
// PicBr.h : PicBr Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CPicBrApp:
// �йش����ʵ�֣������ PicBr.cpp
//

class CPicBrApp : public CWinAppEx
{
public:
	CPicBrApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPicBrApp theApp;
