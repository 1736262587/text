
// MFCApplication2View.cpp : CMFCApplication2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFCApplication2View ����/����

CMFCApplication2View::CMFCApplication2View()
{
	// TODO:  �ڴ˴���ӹ������
	flag = 0;
}

CMFCApplication2View::~CMFCApplication2View()
{
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication2View ����

void CMFCApplication2View::OnDraw(CDC* pDC)
{
	CMFCApplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
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


// CMFCApplication2View ���

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View ��Ϣ�������


void CMFCApplication2View::OnDrawline()
{
	// TODO:  �ڴ���������������
	CMFCApplication2Doc* pDoc = GetDocument();
	CClientDC dc(this );
    flag = 1;
	
}


void CMFCApplication2View::OnDrawrectangle()
{
	// TODO:  �ڴ���������������
	CClientDC dc(this);
	flag = 2;
}


void CMFCApplication2View::OnDrawellipse()
{
	// TODO:  �ڴ���������������
	CClientDC dc(this);
	flag = 3;
}


void CMFCApplication2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	point1 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication2Doc*pDoc = GetDocument();
	
	CClientDC dc(this);
	point2 = point;
	InvalidateRect(NULL,TRUE );
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	
	CView::OnMouseMove(nFlags, point);
}
