#pragma once


// fangda �Ի���

class fangda : public CDialogEx
{
	DECLARE_DYNAMIC(fangda)

public:
	fangda(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~fangda();
	CString pathname;
// �Ի�������
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
