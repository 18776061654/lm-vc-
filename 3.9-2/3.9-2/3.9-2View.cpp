
// 3.9-2View.cpp : CMy392View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.9-2.h"
#endif

#include "3.9-2Doc.h"
#include "3.9-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy392View

IMPLEMENT_DYNCREATE(CMy392View, CView)

BEGIN_MESSAGE_MAP(CMy392View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy392View 构造/析构

CMy392View::CMy392View()
{
	// TODO:  在此处添加构造代码
	

}

CMy392View::~CMy392View()
{
}

BOOL CMy392View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy392View 绘制

void CMy392View::OnDraw(CDC* pDC)
{
	CMy392Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	for (int i = 0; i < pDoc->ca.GetSize(); i++){
	
		pDC->Ellipse(pDoc->ca.GetAt(i));
	}

	
}


// CMy392View 打印

BOOL CMy392View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy392View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy392View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy392View 诊断

#ifdef _DEBUG
void CMy392View::AssertValid() const
{
	CView::AssertValid();
}

void CMy392View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy392Doc* CMy392View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy392Doc)));
	return (CMy392Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy392View 消息处理程序


void CMy392View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy392Doc* pDoc = GetDocument();
	int r = rand() % 50 + 5;
	int t = rand() % 50 + 5;
	CRect cr(point.x - r, point.y - t, point.x + r, point.y + t);

	pDoc->ca.Add(cr);
	this->Invalidate();
	
	CView::OnLButtonDown(nFlags, point);
}
