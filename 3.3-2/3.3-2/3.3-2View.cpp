
// 3.3-2View.cpp : implementation of the CMy332View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "3.3-2.h"
#endif

#include "3.3-2Doc.h"
#include "3.3-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy332View

IMPLEMENT_DYNCREATE(CMy332View, CView)

BEGIN_MESSAGE_MAP(CMy332View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy332View construction/destruction

CMy332View::CMy332View()
{
	// TODO: add construction code here

}

CMy332View::~CMy332View()
{
}

BOOL CMy332View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy332View drawing

void CMy332View::OnDraw(CDC* pDC)
{
	CMy332Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	CString c;
	c.Format(_T("%d"), pDoc->a);
	pDC->TextOutW(200, 200, pDoc->s);
	pDC->TextOutW(400, 200, c);
}


// CMy332View printing

BOOL CMy332View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy332View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy332View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy332View diagnostics

#ifdef _DEBUG
void CMy332View::AssertValid() const
{
	CView::AssertValid();
}

void CMy332View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy332Doc* CMy332View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy332Doc)));
	return (CMy332Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy332View message handlers
