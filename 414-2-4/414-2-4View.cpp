
// 414-2-4View.cpp : CMy41424View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "414-2-4.h"
#endif

#include "414-2-4Doc.h"
#include "414-2-4View.h"
#include "mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy41424View

IMPLEMENT_DYNCREATE(CMy41424View, CView)

BEGIN_MESSAGE_MAP(CMy41424View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy41424View::OnBnClickedButton1)
	ON_COMMAND(ID_32771, &CMy41424View::On32771)
END_MESSAGE_MAP()

// CMy41424View 构造/析构

CMy41424View::CMy41424View()
{
	// TODO:  在此处添加构造代码
	x = 0;
	y = 0;
	z = 0;
}

CMy41424View::~CMy41424View()
{
}

BOOL CMy41424View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy41424View 绘制

void CMy41424View::OnDraw(CDC* pDC)
{
	CMy41424Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	
	pDC->Ellipse(20, 20, 200, 200);
	if (z != 0)
	{
		CBrush brush(RGB(x, y, z));//根据自己需要填充颜色
		CBrush *oldbrush;
		oldbrush = pDC->SelectObject(&brush);//选新的画刷
		pDC->Ellipse(20, 20, 200, 200);
		pDC->SelectObject(oldbrush);//将原来的画刷选回去 
	}
}


// CMy41424View 打印

BOOL CMy41424View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy41424View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy41424View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy41424View 诊断

#ifdef _DEBUG
void CMy41424View::AssertValid() const
{
	CView::AssertValid();
}

void CMy41424View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy41424Doc* CMy41424View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy41424Doc)));
	return (CMy41424Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy41424View 消息处理程序


void CMy41424View::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

}


void CMy41424View::On32771()
{
	// TODO: Add your command handler code here
	mydlg dlg;
	int r = dlg.DoModal();
	x = dlg.x;
	y = dlg.y;
	z = dlg.z;
	if (r == IDOK)
	{
		Invalidate();
	}

}
