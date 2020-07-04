
// MFCApplication1View.cpp : CMFCApplication1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFCApplication1View 构造/析构

CMFCApplication1View::CMFCApplication1View()
	: CRecordView(CMFCApplication1View::IDD)
	, number(_T(""))
	, name(_T(""))
	, sex(_T(""))
	, salary(_T(""))
	, null(_T(""))
{
	m_pSet = NULL;
	// TODO:  在此处添加构造代码

}

CMFCApplication1View::~CMFCApplication1View()
{
}

void CMFCApplication1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
	
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication1Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication1View 诊断

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 数据库支持
CRecordset* CMFCApplication1View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication1View 消息处理程序


void CMFCApplication1View::On32773()
{
	// TODO:  在此添加命令处理程序代码
	//查询功能
	chaxun dlg;
	int r = dlg.DoModal();
	if (r == IDOK){
		UpdateData(true);
		m_pSet->m_strFilter = dlg.check;//把where字句的赋值传给数据库成员m_strFilter
		m_pSet->Requery();//把满足查询条件的记录提取出来放入记录集
		UpdateData(false);
	}
	
}


void CMFCApplication1View::On32774()
{
	// TODO:  在此添加命令处理程序代码
	//排序功能
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
	// TODO:  在此添加命令处理程序代码
	//记录集功能
	record dlg;
	CString str = _T("ID   学号   姓名      性别           年薪     空子段 \r\n"), s;
	int t = m_pSet->GetODBCFieldCount();
	int f = m_pSet->m_ID; //记录指针弹出窗口前的位置ID
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
	while (m_pSet->m_ID != f)  //退出窗口时指针指回弹出窗口前的位置
	{
		m_pSet->MoveNext();
	}
	dlg.r = str;
	dlg.DoModal();
	UpdateData(false);

}



