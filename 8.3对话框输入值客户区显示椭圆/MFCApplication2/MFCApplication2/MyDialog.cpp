// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialog::IDD, pParent)
	, x(0)
	, y(0)
	, a(0)
	, b(0)
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, a);
	DDV_MinMaxDouble(pDX, a, 1, 500);
	DDX_Text(pDX, IDC_EDIT4, b);
	DDV_MinMaxDouble(pDX, b, 1, 500);
	DDV_MinMaxDouble(pDX, x, 1, 500);
	DDV_MinMaxDouble(pDX, y, 1, 500);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
END_MESSAGE_MAP()


// MyDialog 消息处理程序
