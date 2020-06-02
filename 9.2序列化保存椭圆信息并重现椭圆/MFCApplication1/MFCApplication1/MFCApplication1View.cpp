
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
#include<fstream>
#include<iostream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_FILE_OPEN, &CMFCApplication1View::OnFileOpen)
END_MESSAGE_MAP()

// CMFCApplication1View ����/����

CMFCApplication1View::CMFCApplication1View()
{
	// TODO:  �ڴ˴���ӹ������

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
	for (int i = 0; i < cr.GetSize(); i++)
	{
		pDC->Ellipse(cr[i]);
	}
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


void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	p1 = p2 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect c;
	c.left = p1.x; c.top = p1.y; c.right = point.x; c.bottom = point.y;
	cr.Add(c);
	CClientDC dc(this);
	Invalidate();
	dc.Ellipse(c);
	ofstream ofs;
	ofs.open(_T("D:\\��Բ.txt"), ofstream::out);
	for (int i = 0; i<cr.GetSize(); i++)
	{
		ofs << cr[i].top << ' ';
		ofs << cr[i].bottom << ' ';
		ofs << cr[i].left << ' ';
		ofs << cr[i].right << endl;
	}
	ofs.close();
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (MK_LBUTTON&&nFlags) {
		CRect c;
		c.left = p1.x; c.top = p1.y; c.right = point.x; c.bottom = point.y;
		CClientDC dc(this);
		this->Invalidate();
		dc.Ellipse(c);

	}
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication1View::OnFileOpen()
{
	// TODO:  �ڴ���������������
	CFileDialog file(true);
	if (file.DoModal() == IDOK) {
		CString filename = file.GetPathName();
		ifstream ifs;
		ifs.open(filename);
		int i = 0;
		while (!ifs.eof())
		{
			CRect c;
			ifs >> c.top;
			ifs >> c.bottom;
			ifs >> c.left;
			ifs >> c.right;
			cr.Add(c);
			i++;
		}
		ifs.close();
		Invalidate();
	}
}
