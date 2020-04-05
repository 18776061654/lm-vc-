
// MFCApplication3View.cpp : implementation of the CMFCApplication3View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication3.h"
#endif

#include "MFCApplication3Doc.h"
#include "MFCApplication3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3View

IMPLEMENT_DYNCREATE(CMFCApplication3View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication3View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFCApplication3View construction/destruction

CMFCApplication3View::CMFCApplication3View()
{
	// TODO: add construction code here

}

CMFCApplication3View::~CMFCApplication3View()
{
}

BOOL CMFCApplication3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplication3View drawing

void CMFCApplication3View::OnDraw(CDC* pDC)
{
	CMFCApplication3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->Rectangle(500, 200, 850, 360);
}


// CMFCApplication3View printing

BOOL CMFCApplication3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplication3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplication3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCApplication3View diagnostics

#ifdef _DEBUG
void CMFCApplication3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication3Doc* CMFCApplication3View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication3Doc)));
	return (CMFCApplication3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication3View message handlers
int i = 0;
int y = 0;

void CMFCApplication3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	/*SetCaretPos(point);
	m_strLine[i].Empty();
	m_ptorigin = point;*/
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	if (nChar == 0x08)//退格
	{
		COLORREF clr = dc.SetTextColor(dc.GetBkColor());
		dc.TextOut(510, 210+y, m_strLine[i]);
		m_strLine[i] = m_strLine[i].Left(m_strLine[i].GetLength() - 1);
		dc.SetTextColor(clr);
		
	}
	else
	{
		m_strLine[i] +=(wchar_t)nChar;
	}
	if (m_strLine[i].GetLength() >= 35)
	{
		i++;
		y += 30;
	}
	if (i <=4)
	{


		CSize cs = dc.GetTextExtent(m_strLine[i]);//获得字符串的宽度

		dc.TextOut(510, 210 + y, m_strLine[i]);
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}
