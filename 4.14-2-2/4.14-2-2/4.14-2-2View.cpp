
// 4.14-2-2View.cpp : CMy41422View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.14-2-2.h"
#endif

#include "4.14-2-2Doc.h"
#include "4.14-2-2View.h"
#include "mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy41422View

IMPLEMENT_DYNCREATE(CMy41422View, CView)

BEGIN_MESSAGE_MAP(CMy41422View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy41422View::OnBnClickedButton1)
	ON_COMMAND(ID_32771, &CMy41422View::On32771)
END_MESSAGE_MAP()

// CMy41422View 构造/析构

CMy41422View::CMy41422View()
{
	// TODO:  在此处添加构造代码

}

CMy41422View::~CMy41422View()
{
}

BOOL CMy41422View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy41422View 绘制

void CMy41422View::OnDraw(CDC* pDC)
{
	CMy41422Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	pDC->Ellipse(pDoc->cr);
}


// CMy41422View 打印

BOOL CMy41422View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy41422View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy41422View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy41422View 诊断

#ifdef _DEBUG
void CMy41422View::AssertValid() const
{
	CView::AssertValid();
}

void CMy41422View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy41422Doc* CMy41422View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy41422Doc)));
	return (CMy41422Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy41422View 消息处理程序


void CMy41422View::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	

	

}


void CMy41422View::On32771()
{
	// TODO: Add your command handler code here
	mydlg dlg;
	CMy41422Doc* pDoc = GetDocument();
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		pDoc->cr.left = dlg.left;
		pDoc->cr.right = dlg.right;
		pDoc->cr.top = dlg.top;
		pDoc->cr.bottom = dlg.bottom;
		Invalidate();
	}
}
