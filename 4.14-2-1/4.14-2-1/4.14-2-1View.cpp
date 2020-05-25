
// 4.14-2-1View.cpp : CMy41421View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.14-2-1.h"
#endif

#include "4.14-2-1Doc.h"
#include "4.14-2-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy41421View

IMPLEMENT_DYNCREATE(CMy41421View, CView)

BEGIN_MESSAGE_MAP(CMy41421View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_MBUTTONDOWN()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy41421View 构造/析构

CMy41421View::CMy41421View()
{
	// TODO:  在此处添加构造代码

}

CMy41421View::~CMy41421View()
{
}

BOOL CMy41421View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy41421View 绘制

void CMy41421View::OnDraw(CDC* pDC)
{
	CMy41421Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	pDC->Ellipse(pDoc->cr);
}


// CMy41421View 打印

BOOL CMy41421View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy41421View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy41421View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy41421View 诊断

#ifdef _DEBUG
void CMy41421View::AssertValid() const
{
	CView::AssertValid();
}

void CMy41421View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy41421Doc* CMy41421View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy41421Doc)));
	return (CMy41421Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy41421View 消息处理程序


//void CMy41421View::OnMButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: Add your message handler code here and/or call default
//
//	CView::OnMButtonDown(nFlags, point);
//}


void CMy41421View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy41421Doc* pDoc = GetDocument();
	if ((point.x >= pDoc->cr.left) && (point.x < pDoc->cr.right) && (point.y < pDoc->cr.bottom) && (point.y >= pDoc->cr.top))
	{
		pDoc->left = point.x - pDoc->cr.left;
		pDoc->right = pDoc->cr.right - point.x;
		pDoc->top = point.y - pDoc->cr.top;
		pDoc->bottom = pDoc->cr.bottom - point.y;
		pDoc->n = 1;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy41421View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy41421Doc* pDoc = GetDocument();
	pDoc->n = 0;
	CView::OnLButtonUp(nFlags, point);
}


void CMy41421View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy41421Doc* pDoc = GetDocument();
	if ((pDoc->n) == 1)
	{
		pDoc->cr.left = point.x - pDoc->left;
		pDoc->cr.right = pDoc->right + point.x;
		pDoc->cr.top = point.y - pDoc->top;
		pDoc->cr.bottom = pDoc->bottom + point.y;
		Invalidate();
	}
	
	CView::OnMouseMove(nFlags, point);
}
