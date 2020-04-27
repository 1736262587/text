// Dialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "Dialog.h"
#include "afxdialogex.h"


// Dialog �Ի���

IMPLEMENT_DYNAMIC(Dialog, CDialogEx)

Dialog::Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dialog::IDD, pParent)
	, a(0)
	, b(0)
	, c(0)
{

}

Dialog::~Dialog()
{
}

void Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDV_MinMaxDouble(pDX, a, 0, 100);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDV_MinMaxDouble(pDX, b, 1, 100);
	DDX_Text(pDX, IDC_EDIT3, c);
}


BEGIN_MESSAGE_MAP(Dialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Dialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Dialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &Dialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &Dialog::OnBnClickedButton3)
END_MESSAGE_MAP()


// Dialog ��Ϣ�������


void Dialog::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(TRUE);
	c = a + b;
	UpdateData(FALSE);
}


void Dialog::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(TRUE);
	c = a - b;
	UpdateData(FALSE);
}


void Dialog::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(TRUE);
	c = a * b;
	UpdateData(FALSE);
}


void Dialog::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(TRUE);
	c = a / b;
	UpdateData(FALSE);
}
