
// DB2018View.cpp : CDB2018View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DB2018.h"
#endif

#include "DB2018Set.h"
#include "DB2018Doc.h"
#include "DB2018View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB2018View

IMPLEMENT_DYNCREATE(CDB2018View, CRecordView)

BEGIN_MESSAGE_MAP(CDB2018View, CRecordView)
END_MESSAGE_MAP()

// CDB2018View ����/����

CDB2018View::CDB2018View()
	: CRecordView(CDB2018View::IDD)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������

}

CDB2018View::~CDB2018View()
{
}

void CDB2018View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
}

BOOL CDB2018View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDB2018View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB2018Set;
	CRecordView::OnInitialUpdate();

}


// CDB2018View ���

#ifdef _DEBUG
void CDB2018View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB2018View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB2018Doc* CDB2018View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB2018Doc)));
	return (CDB2018Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB2018View ���ݿ�֧��
CRecordset* CDB2018View::OnGetRecordset()
{
	return m_pSet;
}



// CDB2018View ��Ϣ�������
