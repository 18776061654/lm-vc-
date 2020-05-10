
// 3.23-1View.cpp : CMy3231View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.23-1.h"
#endif

#include "3.23-1Doc.h"
#include "3.23-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3231View

IMPLEMENT_DYNCREATE(CMy3231View, CView)

BEGIN_MESSAGE_MAP(CMy3231View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_COMMAND(ID_32771, &CMy3231View::On32771)
END_MESSAGE_MAP()

// CMy3231View 构造/析构

CMy3231View::CMy3231View()
{
	// TODO:  在此处添加构造代码
	ca.SetSize(256);
	n = 0;
	set = true;
}

CMy3231View::~CMy3231View()
{
}

BOOL CMy3231View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3231View 绘制

void CMy3231View::OnDraw(CDC* pDC)
{
	CMy3231Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO:  在此处为本机数据添加绘制代码
	CRect rectDlg;
	GetClientRect(rectDlg);
	CRect cr(rectDlg.Width() / 2 - n, rectDlg.Height() / 2 - n, rectDlg.Width() / 2 + n, rectDlg.Height() / 2 + n);
	n = n + 10;
	ca.Add(cr);
	pDC->SelectStockObject(NULL_BRUSH);
	for (int i = 0; i < ca.GetSize(); i++)
	{
		pDC->Ellipse(ca.GetAt(i));
	}
	
}


// CMy3231View 打印

BOOL CMy3231View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy3231View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy3231View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy3231View 诊断

#ifdef _DEBUG
void CMy3231View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3231View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3231Doc* CMy3231View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3231Doc)));
	return (CMy3231Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3231View 消息处理程序


void CMy3231View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMy3231View::On32771()
{
	// TODO: Add your command handler code here
	if (set)
	{
		SetTimer(0, 1000, NULL);
		set = false;
	}
	
}
