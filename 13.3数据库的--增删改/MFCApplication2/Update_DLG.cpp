// Update_DLG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "Update_DLG.h"
#include "afxdialogex.h"


// Update_DLG �Ի���

IMPLEMENT_DYNAMIC(Update_DLG, CDialogEx)

Update_DLG::Update_DLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(Update_DLG::IDD, pParent)
	, b(0)
{

}

Update_DLG::~Update_DLG()
{
}

void Update_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, b);
}


BEGIN_MESSAGE_MAP(Update_DLG, CDialogEx)
END_MESSAGE_MAP()


// Update_DLG ��Ϣ�������
