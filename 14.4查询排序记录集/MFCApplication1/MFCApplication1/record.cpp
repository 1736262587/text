// record.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "record.h"
#include "afxdialogex.h"


// record 对话框

IMPLEMENT_DYNAMIC(record, CDialogEx)

record::record(CWnd* pParent /*=NULL*/)
	: CDialogEx(record::IDD, pParent)
	, r(_T(""))
{

}

record::~record()
{
}

void record::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, r);
}


BEGIN_MESSAGE_MAP(record, CDialogEx)
END_MESSAGE_MAP()


// record 消息处理程序
