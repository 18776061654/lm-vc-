
// 3.24-3View.cpp : CMy3243View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.24-3.h"
#endif

#include "3.24-3Doc.h"
#include "3.24-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3243View

IMPLEMENT_DYNCREATE(CMy3243View, CView)

BEGIN_MESSAGE_MAP(CMy3243View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMy3243View::On32771)
	ON_COMMAND(ID_32772, &CMy3243View::On32772)
	ON_COMMAND(ID_32773, &CMy3243View::On32773)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy3243View 构造/析构

CMy3243View::CMy3243View()
{
	// TODO:  在此处添加构造代码

}

CMy3243View::~CMy3243View()
{
}

BOOL CMy3243View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3243View 绘制

void CMy3243View::OnDraw(CDC* /*pDC*/)
{
	CMy3243Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMy3243View 打印

BOOL CMy3243View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy3243View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy3243View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy3243View 诊断

#ifdef _DEBUG
void CMy3243View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3243View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3243Doc* CMy3243View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3243Doc)));
	return (CMy3243Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3243View 消息处理程序


void CMy3243View::On32771()
{
	// TODO: Add your command handler code here
	m = 1;
}


void CMy3243View::On32772()
{
	// TODO: Add your command handler code here
	m = 2;
}


void CMy3243View::On32773()
{
	// TODO: Add your command handler code here
	m = 3;
}


void CMy3243View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m == 1 || m == 2 || m == 3)
	{
		n = point;
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMy3243View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m == 1)
	{

		HDC hdc;
		hdc = ::GetDC(m_hWnd);
		MoveToEx(hdc, n.x, n.y, NULL);
		LineTo(hdc, point.x, point.y);
	}
	if (m == 2)
	{
		CClientDC dc(this);
		dc.Rectangle(CRect(n, point));
	}
	if (m == 3)
	{
		CClientDC dc(this);
		dc.Ellipse(CRect(n, point));
	}

	CView::OnLButtonUp(nFlags, point);
}
