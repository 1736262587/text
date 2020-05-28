
// MFCApplication1View.cpp : CMFCApplication1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	ON_COMMAND(ID_SHOWCIRCLE, &CMFCApplication1View::OnShowcircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication1View ����/����

CMFCApplication1View::CMFCApplication1View()
{
	// TODO:  �ڴ˴���ӹ������
	f1 = 1;
	f2 = 0;
	set = true;
}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View ����

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	if (set){
		for (int i = 0; i < 30; i++)
			SetTimer(i, 1000, NULL);
		    set = false;
	}
	pDC->Ellipse(pDoc->cr);
}


// CMFCApplication1View ���

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View ��Ϣ�������


void CMFCApplication1View::OnShowcircle()
{
	// TODO:  �ڴ���������������
	CMFCApplication1Doc*pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);
	CPoint point;
	CClientDC dc(this);
	f1 = 0;
	if (f2==0){
		f2 = 1;
	    point.x= clientRec.right / 2;
		point.y= clientRec.bottom / 2;
		pDoc->cr.left = point.x - 5;
		pDoc->cr.right = point.x + 5;
		pDoc->cr.top = point.y + 5;
		pDoc->cr.bottom = point.y - 5;	
		
	}
	else {
		pDoc->cr.left -= 5;
		pDoc->cr.right += 5;
		pDoc->cr.top += 5;
		pDoc->cr.bottom -= 5;
	}
	InvalidateRect(NULL, FALSE);
}


void CMFCApplication1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (f1 == 0){
		CMFCApplication1View::OnShowcircle();
	}
	CView::OnTimer(nIDEvent);
}
