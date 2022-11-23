
// DemoMFCAppDoc.cpp : implementation of the CDemoMFCAppDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DemoMFCApp.h"
#endif

#include "DemoMFCAppDoc.h"
#include "SetTextDlg.h"
#include "EditBoxDlg.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDemoMFCAppDoc

IMPLEMENT_DYNCREATE(CDemoMFCAppDoc, CDocument)

BEGIN_MESSAGE_MAP(CDemoMFCAppDoc, CDocument)
	ON_COMMAND(ID_DRAW_SETTEXT, &CDemoMFCAppDoc::OnDrawSettext)
	ON_COMMAND(ID_DIALOGUE_LAUNCHDLG, &CDemoMFCAppDoc::OnDialogueLaunchdlg)
END_MESSAGE_MAP()


// CDemoMFCAppDoc construction/destruction

CDemoMFCAppDoc::CDemoMFCAppDoc() noexcept
{
	// TODO: add one-time construction code here

}

CDemoMFCAppDoc::~CDemoMFCAppDoc()
{
}

BOOL CDemoMFCAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_text.Empty();

	return TRUE;
}




// CDemoMFCAppDoc serialization

void CDemoMFCAppDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << m_text;
		SetModifiedFlag(FALSE);
	}
	else
	{
		// TODO: add loading code here
		ar >> m_text;
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CDemoMFCAppDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
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

// Support for Search Handlers
void CDemoMFCAppDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CDemoMFCAppDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDemoMFCAppDoc diagnostics

#ifdef _DEBUG
void CDemoMFCAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDemoMFCAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDemoMFCAppDoc commands


void CDemoMFCAppDoc::OnDrawSettext()
{
	// TODO: Add your command handler code here
	CSetTextDlg dlgSetText;
	dlgSetText.m_text = m_text;
	if (dlgSetText.DoModal() == IDOK) {
		m_text = dlgSetText.m_text;
		UpdateAllViews(NULL);
		SetModifiedFlag(TRUE);
	}
}


void CDemoMFCAppDoc::OnDialogueLaunchdlg()
{
	// TODO: Add your command handler code here
	CEditBoxDlg dlgEditBox;
	dlgEditBox.DoModal();
	/*dlgEditBox.m_age = */
}
