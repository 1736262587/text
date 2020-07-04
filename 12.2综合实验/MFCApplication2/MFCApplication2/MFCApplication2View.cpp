
// MFCApplication2View.cpp : CMFCApplication2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Set.h"
#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"
#include "Update_DLG.h"
#include "ADD_DLG.h"
#include "chaxun.h"
#include "sort.h"
#include "ShowRecord.h"
#include "fangda.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT7, &CMFCApplication2View::OnEnChangeEdit7)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2View::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication2View::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication2View::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication2View::OnBnClickedButton7)
	ON_COMMAND(ID_RECORD_FIRST, &CMFCApplication2View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCApplication2View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCApplication2View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCApplication2View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication2View::OnBnClickedButton8)
END_MESSAGE_MAP()

// CMFCApplication2View 构造/析构

CMFCApplication2View::CMFCApplication2View()
	: CRecordView(CMFCApplication2View::IDD)
	, name(_T(""))
	, number(_T(""))
	, major(_T(""))
	, sex(_T(""))
	, birthday(_T(""))
	, phone(_T(""))
	, address(_T(""))
	, photo(_T(""))
	, ID(0)
{
	m_pSet = NULL;
	// TODO:  在此处添加构造代码
	path = _T("D:\\VC++实验\\第十二次实验\\图片\\");
}

CMFCApplication2View::~CMFCApplication2View()
{
}

void CMFCApplication2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column7);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column8);
	DDX_Text(pDX, IDC_EDIT9, m_pSet->m_ID);
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication2Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication2View 诊断

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View 数据库支持
CRecordset* CMFCApplication2View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication2View 消息处理程序


void CMFCApplication2View::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication2View::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	Update_DLG dlg;
	int f;
	dlg.photo = path + m_pSet->column8;
	if (m_pSet->column8 == "")
	{
		dlg.s = ""; f = 0;
	}
	else { dlg.s = path + m_pSet->column8; f = 1; }
	dlg.path = path;
	dlg.name = m_pSet->column1;
	dlg.number = m_pSet->column2;
	dlg.major = m_pSet->column3;
	dlg.sex = m_pSet->column4;
	dlg.birthday = m_pSet->column5;
	dlg.phone = m_pSet->column6;
	dlg.address = m_pSet->column7;
	dlg.photo = m_pSet->column8;
	int n = dlg.DoModal();
	if (n == IDOK)
	{
		/*if (f == 0) { f = dlg.f; }
		if (dlg.photo == ""&&f == 1 && dlg.name == "")
		{
			prompt pro;
			int t = pro.DoModal();
			return;
		}*/
		m_pSet->Edit();
		m_pSet->column1 = dlg.name;
		m_pSet->column2 = dlg.number;
		m_pSet->column3 = dlg.major;
		m_pSet->column4 = dlg.sex;
		m_pSet->column5 = dlg.birthday;
		m_pSet->column6 = dlg.phone;
		m_pSet->column7 = dlg.address;
		if (f == 1) {
			CString file = path + dlg.photo;
			rename(CT2A(dlg.s.GetString()), CT2A(file.GetString()));
		}
		m_pSet->column8 = dlg.photo;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CMFCApplication2View::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	ADD_DLG dlg;
	dlg.path = path;
	int n = dlg.DoModal();
	if (n == IDOK)
	{
		/*if (dlg.name == "")
		{
			prompt pro;
			int t = pro.DoModal();
			return;
		}*/
		m_pSet->AddNew();
		m_pSet->column1 = dlg.name;
		m_pSet->column2 = dlg.number;
		m_pSet->column3 = dlg.major;
		m_pSet->column4 = dlg.sex;
		m_pSet->column5 = dlg.birthday;
		m_pSet->column6 = dlg.phone;
		m_pSet->column7 = dlg.address;
		m_pSet->column8 = dlg.photo;
		m_pSet->Update();
		m_pSet->MoveLast();
		UpdateData(false);
		Invalidate();
	}
}


void CMFCApplication2View::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void CMFCApplication2View::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	//查询功能
	chaxun q;
	int n = q.DoModal();
	if (n == IDOK) {
		UpdateData(true);
		m_pSet->m_strFilter = q.s;
		m_pSet->Requery();
		UpdateData(false);
	}
	Invalidate();
}


void CMFCApplication2View::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	sort dlg;
	int r = dlg.DoModal();
	if (r == IDOK){
		UpdateData(true);
		m_pSet->m_strSort = dlg.s;
		m_pSet->Requery();
		UpdateData(false);
	}
}


void CMFCApplication2View::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	ShowRecord dlg;
	CString str = _T("ID   姓名       学号       专业         性别   出生年月  手机号码     家庭住址       照片文件名 \r\n"), s;
	int t = m_pSet->GetODBCFieldCount();
	int f = m_pSet->m_ID; //记录指针弹出窗口前的位置ID
	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF())
	{
		for (int i = 0; i < t; i++) {
			m_pSet->GetFieldValue((short)i, s);
			str = str + "  " + s;
		}
		str = str + _T("\r\n");
		m_pSet->MoveNext();
	}
	m_pSet->MoveFirst();
	while (m_pSet->m_ID != f)  //退出窗口时指针指回弹出窗口前的位置
	{
		m_pSet->MoveNext();
	}
	dlg.record = str;
	dlg.DoModal();
	UpdateData(false);

}


void CMFCApplication2View::OnBnClickedButton7()
{
	// TODO:  在此添加控件通知处理程序代码
	m_pSet->m_strFilter = _T("");
	m_pSet->m_strSort = _T("");
	m_pSet->Requery();
	UpdateData(false);

}
void CMFCApplication2View::draw_pic(CString file){
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

void CMFCApplication2View::OnRecordFirst()
{
	// TODO:  在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFCApplication2View::OnRecordPrev()
{
	// TODO:  在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFCApplication2View::OnRecordNext()
{
	// TODO:  在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFCApplication2View::OnRecordLast()
{
	// TODO:  在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFCApplication2View::OnDraw(CDC* pDC)
{
	// TODO:  在此添加专用代码和/或调用基类
	CString filename, s;
	GetDlgItemText(IDC_EDIT8, s);
	filename = path + s;
	draw_pic(filename);
}


void CMFCApplication2View::OnBnClickedButton8()
{
	// TODO:  在此添加控件通知处理程序代码
	fangda dlg;
	CString filename, s;
	GetDlgItemText(IDC_EDIT8, s);
	filename = path + s;
	dlg.pathname = filename;
    dlg.DoModal();
}
