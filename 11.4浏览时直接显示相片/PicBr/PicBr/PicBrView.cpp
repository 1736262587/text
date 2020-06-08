
// PicBrView.cpp : CPicBrView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "PicBr.h"
#endif

#include "PicBrSet.h"
#include "PicBrDoc.h"
#include "PicBrView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPicBrView

IMPLEMENT_DYNCREATE(CPicBrView, CRecordView)

BEGIN_MESSAGE_MAP(CPicBrView, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_FIRST, &CPicBrView::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CPicBrView::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CPicBrView::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CPicBrView::OnRecordLast)
END_MESSAGE_MAP()

// CPicBrView ����/����

CPicBrView::CPicBrView()
	: CRecordView(CPicBrView::IDD)
	, pname(_T(""))
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������
	path = _T("D:\\VC++ʵ��\\��ʮ����ʵ��\\ͼƬ\\");

}

CPicBrView::~CPicBrView()
{
}

void CPicBrView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CPicBrView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CPicBrView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_PicBrSet;
	CRecordView::OnInitialUpdate();

}


// CPicBrView ��ӡ

BOOL CPicBrView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CPicBrView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CPicBrView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CPicBrView ���

#ifdef _DEBUG
void CPicBrView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CPicBrView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CPicBrDoc* CPicBrView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPicBrDoc)));
	return (CPicBrDoc*)m_pDocument;
}
#endif //_DEBUG


// CPicBrView ���ݿ�֧��
CRecordset* CPicBrView::OnGetRecordset()
{
	return m_pSet;
}



// CPicBrView ��Ϣ�������


void CPicBrView::OnRecordFirst()
{
	// TODO:  �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename,s;
	GetDlgItemText(IDC_EDIT1,s);
	filename = path + s;
	draw_pic(filename);
}


void CPicBrView::OnRecordPrev()
{
	// TODO:  �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw_pic(filename);
}


void CPicBrView::OnRecordNext()
{
	// TODO:  �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw_pic(filename);
}


void CPicBrView::OnRecordLast()
{
	// TODO:  �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw_pic(filename);
}

void CPicBrView::draw_pic(CString file){
	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio){
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{ 
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC,sx,sy,w,h);
	ReleaseDC(pDC);
}