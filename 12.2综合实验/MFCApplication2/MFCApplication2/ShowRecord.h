#pragma once


// ShowRecord 对话框

class ShowRecord : public CDialogEx
{
	DECLARE_DYNAMIC(ShowRecord)

public:
	ShowRecord(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ShowRecord();

// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString record;
};
