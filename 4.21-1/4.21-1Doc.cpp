
// 4.21-1Doc.cpp : CMy4211Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.21-1.h"
#endif

#include "4.21-1Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy4211Doc

IMPLEMENT_DYNCREATE(CMy4211Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy4211Doc, CDocument)
END_MESSAGE_MAP()


// CMy4211Doc 构造/析构

CMy4211Doc::CMy4211Doc()
{
	// TODO:  在此添加一次性构造代码
	
		a[0] = _T("da");
		a[1] = _T("fadad");
		a[2] = _T("daafafd");
		a[3] = _T("dagawda");
		a[4] = _T("dafads");
		a[5] = _T("dadaas");
		a[6] = _T("dajfgh");
		a[7] = _T("dafasss");
		a[8] = _T("daikh");
		a[9] = _T("dasdaw");
}

CMy4211Doc::~CMy4211Doc()
{
}

BOOL CMy4211Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMy4211Doc 序列化

void CMy4211Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		for (int i = 0; i < 10; i++)
		{
			
			ar <<a[i];
		}	// TODO:  在此添加存储代码
	}
	else
	{
		for ( int i = 0; i < 10;i++)
		{
			ar >> a[i];
		}	// TODO:  在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMy4211Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMy4211Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMy4211Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy4211Doc 诊断

#ifdef _DEBUG
void CMy4211Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy4211Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy4211Doc 命令
