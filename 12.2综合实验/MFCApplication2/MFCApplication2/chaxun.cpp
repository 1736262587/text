// chaxun.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "chaxun.h"
#include "afxdialogex.h"


// chaxun �Ի���

IMPLEMENT_DYNAMIC(chaxun, CDialogEx)

chaxun::chaxun(CWnd* pParent /*=NULL*/)
	: CDialogEx(chaxun::IDD, pParent)
	, s(_T(""))
{

}

chaxun::~chaxun()
{
}

void chaxun::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
}


BEGIN_MESSAGE_MAP(chaxun, CDialogEx)
END_MESSAGE_MAP()


// chaxun ��Ϣ�������
