#pragma once


// Update_DLG 对话框

class Update_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(Update_DLG)

public:
	Update_DLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Update_DLG();

// 对话框数据
	enum { IDD = IDD_Update };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long b;
};
