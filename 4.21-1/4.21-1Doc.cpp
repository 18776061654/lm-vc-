
// 4.21-1Doc.cpp : CMy4211Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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


// CMy4211Doc ����/����

CMy4211Doc::CMy4211Doc()
{
	// TODO:  �ڴ����һ���Թ������
	
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

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMy4211Doc ���л�

void CMy4211Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		for (int i = 0; i < 10; i++)
		{
			
			ar <<a[i];
		}	// TODO:  �ڴ���Ӵ洢����
	}
	else
	{
		for ( int i = 0; i < 10;i++)
		{
			ar >> a[i];
		}	// TODO:  �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMy4211Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CMy4211Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CMy4211Doc ���

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


// CMy4211Doc ����
