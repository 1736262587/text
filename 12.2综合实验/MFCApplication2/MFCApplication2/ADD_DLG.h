#pragma once


// ADD_DLG 对话框

class ADD_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(ADD_DLG)

public:
	ADD_DLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ADD_DLG();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void draw_pic(CString file);
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString number;
	CString major;
	CString sex;
	CString birthday;
	CString phone;
	CString address;
	CString photo;
	
	CString path;
	afx_msg void OnBnClickedButton1();
};
