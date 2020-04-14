
// 04.07-2View.cpp : CMy04072View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "04.07-2.h"
#endif

#include "04.07-2Doc.h"
#include "04.07-2View.h"
#include "Mydialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04072View

IMPLEMENT_DYNCREATE(CMy04072View, CView)

BEGIN_MESSAGE_MAP(CMy04072View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_change, &CMy04072View::Onchange)
END_MESSAGE_MAP()

// CMy04072View 构造/析构

CMy04072View::CMy04072View()
{
	// TODO:  在此处添加构造代码

}

CMy04072View::~CMy04072View()
{
}

BOOL CMy04072View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy04072View 绘制

void CMy04072View::OnDraw(CDC* /*pDC*/)
{
	CMy04072Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMy04072View 打印

BOOL CMy04072View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy04072View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy04072View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy04072View 诊断

#ifdef _DEBUG
void CMy04072View::AssertValid() const
{
	CView::AssertValid();
}

void CMy04072View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy04072Doc* CMy04072View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04072Doc)));
	return (CMy04072Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy04072View 消息处理程序


void CMy04072View::Onchange()
{
	// TODO: Add your command handler code here
	Mydialog dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
}
