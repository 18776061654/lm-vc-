
// 3.27-3View.cpp : CMy3273View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.27-3.h"
#endif

#include "3.27-3Doc.h"
#include "3.27-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3273View

IMPLEMENT_DYNCREATE(CMy3273View, CView)

BEGIN_MESSAGE_MAP(CMy3273View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy3273View 构造/析构

CMy3273View::CMy3273View()
{
	// TODO:  在此处添加构造代码

	set = true;
	N = 1;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);
	}

}

CMy3273View::~CMy3273View()
{
}

BOOL CMy3273View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3273View 绘制

void CMy3273View::OnDraw(CDC* pDC)
{
	CMy3273Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set)
	{
		for (int i = 0; i < N; i++)\
		{
			SetTimer(i, 10,NULL);
			set = false;
		}
		
	}
	// TODO:  在此处为本机数据添加绘制代码

	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);
	}
}


// CMy3273View 打印

BOOL CMy3273View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy3273View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy3273View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy3273View 诊断

#ifdef _DEBUG
void CMy3273View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3273View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3273Doc* CMy3273View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3273Doc)));
	return (CMy3273Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3273View 消息处理程序


void CMy3273View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	int i = nIDEvent;
	CRect rectDlg;
	GetClientRect(rectDlg);//获得窗体的大小
	if (rectDlg.Height() == cr[i].bottom)
		m = 0;
	if (cr[i].top == 0)
		m = 1;
	if (m == 0)
	{
		cr[i].top -= 1;
		cr[i].bottom -= 1;
	}
	if (m==1)
	{
		cr[i].top += 1;
		cr[i].bottom += 1;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
