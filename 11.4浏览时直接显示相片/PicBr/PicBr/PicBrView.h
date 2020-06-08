
// PicBrView.h : CPicBrView 类的接口
//

#pragma once

class CPicBrSet;

class CPicBrView : public CRecordView
{
protected: // 仅从序列化创建
	CPicBrView();
	DECLARE_DYNCREATE(CPicBrView)

public:
	enum{ IDD = IDD_PICBR_FORM };
	CPicBrSet* m_pSet;
	CString path;
// 特性
public:
	CPicBrDoc* GetDocument() const;
	void draw_pic(CString file);
// 操作
public:
	

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CPicBrView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString pname;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // PicBrView.cpp 中的调试版本
inline CPicBrDoc* CPicBrView::GetDocument() const
   { return reinterpret_cast<CPicBrDoc*>(m_pDocument); }
#endif

