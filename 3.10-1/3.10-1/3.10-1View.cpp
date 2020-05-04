
// 3.10-1View.cpp : CMy3101View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.10-1.h"
#endif

#include "3.10-1Doc.h"
#include "3.10-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3101View

IMPLEMENT_DYNCREATE(CMy3101View, CView)

BEGIN_MESSAGE_MAP(CMy3101View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy3101View 构造/析构

CMy3101View::CMy3101View()
{
	// TODO:  在此处添加构造代码

}

CMy3101View::~CMy3101View()
{
}

BOOL CMy3101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3101View 绘制

void CMy3101View::OnDraw(CDC* /*pDC*/)
{
	CMy3101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMy3101View 打印

BOOL CMy3101View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy3101View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy3101View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy3101View 诊断

#ifdef _DEBUG
void CMy3101View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3101Doc* CMy3101View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3101Doc)));
	return (CMy3101Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3101View 消息处理程序


void CMy3101View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CString s;
	s = _T("左键正在被按下");
	CClientDC dc(this);              //创建一个对象
	dc.TextOutW(100, 200, s);           //输出s

	CView::OnLButtonDown(nFlags, point);
}


void CMy3101View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// TODO: Add your message handler code here and/or call default
	CString s;
	s = _T("左键正在被抬起");
	CClientDC dc(this);              //创建一个对象
	dc.TextOutW(100, 200, s);           //输出s
	CView::OnLButtonUp(nFlags, point);
}
