
// DB2018View.h : CDB2018View 类的接口
//

#pragma once

class CDB2018Set;

class CDB2018View : public CRecordView
{
protected: // 仅从序列化创建
	CDB2018View();
	DECLARE_DYNCREATE(CDB2018View)

public:
	enum{ IDD = IDD_DB2018_FORM };
	CDB2018Set* m_pSet;

// 特性
public:
	CDB2018Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CDB2018View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString number;
	CString age;
	CString phone;
};

#ifndef _DEBUG  // DB2018View.cpp 中的调试版本
inline CDB2018Doc* CDB2018View::GetDocument() const
   { return reinterpret_cast<CDB2018Doc*>(m_pDocument); }
#endif

