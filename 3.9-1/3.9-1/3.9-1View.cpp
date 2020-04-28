
// 3.9-1View.cpp : CMy391View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.9-1.h"
#endif

#include "3.9-1Doc.h"
#include "3.9-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy391View

IMPLEMENT_DYNCREATE(CMy391View, CView)

BEGIN_MESSAGE_MAP(CMy391View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy391View 构造/析构

CMy391View::CMy391View()
{
	// TODO:  在此处添加构造代码

}

CMy391View::~CMy391View()
{
}

BOOL CMy391View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy391View 绘制

void CMy391View::OnDraw(CDC* /*pDC*/)
{
	CMy391Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码

}


// CMy391View 打印

BOOL CMy391View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy391View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy391View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy391View 诊断

#ifdef _DEBUG
void CMy391View::AssertValid() const
{
	CView::AssertValid();
}

void CMy391View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy391Doc* CMy391View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy391Doc)));
	return (CMy391Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy391View 消息处理程序


void CMy391View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this);
	CRect rc;
	GetClientRect(&rc);
	int nWidth = rc.Width();
	int nheight = rc.Height();
	if (nWidth>nheight)
		dc.Ellipse(0, 0, nheight, nheight);
	else
		dc.Ellipse(0, 0, nWidth, nWidth);

	CView::OnLButtonDown(nFlags, point);
}
