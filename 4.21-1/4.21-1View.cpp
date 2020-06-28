
// 4.21-1View.cpp : CMy4211View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.21-1.h"
#endif
#include "mydlg.h"
#include "4.21-1Doc.h"
#include "4.21-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy4211View

IMPLEMENT_DYNCREATE(CMy4211View, CView)

BEGIN_MESSAGE_MAP(CMy4211View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMy4211View::On32771)
END_MESSAGE_MAP()

// CMy4211View 构造/析构

CMy4211View::CMy4211View()
{
	// TODO:  在此处添加构造代码

}

CMy4211View::~CMy4211View()
{
}

BOOL CMy4211View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy4211View 绘制

void CMy4211View::OnDraw(CDC* /*pDC*/)
{
	CMy4211Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMy4211View 打印

BOOL CMy4211View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy4211View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy4211View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy4211View 诊断

#ifdef _DEBUG
void CMy4211View::AssertValid() const
{
	CView::AssertValid();
}

void CMy4211View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy4211Doc* CMy4211View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4211Doc)));
	return (CMy4211Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy4211View 消息处理程序


void CMy4211View::On32771()
{
	// TODO: Add your command handler code here
	CMy4211Doc* pDoc = GetDocument();
	mydlg dlg;
	for (int i = 0; i < 10;i++)
	dlg.a[i] = pDoc->a[i];
	int r = dlg.DoModal();


}
