
// MFCApplication2View.h : CMFCApplication2View ��Ľӿ�
//

#pragma once


class CMFCApplication2View : public CView
{
protected: // �������л�����
	CMFCApplication2View();
	DECLARE_DYNCREATE(CMFCApplication2View)

// ����
public:
	CMFCApplication2Doc* GetDocument() const;

// ����
public:
	CArray<CRect> c, c1;
	CArray<int> R, G, B;
	int N ;
	CPoint p1, p2;
	int f ;
	
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCApplication2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnShowdialog();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32775();
};

#ifndef _DEBUG  // MFCApplication2View.cpp �еĵ��԰汾
inline CMFCApplication2Doc* CMFCApplication2View::GetDocument() const
   { return reinterpret_cast<CMFCApplication2Doc*>(m_pDocument); }
#endif

