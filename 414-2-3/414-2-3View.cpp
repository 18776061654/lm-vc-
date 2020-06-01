
// 414-2-3View.cpp : CMy41423View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "414-2-3.h"
#endif

#include "414-2-3Doc.h"
#include "414-2-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy41423View

IMPLEMENT_DYNCREATE(CMy41423View, CView)

BEGIN_MESSAGE_MAP(CMy41423View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy41423View 构造/析构

CMy41423View::CMy41423View()
{
	// TODO:  在此处添加构造代码

}

CMy41423View::~CMy41423View()
{
}

BOOL CMy41423View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy41423View 绘制

void CMy41423View::OnDraw(CDC* pDC)
{
	CMy41423Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	
	pDC->Ellipse(pDoc->cr);

	

}


// CMy41423View 打印

BOOL CMy41423View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy41423View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy41423View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy41423View 诊断

#ifdef _DEBUG
void CMy41423View::AssertValid() const
{
	CView::AssertValid();
}

void CMy41423View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy41423Doc* CMy41423View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy41423Doc)));
	return (CMy41423Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy41423View 消息处理程序


void CMy41423View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (point.x >= 200 && point.x < 500 && point.y >= 200 && point.y < 300)
	{
		CMy41423Doc* pDoc = GetDocument();
		CDC * dc = GetDC();
		CPen * pOldPen = NULL;
		CPen pen;
		pen.CreatePen(PS_DASH, 1, RGB(0, 255, 0));
		pOldPen = dc->SelectObject(&pen);
		CBrush * pOldBrush = NULL;
		CBrush * pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		pOldBrush = dc->SelectObject(pBrush);
		dc->Rectangle(&pDoc->cr);
		dc->SelectObject(pOldPen);
		pen.DeleteObject();
	}
	CView::OnLButtonDown(nFlags, point);
}
