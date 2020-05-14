
// PicBrView.h : CPicBrView ��Ľӿ�
//

#pragma once

class CPicBrSet;

class CPicBrView : public CRecordView
{
protected: // �������л�����
	CPicBrView();
	DECLARE_DYNCREATE(CPicBrView)

public:
	enum{ IDD = IDD_PICBR_FORM };
	CPicBrSet* m_pSet;
	CString path;
// ����
public:
	CPicBrDoc* GetDocument() const;
	void draw_pic(CString file);
// ����
public:
	

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CPicBrView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString pname;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // PicBrView.cpp �еĵ��԰汾
inline CPicBrDoc* CPicBrView::GetDocument() const
   { return reinterpret_cast<CPicBrDoc*>(m_pDocument); }
#endif

