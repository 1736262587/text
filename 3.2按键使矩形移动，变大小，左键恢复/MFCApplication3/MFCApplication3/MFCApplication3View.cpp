
// MFCApplication3View.cpp : CMFCApplication3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFCApplication3View ����/����

CMFCApplication3View::CMFCApplication3View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFCApplication3View::~CMFCApplication3View()
{
}

BOOL CMFCApplication3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication3View ����

void CMFCApplication3View::OnDraw(CDC* pDC)
{
	CMFCApplication3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->m_crlRect);
}


// CMFCApplication3View ���

#ifdef _DEBUG
void CMFCApplication3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication3Doc* CMFCApplication3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication3Doc)));
	return (CMFCApplication3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication3View ��Ϣ�������


void CMFCApplication3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication3Doc*pDoc = GetDocument();
	CRect ClientRec;//�������
	GetClientRect(&ClientRec);//��ȡ�ͻ�����С
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
//	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDown(nFlags, point);
	CMFCApplication3Doc*pDoc = GetDocument();
	pDoc->m_crlRect.left = 30;
	pDoc->m_crlRect.right = 80;
	pDoc->m_crlRect.top = 30;
	pDoc->m_crlRect.bottom = 80;
	InvalidateRect(NULL,TRUE);
}
