// fangda.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "fangda.h"
#include "afxdialogex.h"


// fangda 对话框

IMPLEMENT_DYNAMIC(fangda, CDialogEx)

fangda::fangda(CWnd* pParent /*=NULL*/)
	: CDialogEx(fangda::IDD, pParent)
{

}

fangda::~fangda()
{
}

void fangda::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(fangda, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// fangda 消息处理程序


void fangda::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	CImage img;
	img.Load(pathname);
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
	// 不为绘图消息调用 CDialogEx::OnPaint()

}
