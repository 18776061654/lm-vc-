
// 04.07View.cpp : implementation of the CMy0407View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "04.07.h"
#endif

#include "04.07Doc.h"
#include "04.07View.h"
#include "mydialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0407View

IMPLEMENT_DYNCREATE(CMy0407View, CView)

BEGIN_MESSAGE_MAP(CMy0407View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_POPOUT, &CMy0407View::OnPopout)
END_MESSAGE_MAP()

// CMy0407View construction/destruction

CMy0407View::CMy0407View()
{
	// TODO: add construction code here

}

CMy0407View::~CMy0407View()
{
}

BOOL CMy0407View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy0407View drawing

void CMy0407View::OnDraw(CDC* /*pDC*/)
{
	CMy0407Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMy0407View printing

BOOL CMy0407View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy0407View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy0407View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy0407View diagnostics

#ifdef _DEBUG
void CMy0407View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0407View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0407Doc* CMy0407View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0407Doc)));
	return (CMy0407Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0407View message handlers


void CMy0407View::OnPopout()
{
	// TODO: Add your command handler code here
	mydialog dlg;
	int t = dlg.DoModal();

	if (t == IDOK)
	{
		CString s;
		s = _T("您已退出对话框");
		CClientDC dc(this);              //创建一个对象
		dc.TextOutW(100, 200, s);           //输出s


	}
}
