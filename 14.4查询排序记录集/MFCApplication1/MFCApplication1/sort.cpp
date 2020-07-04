// sort.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "sort.h"
#include "afxdialogex.h"


// sort 对话框

IMPLEMENT_DYNAMIC(sort, CDialogEx)

sort::sort(CWnd* pParent /*=NULL*/)
	: CDialogEx(sort::IDD, pParent)
	, s(_T(""))
{

}

sort::~sort()
{
}

void sort::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
}


BEGIN_MESSAGE_MAP(sort, CDialogEx)
END_MESSAGE_MAP()


// sort 消息处理程序
