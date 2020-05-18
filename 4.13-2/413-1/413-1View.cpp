
// 413-1View.cpp : CMy4131View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "413-1.h"
#endif
#include "mydialog.h"
#include "413-1Doc.h"
#include "413-1View.h"
#include "mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy4131View

IMPLEMENT_DYNCREATE(CMy4131View, CView)

BEGIN_MESSAGE_MAP(CMy4131View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_32771, &CMy4131View::On32771)
END_MESSAGE_MAP()

// CMy4131View 构造/析构

CMy4131View::CMy4131View()
{
	// TODO:  在此处添加构造代码
	s1 = "";
}

CMy4131View::~CMy4131View()
{
}

BOOL CMy4131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy4131View 绘制

void CMy4131View::OnDraw(CDC* /*pDC*/)
{
	CMy4131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMy4131View 打印

BOOL CMy4131View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy4131View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy4131View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy4131View 诊断

#ifdef _DEBUG
void CMy4131View::AssertValid() const
{
	CView::AssertValid();
}

void CMy4131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy4131Doc* CMy4131View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4131Doc)));
	return (CMy4131Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy4131View 消息处理程序


void CMy4131View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	mydlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		 s1 = dlg.s;
		GetDC()->TextOutW(200, 100, s1);
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CMy4131View::On32771()
{
	// TODO: Add your command handler code here
	mydialog mydlg;
	mydlg.s2 = s1;
	int r = mydlg.DoModal();
	if (r == IDOK)
	{
		
	}
	
}

