
// MFCApplication2View.h : CMFCApplication2View 类的接口
//

#pragma once

class CMFCApplication2Set;

class CMFCApplication2View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCApplication2View();
	DECLARE_DYNCREATE(CMFCApplication2View)

public:
	enum{ IDD = IDD_MFCAPPLICATION2_FORM };
	CMFCApplication2Set* m_pSet;

// 特性
public:
	CMFCApplication2Doc* GetDocument() const;
	void draw_pic(CString file);
// 操作
public:
	CString path;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCApplication2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit7();
	CString name;
	CString number;
	CString major;
	CString sex;
	CString birthday;
	CString phone;
	CString address;
	CString photo;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	long ID;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnBnClickedButton8();
};

#ifndef _DEBUG  // MFCApplication2View.cpp 中的调试版本
inline CMFCApplication2Doc* CMFCApplication2View::GetDocument() const
   { return reinterpret_cast<CMFCApplication2Doc*>(m_pDocument); }
#endif

