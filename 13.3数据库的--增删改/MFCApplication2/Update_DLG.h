#pragma once


// Update_DLG �Ի���

class Update_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(Update_DLG)

public:
	Update_DLG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Update_DLG();

// �Ի�������
	enum { IDD = IDD_Update };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long b;
};
