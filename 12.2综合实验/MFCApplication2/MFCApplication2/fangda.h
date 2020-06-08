#pragma once


// fangda 对话框

class fangda : public CDialogEx
{
	DECLARE_DYNAMIC(fangda)

public:
	fangda(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~fangda();
	CString pathname;
// 对话框数据
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
