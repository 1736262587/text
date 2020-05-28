
// MFCApplication1View.cpp : CMFCApplication1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	ON_COMMAND(ID_SHOWYUAN, &CMFCApplication1View::OnShowyuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication1View 构造/析构

CMFCApplication1View::CMFCApplication1View()
{
	// TODO:  在此处添加构造代码
	flag = true; flag1 = true; set = true;
	red = 0; green = 0; blue = 0;
}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 绘制

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	if (set){
		for (int i = 0; i < 25; i++){
			SetTimer(i, 1000, NULL);
			set = false;
		}
	}
	int width = 5;
	int color = RGB(red, green, blue);
	CPen newPen(PS_SOLID, width, color);
	CPen *oldPen = pDC->SelectObject(&newPen);//画笔
	pDC->Ellipse(cr);
	pDC->SelectObject(&oldPen);//释放画笔资源

}


// CMFCApplication1View 诊断

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 消息处理程序


void CMFCApplication1View::OnShowyuan()
{
	// TODO:  在此添加命令处理程序代码
	
	CClientDC dc(this);
	CMFCApplication1Doc*pDoc = GetDocument();
	flag1 = false;
	if (flag)
	{ 
		flag = false;
		GetClientRect(&cr);
		point.x = (cr.left + cr.right) / 2;
		point.y = (cr.top + cr.bottom) / 2;
		cr.left = point.x - 5;
		cr.right = point.x + 5;
		cr.top = point.y + 5;
		cr.bottom = point.y - 5;
	}
	else{
		cr.left = cr.left - 3;
		cr.right = cr.right + 3;
		cr.top = cr.top + 3;
		cr.bottom = cr.bottom - 3;
		red += 5;
		green += 4;
		blue += 3;
	}
	InvalidateRect(NULL,FALSE);
}


void CMFCApplication1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (flag1 == false){
		CMFCApplication1View::OnShowyuan();
   }
	CView::OnTimer(nIDEvent);
}
