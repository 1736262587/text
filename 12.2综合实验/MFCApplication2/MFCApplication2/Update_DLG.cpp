// Update_DLG.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "Update_DLG.h"
#include "afxdialogex.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

// Update_DLG 对话框

IMPLEMENT_DYNAMIC(Update_DLG, CDialogEx)

Update_DLG::Update_DLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(Update_DLG::IDD, pParent)
	, name(_T(""))
	, number(_T(""))
	, major(_T(""))
	, sex(_T(""))
	, birthday(_T(""))
	, phone(_T(""))
	, address(_T(""))
	, photo(_T(""))
{

}

Update_DLG::~Update_DLG()
{
}

void Update_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, number);
	DDX_Text(pDX, IDC_EDIT3, major);
	DDX_Text(pDX, IDC_EDIT4, sex);
	DDX_Text(pDX, IDC_EDIT5, birthday);
	DDX_Text(pDX, IDC_EDIT7, phone);
	DDX_Text(pDX, IDC_EDIT6, address);
	DDX_Text(pDX, IDC_EDIT8, photo);
}


BEGIN_MESSAGE_MAP(Update_DLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Update_DLG::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Update_DLG 消息处理程序
void string_replace1(std::string &strBig, const std::string &strsrc, const std::string &strdst)
{
	std::string::size_type pos = 0;
	std::string::size_type srclen = strsrc.size();
	std::string::size_type dstlen = strdst.size();

	while ((pos = strBig.find(strsrc, pos)) != std::string::npos)
	{
		strBig.replace(pos, srclen, strdst);
		pos += dstlen;
	}
}

std::string GetPathOrURLShortName1(std::string strFullName)
{
	if (strFullName.empty())
	{
		return "";
	}

	string_replace1(strFullName, "/", "\\");

	std::string::size_type iPos = strFullName.find_last_of('\\') + 1;

	return strFullName.substr(iPos, strFullName.length() - iPos);
}

void Update_DLG::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog cfd(true);
	int n = cfd.DoModal();
	if (n == IDOK)
	{
		CString filename1 = cfd.GetPathName();
		draw_pic1(filename1);
		f = 1;
		string t = CT2A(filename1.GetString());
		string s = GetPathOrURLShortName1(t);
		CDC*pDC = GetDC();
		//DeleteFile(file);
		CopyFile(filename1, path + CA2T(s.c_str()), false);
		GetDlgItem(IDC_EDIT8)->SetWindowTextW(CA2T(s.c_str()));
		ReleaseDC(pDC);
	}
}
void Update_DLG::draw_pic1(CString file){
	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio){
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}



void Update_DLG::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	if (s != "") {
		draw_pic1(s);

	}
}
