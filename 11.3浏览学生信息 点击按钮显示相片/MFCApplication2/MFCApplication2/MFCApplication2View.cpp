
// MFCApplication2View.cpp : CMFCApplication2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Set.h"
#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"
#include "MyDialog.h"
#include "Dialog1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMFCApplication2View ����/����

CMFCApplication2View::CMFCApplication2View()
	: CRecordView(CMFCApplication2View::IDD)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������

	
}

CMFCApplication2View::~CMFCApplication2View()
{
}

void CMFCApplication2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->m_4);
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication2Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication2View ��ӡ

BOOL CMFCApplication2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCApplication2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCApplication2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFCApplication2View ���

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View ���ݿ�֧��
CRecordset* CMFCApplication2View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication2View ��Ϣ�������


void CMFCApplication2View::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MyDialog dlg;
    CString filename;
	filename = m_pSet->m_5;
	dlg.pathname = filename;
	dlg.DoModal();
	
}

void CMFCApplication2View::draw_pic(CString file){
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
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}