
// MFCApplication1View.cpp : CMFCApplication1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCApplication1View 构造/析构

CMFCApplication1View::CMFCApplication1View()
{
	// TODO:  在此处添加构造代码
	set = true; N = 5;
	for (int i = 0; i < N; i++)//构造多个矩形
	{
		int t = (i + 1) * 100;//左上角位置
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);//把矩形放入数组中
	}
}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 绘制

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	
	if (set){
		for (int i = 0; i < N; i++){
			SetTimer(i, rand() % 400 + 100, NULL);
			set = false;
		}
	}
		for (int i = 0; i < N; i++){
			pDC->Ellipse(cr[i]);
		}
}


// CMFCApplication1View 诊断

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 消息处理程序


void CMFCApplication1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent;
	CRect clientRec;
	GetClientRect(&clientRec );
	static int f = 1;
	if ((cr[i].bottom < clientRec.bottom)&&(f==1))
	{
		cr[i].top += 10;
		cr[i].bottom += 10;
		Invalidate();
	}
	else{
		    f = 0;
			cr[i].top -= 10;
			cr[i].bottom -= 10;
			Invalidate();
	}
	
	CView::OnTimer(nIDEvent);
}
