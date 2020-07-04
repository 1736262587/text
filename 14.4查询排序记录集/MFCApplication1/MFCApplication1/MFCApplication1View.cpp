
// MFCApplication1View.cpp : CMFCApplication1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Set.h"
#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"
#include "chaxun.h"
#include "record.h"
#include "sort.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CRecordView)
	ON_COMMAND(ID_32773, &CMFCApplication1View::On32773)
	ON_COMMAND(ID_32774, &CMFCApplication1View::On32774)
	ON_COMMAND(ID_32775, &CMFCApplication1View::On32775)
END_MESSAGE_MAP()

// CMFCApplication1View ����/����

CMFCApplication1View::CMFCApplication1View()
	: CRecordView(CMFCApplication1View::IDD)
	, number(_T(""))
	, name(_T(""))
	, sex(_T(""))
	, salary(_T(""))
	, null(_T(""))
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������

}

CMFCApplication1View::~CMFCApplication1View()
{
}

void CMFCApplication1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
	
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication1Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication1View ���

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View ���ݿ�֧��
CRecordset* CMFCApplication1View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication1View ��Ϣ�������


void CMFCApplication1View::On32773()
{
	// TODO:  �ڴ���������������
	//��ѯ����
	chaxun dlg;
	int r = dlg.DoModal();
	if (r == IDOK){
		UpdateData(true);
		m_pSet->m_strFilter = dlg.check;//��where�־�ĸ�ֵ�������ݿ��Աm_strFilter
		m_pSet->Requery();//�������ѯ�����ļ�¼��ȡ���������¼��
		UpdateData(false);
	}
	
}


void CMFCApplication1View::On32774()
{
	// TODO:  �ڴ���������������
	//������
	sort dlg;
	int r = dlg.DoModal();
	if (r == IDOK){
		UpdateData(true);
		m_pSet->m_strSort = dlg.s;
		m_pSet->Requery();
		UpdateData(false);
	}
}


void CMFCApplication1View::On32775()
{
	// TODO:  �ڴ���������������
	//��¼������
	record dlg;
	CString str = _T("ID   ѧ��   ����      �Ա�           ��н     ���Ӷ� \r\n"), s;
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
	dlg.r = str;
	dlg.DoModal();
	UpdateData(false);

}



