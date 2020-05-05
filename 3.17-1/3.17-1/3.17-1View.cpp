
// 3.17-1View.cpp : CMy3171View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.17-1.h"
#endif

#include "3.17-1Doc.h"
#include "3.17-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3171View

IMPLEMENT_DYNCREATE(CMy3171View, CView)

BEGIN_MESSAGE_MAP(CMy3171View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy3171View 构造/析构

CMy3171View::CMy3171View()
{
	// TODO:  在此处添加构造代码

}

CMy3171View::~CMy3171View()
{
}

BOOL CMy3171View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3171View 绘制

void CMy3171View::OnDraw(CDC* /*pDC*/)
{
	CMy3171Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMy3171View 打印

BOOL CMy3171View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy3171View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy3171View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy3171View 诊断

#ifdef _DEBUG
void CMy3171View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3171View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3171Doc* CMy3171View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3171Doc)));
	return (CMy3171Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3171View 消息处理程序


void CMy3171View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy3171Doc* pDoc = GetDocument();
	CClientDC dc(this);              //创建一个对象
	CString s;
	
	
	if (nFlags)
	{
		pDoc->count++;
		s.Format(_T("mousemove发生了：%d 次"), pDoc->count);
		dc.TextOutW(100, 200, s);           //输出s

	}

	CView::OnMouseMove(nFlags, point);
}


void CMy3171View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy3171Doc* pDoc = GetDocument();
	pDoc->x1 = point.x;
	CView::OnLButtonDown(nFlags, point);
}


void CMy3171View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy3171Doc* pDoc = GetDocument();
	CClientDC dc(this);              //创建一个对象
	CString s;
	pDoc->x2 = point.x;
	pDoc->count = 0;
	s.Format(_T("横向移动了：%d 像素"), pDoc->x2 -pDoc->x1);
	dc.TextOutW(100, 300, s);           //输出s
	CView::OnLButtonUp(nFlags, point);
}
