
// 4.7-1View.cpp : CMy471View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.7-1.h"
#endif

#include "4.7-1Doc.h"
#include "4.7-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy471View

IMPLEMENT_DYNCREATE(CMy471View, CView)

BEGIN_MESSAGE_MAP(CMy471View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy471View 构造/析构

CMy471View::CMy471View()
{
	// TODO:  在此处添加构造代码
	cr.top = 100;
	cr.left = 100;
	cr.right = 400;
	cr.bottom = 400;
	top = 0;
	right = 0;
	left = 0;
	bottom = 0;
	M = 0;
}

CMy471View::~CMy471View()
{
}

BOOL CMy471View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy471View 绘制

void CMy471View::OnDraw(CDC* pDC)
{
	CMy471Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO:  在此处为本机数据添加绘制代码

	pDC->Rectangle(cr);
}


// CMy471View 打印

BOOL CMy471View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy471View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy471View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy471View 诊断

#ifdef _DEBUG
void CMy471View::AssertValid() const
{
	CView::AssertValid();
}

void CMy471View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy471Doc* CMy471View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy471Doc)));
	return (CMy471Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy471View 消息处理程序


void CMy471View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (point.x >= cr.left&&point.x <= cr.right&&point.y >= cr.top&&point.y <= cr.bottom)
	{
		left = point.x - cr.left;
		right = cr.right - point.x;
		top = point.y - cr.top;
		bottom = cr.bottom - point.y;
		M = 1;
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMy471View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (M == 1)
	{
		cr.left = point.x - left;
		cr.right = point.x + right;
		cr.top = point.y - top;
		cr.bottom = point.y + bottom;
		Invalidate();
		M = 0;
	}
	CView::OnLButtonUp(nFlags, point);
}
