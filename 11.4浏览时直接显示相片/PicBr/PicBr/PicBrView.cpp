
// PicBrView.cpp : CPicBrView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_FIRST, &CPicBrView::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CPicBrView::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CPicBrView::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CPicBrView::OnRecordLast)
END_MESSAGE_MAP()

// CPicBrView 构造/析构

CPicBrView::CPicBrView()
	: CRecordView(CPicBrView::IDD)
	, pname(_T(""))
{
	m_pSet = NULL;
	// TODO:  在此处添加构造代码
	path = _T("D:\\VC++实验\\第十二次实验\\图片\\");

}

CPicBrView::~CPicBrView()
{
}

void CPicBrView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CPicBrView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CPicBrView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_PicBrSet;
	CRecordView::OnInitialUpdate();

}


// CPicBrView 打印

BOOL CPicBrView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPicBrView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CPicBrView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CPicBrView 诊断

#ifdef _DEBUG
void CPicBrView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CPicBrView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CPicBrDoc* CPicBrView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPicBrDoc)));
	return (CPicBrDoc*)m_pDocument;
}
#endif //_DEBUG


// CPicBrView 数据库支持
CRecordset* CPicBrView::OnGetRecordset()
{
	return m_pSet;
}



// CPicBrView 消息处理程序


void CPicBrView::OnRecordFirst()
{
	// TODO:  在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename,s;
	GetDlgItemText(IDC_EDIT1,s);
	filename = path + s;
	draw_pic(filename);
}


void CPicBrView::OnRecordPrev()
{
	// TODO:  在此添加命令处理程序代码
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
	// TODO:  在此添加命令处理程序代码
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
	// TODO:  在此添加命令处理程序代码
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