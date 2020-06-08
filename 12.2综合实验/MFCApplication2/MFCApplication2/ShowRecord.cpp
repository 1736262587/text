// ShowRecord.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "ShowRecord.h"
#include "afxdialogex.h"


// ShowRecord 对话框

IMPLEMENT_DYNAMIC(ShowRecord, CDialogEx)

ShowRecord::ShowRecord(CWnd* pParent /*=NULL*/)
	: CDialogEx(ShowRecord::IDD, pParent)
	, record(_T(""))
{

}

ShowRecord::~ShowRecord()
{
}

void ShowRecord::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, record);
}


BEGIN_MESSAGE_MAP(ShowRecord, CDialogEx)
END_MESSAGE_MAP()


// ShowRecord 消息处理程序
