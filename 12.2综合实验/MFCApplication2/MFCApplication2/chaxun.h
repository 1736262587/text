#pragma once


// chaxun 对话框

class chaxun : public CDialogEx
{
	DECLARE_DYNAMIC(chaxun)

public:
	chaxun(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~chaxun();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString s;
};
