
// DB2018View.cpp : CDB2018View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CDB2018View 构造/析构

CDB2018View::CDB2018View()
	: CRecordView(CDB2018View::IDD)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO:  在此处添加构造代码

}

CDB2018View::~CDB2018View()
{
}

void CDB2018View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
}

BOOL CDB2018View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDB2018View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB2018Set;
	CRecordView::OnInitialUpdate();

}


// CDB2018View 诊断

#ifdef _DEBUG
void CDB2018View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB2018View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB2018Doc* CDB2018View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB2018Doc)));
	return (CDB2018Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB2018View 数据库支持
CRecordset* CDB2018View::OnGetRecordset()
{
	return m_pSet;
}



// CDB2018View 消息处理程序
