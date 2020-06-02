
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
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SHOWDIALOG, &CMFCApplication2View::OnShowdialog)
	ON_COMMAND(ID_32773, &CMFCApplication2View::On32773)
	ON_COMMAND(ID_32774, &CMFCApplication2View::On32774)
	ON_COMMAND(ID_32775, &CMFCApplication2View::On32775)
END_MESSAGE_MAP()

// CMFCApplication2View 构造/析构

CMFCApplication2View::CMFCApplication2View()
{
	// TODO:  在此处添加构造代码
	 f = 1;
	N = 50;
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
	for (int i = 0; i < c.GetSize(); i++)
	{
		pDC->Ellipse(c.GetAt(i));
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


void CMFCApplication2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	p1 = p2 = point;
	int r = 0, g = 255, b = 0;
	if (nFlags&&f == 0)
	{
		int mixi = 0, f1 = 0;
		for (int i = 0; i < c.GetSize(); i++)
		{
			c.GetAt(i);

			if ((((point.x - (c.GetAt(i).left + c.GetAt(i).right) / 2)*(point.x - (c.GetAt(i).left + c.GetAt(i).right) / 2) +
				(point.y - (c.GetAt(i).top + c.GetAt(i).bottom) / 2)*(point.y - (c.GetAt(i).top + c.GetAt(i).bottom) / 2)) <=
				((point.x - (c.GetAt(mixi).left + c.GetAt(mixi).right) / 2)*(point.x - (c.GetAt(mixi).left + c.GetAt(mixi).right) / 2) +
				(point.y - (c.GetAt(mixi).top + c.GetAt(mixi).bottom) / 2)*(point.y - (c.GetAt(mixi).top + c.GetAt(mixi).bottom) / 2)))
				&& ((point.x >= c.GetAt(i).left&&point.x <= c.GetAt(i).right&&point.y >= c.GetAt(i).top&&point.y <= c.GetAt(i).bottom) ||
				(point.x <= c.GetAt(i).left&&point.x >= c.GetAt(i).right&&point.y <= c.GetAt(i).top&&point.y >= c.GetAt(i).bottom) ||
				(point.x >= c.GetAt(i).left&&point.x <= c.GetAt(i).right&&point.y <= c.GetAt(i).top&&point.y >= c.GetAt(i).bottom) ||
				(point.x <= c.GetAt(i).left&&point.x >= c.GetAt(i).right&&point.y >= c.GetAt(i).top&&point.y <= c.GetAt(i).bottom)
				))
			{
				mixi = i;
				f1 = 1;
				c1.Add(c.GetAt(mixi));
			}
		}
		if (f1) {
			CDC * dc = GetDC();
			CPen * pOldPen = NULL;
			CPen pen;
			pen.CreatePen(PS_DASH, 1, RGB(0, 255, 0));//虚线
			pOldPen = dc->SelectObject(&pen);

			CBrush * pOldBrush = NULL;
			CBrush * pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//背景透明效果
			pOldBrush = dc->SelectObject(pBrush);

			dc->Rectangle(c.GetAt(mixi));
			dc->SelectObject(pOldPen);
			pen.DeleteObject();
		}
	}
	if (nFlags&&f == 3)
	{

		int mixi = 0, f1 = 0;

		for (int i = 0; i < c.GetSize(); i++)
		{
			c.GetAt(i);

			if ((((point.x - (c.GetAt(i).left + c.GetAt(i).right) / 2)*(point.x - (c.GetAt(i).left + c.GetAt(i).right) / 2) +
				(point.y - (c.GetAt(i).top + c.GetAt(i).bottom) / 2)*(point.y - (c.GetAt(i).top + c.GetAt(i).bottom) / 2)) <=
				((point.x - (c.GetAt(mixi).left + c.GetAt(mixi).right) / 2)*(point.x - (c.GetAt(mixi).left + c.GetAt(mixi).right) / 2) +
				(point.y - (c.GetAt(mixi).top + c.GetAt(mixi).bottom) / 2)*(point.y - (c.GetAt(mixi).top + c.GetAt(mixi).bottom) / 2)))
				&& ((point.x >= c.GetAt(i).left&&point.x <= c.GetAt(i).right&&point.y >= c.GetAt(i).top&&point.y <= c.GetAt(i).bottom) ||
				(point.x <= c.GetAt(i).left&&point.x >= c.GetAt(i).right&&point.y <= c.GetAt(i).top&&point.y >= c.GetAt(i).bottom) ||
				(point.x >= c.GetAt(i).left&&point.x <= c.GetAt(i).right&&point.y <= c.GetAt(i).top&&point.y >= c.GetAt(i).bottom) ||
				(point.x <= c.GetAt(i).left&&point.x >= c.GetAt(i).right&&point.y >= c.GetAt(i).top&&point.y <= c.GetAt(i).bottom)
				))
			{
				mixi = i;
				f1 = 1;
			}

		}

		if (f1) {
			CDC * pDC = GetDC();
			CBrush Brush(RGB(r, g, b));
			CBrush *oldbrush;
			oldbrush = pDC->SelectObject(&Brush);
			pDC->Ellipse(c.GetAt(mixi));
			pDC->SelectObject(&oldbrush);
			ReleaseDC(pDC);
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CRect cr;
	cr.left = p1.x; cr.top = p1.y; cr.right = p2.x, cr.bottom = p2.y;
	dc.Ellipse(&cr);
	c.Add(cr);
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CRect cr;
	if (MK_LBUTTON&&nFlags&&f == 1)
	{
		p2 = point;
		cr.left = p1.x; cr.top = p1.y; cr.right = p2.x, cr.bottom = p2.y;
		Invalidate();
		GetDC()->Ellipse(&cr);
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication2View::OnShowdialog()
{
	// TODO:  在此添加命令处理程序代码
	MyDialog dlg;
	int t = dlg.DoModal();
	if (t == IDOK){
		double X = dlg.x;
		double Y = dlg.y;
		double A = dlg.a;
		double B = dlg.b;
		int Red = dlg.r;
		int Green = dlg.g;
		int Blue = dlg.blue;
		CDC *pDC = GetDC();
		CBrush newBrush(RGB(Red, Green, Blue));
		CBrush *oldBrush;
		oldBrush=pDC->SelectObject(&newBrush);
		CRect cr(X - A, Y - B, X + A, Y + B);
		pDC->Ellipse(cr);
		pDC->SelectObject(&oldBrush);
		ReleaseDC(pDC);
	}
}


void CMFCApplication2View::On32773()
{
	// TODO:  在此添加命令处理程序代码
	f = 0;
}


void CMFCApplication2View::On32774()
{
	// TODO:  在此添加命令处理程序代码
	f = 3;
}


void CMFCApplication2View::On32775()
{
	// TODO:  在此添加命令处理程序代码
	f = 1;
}
