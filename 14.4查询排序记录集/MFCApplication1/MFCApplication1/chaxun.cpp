// chaxun.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "chaxun.h"
#include "afxdialogex.h"


// chaxun �Ի���

IMPLEMENT_DYNAMIC(chaxun, CDialogEx)

chaxun::chaxun(CWnd* pParent /*=NULL*/)
	: CDialogEx(chaxun::IDD, pParent)
	, check(_T(""))
{

}

chaxun::~chaxun()
{
}

void chaxun::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, check);
}


BEGIN_MESSAGE_MAP(chaxun, CDialogEx)
END_MESSAGE_MAP()


// chaxun ��Ϣ�������
