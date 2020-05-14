
// DB2018View.h : CDB2018View ��Ľӿ�
//

#pragma once

class CDB2018Set;

class CDB2018View : public CRecordView
{
protected: // �������л�����
	CDB2018View();
	DECLARE_DYNCREATE(CDB2018View)

public:
	enum{ IDD = IDD_DB2018_FORM };
	CDB2018Set* m_pSet;

// ����
public:
	CDB2018Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CDB2018View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString number;
	CString age;
	CString phone;
};

#ifndef _DEBUG  // DB2018View.cpp �еĵ��԰汾
inline CDB2018Doc* CDB2018View::GetDocument() const
   { return reinterpret_cast<CDB2018Doc*>(m_pDocument); }
#endif

