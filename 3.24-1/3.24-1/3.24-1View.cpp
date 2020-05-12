
// 3.24-1View.cpp : CMy3241View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.24-1.h"
#endif

#include "3.24-1Doc.h"
#include "3.24-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3241View

IMPLEMENT_DYNCREATE(CMy3241View, CView)

BEGIN_MESSAGE_MAP(CMy3241View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_NAME_LMNAME, &CMy3241View::OnNameLmname)
END_MESSAGE_MAP()

// CMy3241View 构造/析构

CMy3241View::CMy3241View()
{
	// TODO:  在此处添加构造代码

}

CMy3241View::~CMy3241View()
{
}

BOOL CMy3241View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3241View 绘制

void CMy3241View::OnDraw(CDC* /*pDC*/)
{
	CMy3241Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMy3241View 打印

BOOL CMy3241View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy3241View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy3241View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy3241View 诊断

#ifdef _DEBUG
void CMy3241View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3241View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3241Doc* CMy3241View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3241Doc)));
	return (CMy3241Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3241View 消息处理程序


void CMy3241View::OnNameLmname()
{
	// TODO: Add your command handler code here
	CString s = _T("姓名：卢敏");
	CClientDC dc(this);
	dc.TextOutW(200, 300, s);

}
