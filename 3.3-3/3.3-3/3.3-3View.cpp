
// 3.3-3View.cpp : CMy333View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.3-3.h"
#endif

#include "3.3-3Doc.h"
#include "3.3-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy333View

IMPLEMENT_DYNCREATE(CMy333View, CView)

BEGIN_MESSAGE_MAP(CMy333View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy333View 构造/析构

CMy333View::CMy333View()
{
	// TODO:  在此处添加构造代码

}

CMy333View::~CMy333View()
{
}

BOOL CMy333View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy333View 绘制

void CMy333View::OnDraw(CDC* /*pDC*/)
{
	CMy333Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMy333View 打印

BOOL CMy333View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy333View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy333View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy333View 诊断

#ifdef _DEBUG
void CMy333View::AssertValid() const
{
	CView::AssertValid();
}

void CMy333View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy333Doc* CMy333View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy333Doc)));
	return (CMy333Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy333View 消息处理程序


void CMy333View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy333Doc* pDoc = GetDocument();
	pDoc->count = pDoc->count + 1;

	CView::OnLButtonDown(nFlags, point);
}


void CMy333View::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default


	CView::OnMButtonDown(nFlags, point);
}


void CMy333View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy333Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->count);
	CDC* pDC = GetDC(); 
	pDC->TextOut(20, 20, s);
	CView::OnRButtonDown(nFlags, point);
	
}
