
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
#include "Update_DLG.h"
#include "ADD_DLG.h"
#include "chaxun.h"
#include "sort.h"
#include "ShowRecord.h"
#include "fangda.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT7, &CMFCApplication2View::OnEnChangeEdit7)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2View::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication2View::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication2View::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication2View::OnBnClickedButton7)
	ON_COMMAND(ID_RECORD_FIRST, &CMFCApplication2View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCApplication2View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCApplication2View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCApplication2View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication2View::OnBnClickedButton8)
END_MESSAGE_MAP()

// CMFCApplication2View ����/����

CMFCApplication2View::CMFCApplication2View()
	: CRecordView(CMFCApplication2View::IDD)
	, name(_T(""))
	, number(_T(""))
	, major(_T(""))
	, sex(_T(""))
	, birthday(_T(""))
	, phone(_T(""))
	, address(_T(""))
	, photo(_T(""))
	, ID(0)
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������
	path = _T("D:\\VC++ʵ��\\��ʮ����ʵ��\\ͼƬ\\");
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
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column7);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column8);
	DDX_Text(pDX, IDC_EDIT9, m_pSet->m_ID);
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


void CMFCApplication2View::OnEnChangeEdit7()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFCApplication2View::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	Update_DLG dlg;
	int f;
	dlg.photo = path + m_pSet->column8;
	if (m_pSet->column8 == "")
	{
		dlg.s = ""; f = 0;
	}
	else { dlg.s = path + m_pSet->column8; f = 1; }
	dlg.path = path;
	dlg.name = m_pSet->column1;
	dlg.number = m_pSet->column2;
	dlg.major = m_pSet->column3;
	dlg.sex = m_pSet->column4;
	dlg.birthday = m_pSet->column5;
	dlg.phone = m_pSet->column6;
	dlg.address = m_pSet->column7;
	dlg.photo = m_pSet->column8;
	int n = dlg.DoModal();
	if (n == IDOK)
	{
		/*if (f == 0) { f = dlg.f; }
		if (dlg.photo == ""&&f == 1 && dlg.name == "")
		{
			prompt pro;
			int t = pro.DoModal();
			return;
		}*/
		m_pSet->Edit();
		m_pSet->column1 = dlg.name;
		m_pSet->column2 = dlg.number;
		m_pSet->column3 = dlg.major;
		m_pSet->column4 = dlg.sex;
		m_pSet->column5 = dlg.birthday;
		m_pSet->column6 = dlg.phone;
		m_pSet->column7 = dlg.address;
		if (f == 1) {
			CString file = path + dlg.photo;
			rename(CT2A(dlg.s.GetString()), CT2A(file.GetString()));
		}
		m_pSet->column8 = dlg.photo;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CMFCApplication2View::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ADD_DLG dlg;
	dlg.path = path;
	int n = dlg.DoModal();
	if (n == IDOK)
	{
		/*if (dlg.name == "")
		{
			prompt pro;
			int t = pro.DoModal();
			return;
		}*/
		m_pSet->AddNew();
		m_pSet->column1 = dlg.name;
		m_pSet->column2 = dlg.number;
		m_pSet->column3 = dlg.major;
		m_pSet->column4 = dlg.sex;
		m_pSet->column5 = dlg.birthday;
		m_pSet->column6 = dlg.phone;
		m_pSet->column7 = dlg.address;
		m_pSet->column8 = dlg.photo;
		m_pSet->Update();
		m_pSet->MoveLast();
		UpdateData(false);
		Invalidate();
	}
}


void CMFCApplication2View::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void CMFCApplication2View::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//��ѯ����
	chaxun q;
	int n = q.DoModal();
	if (n == IDOK) {
		UpdateData(true);
		m_pSet->m_strFilter = q.s;
		m_pSet->Requery();
		UpdateData(false);
	}
	Invalidate();
}


void CMFCApplication2View::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	sort dlg;
	int r = dlg.DoModal();
	if (r == IDOK){
		UpdateData(true);
		m_pSet->m_strSort = dlg.s;
		m_pSet->Requery();
		UpdateData(false);
	}
}


void CMFCApplication2View::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ShowRecord dlg;
	CString str = _T("ID   ����       ѧ��       רҵ         �Ա�   ��������  �ֻ�����     ��ͥסַ       ��Ƭ�ļ��� \r\n"), s;
	int t = m_pSet->GetODBCFieldCount();
	int f = m_pSet->m_ID; //��¼ָ�뵯������ǰ��λ��ID
	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())
	{
		for (int i = 0; i < t; i++) {
			m_pSet->GetFieldValue((short)i, s);
			str = str + "  " + s;
		}
		str = str + _T("\r\n");
		m_pSet->MoveNext();
	}
	m_pSet->MoveFirst();
	while (m_pSet->m_ID != f)  //�˳�����ʱָ��ָ�ص�������ǰ��λ��
	{
		m_pSet->MoveNext();
	}
	dlg.record = str;
	dlg.DoModal();
	UpdateData(false);

}


void CMFCApplication2View::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_pSet->m_strFilter = _T("");
	m_pSet->m_strSort = _T("");
	m_pSet->Requery();
	UpdateData(false);

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

void CMFCApplication2View::OnRecordFirst()
{
	// TODO:  �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFCApplication2View::OnRecordPrev()
{
	// TODO:  �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFCApplication2View::OnRecordNext()
{
	// TODO:  �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFCApplication2View::OnRecordLast()
{
	// TODO:  �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFCApplication2View::OnDraw(CDC* pDC)
{
	// TODO:  �ڴ����ר�ô����/����û���
	CString filename, s;
	GetDlgItemText(IDC_EDIT8, s);
	filename = path + s;
	draw_pic(filename);
}


void CMFCApplication2View::OnBnClickedButton8()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	fangda dlg;
	CString filename, s;
	GetDlgItemText(IDC_EDIT8, s);
	filename = path + s;
	dlg.pathname = filename;
    dlg.DoModal();
}
