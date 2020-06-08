// fangda.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "fangda.h"
#include "afxdialogex.h"


// fangda �Ի���

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


// fangda ��Ϣ�������


void fangda::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
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
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

}
