
// 4.7-3View.cpp : CMy473View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.7-3.h"
#endif

#include "4.7-3Doc.h"
#include "4.7-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy473View

IMPLEMENT_DYNCREATE(CMy473View, CView)

BEGIN_MESSAGE_MAP(CMy473View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMy473View 构造/析构

CMy473View::CMy473View()
{
	// TODO:  在此处添加构造代码
	cr.top = 300;
	cr.left = 100;
	cr.right = 200;
	cr.bottom = 400;
	set = true;
	m = 0;
}

CMy473View::~CMy473View()
{
}

BOOL CMy473View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy473View 绘制

void CMy473View::OnDraw(CDC* pDC)
{
	CMy473Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	CRect rectDlg;
	GetClientRect(rectDlg);
	
	if ((cr.right + 10) < rectDlg.Width()&&m==0)
		{
			cr.left += 10;
			cr.right += 10;
		}
	else if ((cr.left - 10) > 0)
	{
		m = 1;
		cr.left -= 10;
		cr.right -= 10;

	}
		if ((cr.left - 10) <= 0)
		{
			m = 0;

		}
	

	pDC->Ellipse(cr);
}


// CMy473View 打印

BOOL CMy473View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy473View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy473View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy473View 诊断

#ifdef _DEBUG
void CMy473View::AssertValid() const
{
	CView::AssertValid();
}

void CMy473View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy473Doc* CMy473View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy473Doc)));
	return (CMy473Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy473View 消息处理程序


void CMy473View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (set)
	{
		SetTimer(0, 100, NULL);
		set = false;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy473View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMy473View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(0);
	set = true;
	CView::OnLButtonDblClk(nFlags, point);
}
