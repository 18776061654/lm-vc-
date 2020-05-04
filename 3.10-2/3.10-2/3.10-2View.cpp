
// 3.10-2View.cpp : CMy3102View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.10-2.h"
#endif

#include "3.10-2Doc.h"
#include "3.10-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3102View

IMPLEMENT_DYNCREATE(CMy3102View, CView)

BEGIN_MESSAGE_MAP(CMy3102View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy3102View 构造/析构

CMy3102View::CMy3102View()
{
	// TODO:  在此处添加构造代码

}

CMy3102View::~CMy3102View()
{
}

BOOL CMy3102View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3102View 绘制

void CMy3102View::OnDraw(CDC* /*pDC*/)
{
	CMy3102Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMy3102View 打印

BOOL CMy3102View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy3102View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy3102View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy3102View 诊断

#ifdef _DEBUG
void CMy3102View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3102View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3102Doc* CMy3102View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3102Doc)));
	return (CMy3102Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3102View 消息处理程序


void CMy3102View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy3102Doc* pDoc = GetDocument();
	CString s;
	int c;
	c = pDoc->a + pDoc->b;
	CClientDC dc(this);              //创建一个对象
	s.Format(_T("A+B=%d"),c);
	dc.TextOutW(100, 200, s);           //输出s


	CView::OnLButtonDown(nFlags, point);
}
