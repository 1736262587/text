#pragma once


// record �Ի���

class record : public CDialogEx
{
	DECLARE_DYNAMIC(record)

public:
	record(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~record();
	
// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	
public:
	CString r;
};
