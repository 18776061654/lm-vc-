
// 3.16View.cpp : CMy316View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.16.h"
#endif

#include "3.16Doc.h"
#include "3.16View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy316View

IMPLEMENT_DYNCREATE(CMy316View, CView)

BEGIN_MESSAGE_MAP(CMy316View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy316View 构造/析构

CMy316View::CMy316View()
{
	// TODO:  在此处添加构造代码

}

CMy316View::~CMy316View()
{
}

BOOL CMy316View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy316View 绘制

void CMy316View::OnDraw(CDC* pDC)
{
	CMy316Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->cr);
	// TODO:  在此处为本机数据添加绘制代码
}


// CMy316View 打印

BOOL CMy316View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy316View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy316View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy316View 诊断

#ifdef _DEBUG
void CMy316View::AssertValid() const
{
	CView::AssertValid();
}

void CMy316View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy316Doc* CMy316View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy316Doc)));
	return (CMy316Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy316View 消息处理程序


void CMy316View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	CMy316Doc* pDoc = GetDocument();
	pDoc->cr.left = point.x;
	pDoc->cr.top = point.y;


	CView::OnLButtonDown(nFlags, point);
}


void CMy316View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy316Doc* pDoc = GetDocument();
	pDoc->cr.right = point.x;
	pDoc->cr.bottom = point.y;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonUp(nFlags, point);
}


void CMy316View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CString s;
	s.Format(_T("鼠标当前坐标：(%d,%d)"), point.x, point.y); //把鼠标的值转换到s
	CClientDC dc(this);              //创建一个对象
	dc.TextOutW(100, 200, s);           //输出s


	CView::OnMouseMove(nFlags, point);
}
