
// MFCApplication2View.cpp : CMFCApplication2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CView)
	ON_COMMAND(ID_DRAWLINE, &CMFCApplication2View::OnDrawline)
	ON_COMMAND(ID_DRAWRECTANGLE, &CMFCApplication2View::OnDrawrectangle)
	ON_COMMAND(ID_DRAWELLIPSE, &CMFCApplication2View::OnDrawellipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApplication2View 构造/析构

CMFCApplication2View::CMFCApplication2View()
{
	// TODO:  在此处添加构造代码
	flag = 0;
}

CMFCApplication2View::~CMFCApplication2View()
{
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication2View 绘制

void CMFCApplication2View::OnDraw(CDC* pDC)
{
	CMFCApplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO:  在此处为本机数据添加绘制代码
	if (flag == 1){
		pDC->MoveTo(point1);
		pDC->LineTo(point2);
	}
	if (flag == 2)
	{
		rect.left = point1.x;
		rect.top = point1.y;
		rect.right = point2.x;
		rect.bottom = point2.y;
		pDC->Rectangle(rect);
	}
	if (flag == 3)
	{
		rect.left = point1.x;
		rect.top = point1.y;
		rect.right = point2.x;
		rect.bottom = point2.y;
		pDC->Ellipse(rect);
	}
}


// CMFCApplication2View 诊断

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View 消息处理程序


void CMFCApplication2View::OnDrawline()
{
	// TODO:  在此添加命令处理程序代码
	CMFCApplication2Doc* pDoc = GetDocument();
	CClientDC dc(this );
    flag = 1;
	
}


void CMFCApplication2View::OnDrawrectangle()
{
	// TODO:  在此添加命令处理程序代码
	CClientDC dc(this);
	flag = 2;
}


void CMFCApplication2View::OnDrawellipse()
{
	// TODO:  在此添加命令处理程序代码
	CClientDC dc(this);
	flag = 3;
}


void CMFCApplication2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	point1 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CMFCApplication2Doc*pDoc = GetDocument();
	
	CClientDC dc(this);
	point2 = point;
	InvalidateRect(NULL,TRUE );
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	
	CView::OnMouseMove(nFlags, point);
}
