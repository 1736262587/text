#pragma once


// Update_DLG 对话框

class Update_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(Update_DLG)

public:
	Update_DLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Update_DLG();
	void draw_pic1(CString file);
// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
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
	afx_msg void OnBnClickedButton1();
	
	CString path;
	CString s;
	int f = 0;
	CString file;
	afx_msg void OnPaint();
};
