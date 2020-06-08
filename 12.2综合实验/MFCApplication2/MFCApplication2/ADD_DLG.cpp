// ADD_DLG.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "ADD_DLG.h"
#include "afxdialogex.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

// ADD_DLG 对话框

IMPLEMENT_DYNAMIC(ADD_DLG, CDialogEx)

ADD_DLG::ADD_DLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(ADD_DLG::IDD, pParent)
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

ADD_DLG::~ADD_DLG()
{
}

void ADD_DLG::DoDataExchange(CDataExchange* pDX)
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


BEGIN_MESSAGE_MAP(ADD_DLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ADD_DLG::OnBnClickedButton1)
	
	ON_BN_CLICKED(IDC_BUTTON1, &ADD_DLG::OnBnClickedButton1)
END_MESSAGE_MAP()


// ADD_DLG 消息处理程序
void string_replace(std::string &strBig, const std::string &strsrc, const std::string &strdst)
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

std::string GetPathOrURLShortName(std::string strFullName)
{
	if (strFullName.empty())
	{
		return "";
	}

	string_replace(strFullName, "/", "\\");

	std::string::size_type iPos = strFullName.find_last_of('\\') + 1;

	return strFullName.substr(iPos, strFullName.length() - iPos);
}



void ADD_DLG::draw_pic(CString file){
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



void ADD_DLG::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog cfd(true);
	int n = cfd.DoModal();
	if (n == IDOK)
	{
		CString filename1 = cfd.GetPathName();
		draw_pic(filename1);
		CDC*pDC = GetDC();
		string t = CT2A(filename1.GetString());
		string s = GetPathOrURLShortName(t);
		CopyFile(filename1, path + CA2T(s.c_str()), false);
		GetDlgItem(IDC_EDIT8)->SetWindowTextW(CA2T(s.c_str()));
		ReleaseDC(pDC);
	}
}