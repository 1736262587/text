#pragma once


// ShowRecord �Ի���

class ShowRecord : public CDialogEx
{
	DECLARE_DYNAMIC(ShowRecord)

public:
	ShowRecord(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ShowRecord();

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString record;
};
