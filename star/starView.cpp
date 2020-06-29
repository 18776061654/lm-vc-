
// starView.cpp : CstarView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "star.h"
#endif

#include "starDoc.h"
#include "starView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "w32.h"

// CstarView

IMPLEMENT_DYNCREATE(CstarView, CView)

BEGIN_MESSAGE_MAP(CstarView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CstarView 构造/析构

CstarView::CstarView()
{
	// TODO:  在此处添加构造代码

}

CstarView::~CstarView()
{
}

BOOL CstarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CstarView 绘制

void CstarView::OnDraw(CDC* pDC)
{
	CstarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	CString s;
    s.Format(_T("%d"),factorial(5));
	pDC->TextOutW(200,200,s);
}


// CstarView 打印

BOOL CstarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CstarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CstarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CstarView 诊断

#ifdef _DEBUG
void CstarView::AssertValid() const
{
	CView::AssertValid();
}

void CstarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CstarDoc* CstarView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CstarDoc)));
	return (CstarDoc*)m_pDocument;
}
#endif //_DEBUG


// CstarView 消息处理程序
