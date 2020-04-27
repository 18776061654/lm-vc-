
// tuxingView.cpp : CtuxingView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "tuxing.h"
#endif

#include "tuxingDoc.h"
#include "tuxingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtuxingView

IMPLEMENT_DYNCREATE(CtuxingView, CView)

BEGIN_MESSAGE_MAP(CtuxingView, CView)
END_MESSAGE_MAP()

// CtuxingView 构造/析构

CtuxingView::CtuxingView()
{
	// TODO:  在此处添加构造代码

}

CtuxingView::~CtuxingView()
{
}

BOOL CtuxingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CtuxingView 绘制

void CtuxingView::OnDraw(CDC* /*pDC*/)
{
	CtuxingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	CString s,c;
	int a = 20;
	s = _T("我是大帅哥!!");
	c.Format(_T("%d"), a);
	CClientDC dc(this);              //创建一个对象
	dc.TextOutW(100, 200, s);           //输出s
	dc.TextOutW(400, 200, c);
	



}


// CtuxingView 诊断

#ifdef _DEBUG
void CtuxingView::AssertValid() const
{
	CView::AssertValid();
}

void CtuxingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtuxingDoc* CtuxingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtuxingDoc)));
	return (CtuxingDoc*)m_pDocument;
}
#endif //_DEBUG


// CtuxingView 消息处理程序
