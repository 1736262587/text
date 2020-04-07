
// MFCApplication3View.cpp : CMFCApplication3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication3.h"
#endif

#include "MFCApplication3Doc.h"
#include "MFCApplication3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3View

IMPLEMENT_DYNCREATE(CMFCApplication3View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication3View, CView)
	ON_WM_KEYDOWN()
//	ON_WM_CHAR()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication3View 构造/析构

CMFCApplication3View::CMFCApplication3View()
{
	// TODO:  在此处添加构造代码

}

CMFCApplication3View::~CMFCApplication3View()
{
}

BOOL CMFCApplication3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication3View 绘制

void CMFCApplication3View::OnDraw(CDC* pDC)
{
	CMFCApplication3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_crlRect);
}


// CMFCApplication3View 诊断

#ifdef _DEBUG
void CMFCApplication3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication3Doc* CMFCApplication3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication3Doc)));
	return (CMFCApplication3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication3View 消息处理程序


void CMFCApplication3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CMFCApplication3Doc*pDoc = GetDocument();
	CRect ClientRec;//构造矩形
	GetClientRect(&ClientRec);//获取客户区大小
	switch (nChar)
	{
	case VK_HOME:
		if ((pDoc->m_crlRect.top > 0) && (pDoc->m_crlRect.left > 0))
		{
			pDoc->m_crlRect.left -= 5;
			pDoc->m_crlRect.top -= 5;

		}
		break;
	case VK_END:
		if ((pDoc->m_crlRect.top > 0) && (pDoc->m_crlRect.left > 0))
		{
			pDoc->m_crlRect.left += 5;
			pDoc->m_crlRect.top += 5;

		}
		break;
	case VK_LEFT:
		if (pDoc->m_crlRect.left > 0)
		{
			pDoc->m_crlRect.left -= 5;
			pDoc->m_crlRect.right -= 5;
		}
		break;
	
	case VK_RIGHT:
		if (pDoc->m_crlRect.right <=(ClientRec.right -ClientRec.left))
		{
			pDoc->m_crlRect.left += 5;
			pDoc->m_crlRect.right += 5;
		}
		break;

	case VK_UP:
		if (pDoc->m_crlRect.top >0)
		{
			pDoc->m_crlRect.top -= 5;
			pDoc->m_crlRect.bottom -= 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->m_crlRect.bottom <= (ClientRec.bottom - ClientRec.top))
		{
			pDoc->m_crlRect.top += 5;
			pDoc->m_crlRect.bottom += 5;
		}
		break;
}
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


//void CMFCApplication3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO:  在此添加消息处理程序代码和/或调用默认值
//	CMFCApplication3Doc*pDoc = GetDocument();
//	CRect ClientRec;
//	GetClientRect(&ClientRec);
//	switch (nChar)
//	{
//	case VK_HOME:
//		if ((pDoc->m_crlRect.top > 0) && (pDoc->m_crlRect.left > 0))
//		{
//			pDoc->m_crlRect.left -= 5;
//			pDoc->m_crlRect.top -= 5;
//	
//		}
//		break;
//	case VK_END :
//		if ((pDoc->m_crlRect.top > 0) && (pDoc->m_crlRect.left > 0))
//		{
//			pDoc->m_crlRect.left += 5;
//			pDoc->m_crlRect.top += 5;
//
//		}
//		break;
//	case VK_LEFT:
//		if (pDoc->m_crlRect.left > 0)
//		{
//			pDoc->m_crlRect.left -= 5;
//			pDoc->m_crlRect.right -= 5;
//		}
//		break;
//	case VK_RIGHT:
//		if (pDoc->m_crlRect.right<= (ClientRec.right -ClientRec.left ))
//		{
//			pDoc->m_crlRect.left += 5;
//			pDoc->m_crlRect.right += 5;
//		}
//		break;
//	case VK_UP:
//		if (pDoc->m_crlRect.top > 0)
//		{
//			pDoc->m_crlRect.top -= 5;
//			pDoc->m_crlRect.bottom -= 5;
//		}
//		break;
//	case VK_DOWN:
//		if (pDoc->m_crlRect.bottom <= (ClientRec.bottom -ClientRec.top ))
//		{
//			pDoc->m_crlRect.top += 5;
//			pDoc->m_crlRect.bottom += 5;
//		}
//		break;
//	}
//	CView::OnChar(nChar, nRepCnt, nFlags);
//}


void CMFCApplication3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	CMFCApplication3Doc*pDoc = GetDocument();
	pDoc->m_crlRect.left = 30;
	pDoc->m_crlRect.right = 80;
	pDoc->m_crlRect.top = 30;
	pDoc->m_crlRect.bottom = 80;
	InvalidateRect(NULL,TRUE);
}
