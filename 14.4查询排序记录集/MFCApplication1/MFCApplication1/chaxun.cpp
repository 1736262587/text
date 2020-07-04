// chaxun.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "chaxun.h"
#include "afxdialogex.h"


// chaxun 对话框

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


// chaxun 消息处理程序
