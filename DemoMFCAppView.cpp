
// DemoMFCAppView.cpp : implementation of the CDemoMFCAppView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DemoMFCApp.h"
#endif

#include "DemoMFCAppDoc.h"
#include "DemoMFCAppView.h"
#include "PollDlg.h"
#include "DrawDlg.h"
#include "SliderCtrlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoMFCAppView

IMPLEMENT_DYNCREATE(CDemoMFCAppView, CView)

BEGIN_MESSAGE_MAP(CDemoMFCAppView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDemoMFCAppView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DRAW_DRAWACIRCLE, &CDemoMFCAppView::OnDrawDrawacircle)
	ON_COMMAND(ID_DRAW_DRAWARECTANGLE, &CDemoMFCAppView::OnDrawDrawarectangle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_DRAWACIRCLE, &CDemoMFCAppView::OnUpdateDrawDrawacircle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_DRAWARECTANGLE, &CDemoMFCAppView::OnUpdateDrawDrawarectangle)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BTN_PRESS_ME, OnBtnPressMeClicked)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_BTN_Move, &CDemoMFCAppView::OnBtnMove)
	ON_COMMAND(ID_ACTION_POLL, &CDemoMFCAppView::OnActionPoll)
	ON_COMMAND(ID_ACTION_DRAWINDIALOGUE, &CDemoMFCAppView::OnActionDrawindialogue)
	ON_COMMAND(ID_ACTION_SLIDERCONTROL, &CDemoMFCAppView::OnActionSlidercontrol)
END_MESSAGE_MAP()

// CDemoMFCAppView construction/destruction

CDemoMFCAppView::CDemoMFCAppView() noexcept
{
	// TODO: add construction code here

}

CDemoMFCAppView::~CDemoMFCAppView()
{
}

BOOL CDemoMFCAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDemoMFCAppView drawing

void CDemoMFCAppView::OnDraw(CDC* pDC)
{
	CDemoMFCAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	// Draw on main window from slider
	CRect rectWindow;
	GetClientRect(&rectWindow);

	auto color{ RGB(red, green, blue) };

	CBrush brush(color);

	pDC->FillRect(&rectWindow, &brush);

	// Draw other functionalities
	if (m_drawCircle)
		pDC->Ellipse(100, 100, 300, 300);
	else
		pDC->Rectangle(100, 100, 300, 300);

	pDC->TextOutW(100, 200, pDoc->GetText());

	CRect rectClient;
	m_button.GetClientRect(rectClient);
	if (m_redBackCol)
		pDC->FillSolidRect(rectClient, RGB(255, 0, 0));

	// Poll answer code
	CString pollText;
	pollText = _T("Poll result so far: ");
	pDC->TextOutW(600, 100, pollText);
	pollText.Format(_T("Mercedes: %d, Ferrari: %d, BMW: %d"), 
		m_mercedesCount, m_ferrariCount, m_bmwCount);
	pDC->TextOutW(600, 130, pollText);
}


// CDemoMFCAppView printing


void CDemoMFCAppView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDemoMFCAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDemoMFCAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDemoMFCAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDemoMFCAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDemoMFCAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

void CDemoMFCAppView::OnBtnPressMeClicked()
{
	if (m_followMouse) {
		m_followMouse = false;
	}
	else {
		if (!m_redBackCol)
			m_button.SetWindowTextW(L"Press Again!");
		else
			m_button.SetWindowTextW(L"Press Me!");
		m_redBackCol = !m_redBackCol;
		Invalidate();
		UpdateWindow();
	}
	
}


// CDemoMFCAppView diagnostics

#ifdef _DEBUG
void CDemoMFCAppView::AssertValid() const
{
	CView::AssertValid();
}

void CDemoMFCAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoMFCAppDoc* CDemoMFCAppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoMFCAppDoc)));
	return (CDemoMFCAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CDemoMFCAppView message handlers


void CDemoMFCAppView::OnDrawDrawacircle()
{
	// TODO: Add your command handler code here
	m_drawCircle = true;
	Invalidate();
	UpdateWindow();
}


void CDemoMFCAppView::OnDrawDrawarectangle()
{
	// TODO: Add your command handler code here
	m_drawCircle = false;
	Invalidate();
	UpdateWindow();
}


void CDemoMFCAppView::OnUpdateDrawDrawacircle(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_drawCircle);
}


void CDemoMFCAppView::OnUpdateDrawDrawarectangle(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_drawCircle);
}

LRESULT CALLBACK CustomButtonProc(HWND hWnd, UINT uMsg, WPARAM wParam,
	LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData) {
	CDemoMFCAppView* view = reinterpret_cast<CDemoMFCAppView*>(dwRefData);
	switch (uMsg)
	{
	case WM_MOUSEMOVE:
		view->MoveButton(CPoint{ GET_X_LPARAM(lParam),  GET_Y_LPARAM(lParam) }, true);
		return TRUE;
	}
	return DefSubclassProc(hWnd, uMsg, wParam, lParam);
}

int CDemoMFCAppView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_button.Create(_T("Press me!"), BS_PUSHBUTTON,
		CRect(300, 100, 380, 150), this, IDC_BTN_PRESS_ME);
	SetWindowSubclass(m_button, CustomButtonProc, 0, reinterpret_cast<DWORD_PTR>(this));
	m_button.ShowWindow(SW_SHOW);

	return 0;
}


void CDemoMFCAppView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_followMouse)
		MoveButton(point);

	CView::OnMouseMove(nFlags, point);
}

void CDemoMFCAppView::MoveButton(CPoint centralPoint, bool coordFromCustom) {
	if (!m_followMouse)
		return;
	CRect rectButton;
	m_button.GetWindowRect(rectButton);
	ScreenToClient(rectButton);
	if (coordFromCustom)
		centralPoint += rectButton.TopLeft();
	m_button.MoveWindow(centralPoint.x - rectButton.Width()/2, centralPoint.y - rectButton.Height() / 2,
		rectButton.Width(), rectButton.Height());
}

void CDemoMFCAppView::OnBtnMove()
{
	// TODO: Add your command handler code here
	m_followMouse = true;
}


void CDemoMFCAppView::OnActionPoll()
{
	// TODO: Add your command handler code here
	CPollDlg dlgPoll;

	if (dlgPoll.DoModal() == IDOK)
		if (dlgPoll.m_participationPollValue == PARTICIPATE_POLL_YES) {
			if (dlgPoll.m_answerPollValue == ANSWER_POLL_MERCEDES)
				++m_mercedesCount;
			else if (dlgPoll.m_answerPollValue == ANSWER_POLL_FERRARI)
				++m_ferrariCount;
			else
				++m_bmwCount;

			Invalidate();
			UpdateWindow();
		}
}


void CDemoMFCAppView::OnActionDrawindialogue()
{
	// TODO: Add your command handler code here
	CDrawDlg dlgDraw;
	dlgDraw.DoModal();
	
}


void CDemoMFCAppView::OnActionSlidercontrol()
{
	// TODO: Add your command handler code here
	CSliderCtrlDlg dlgSliderCtrl;

	dlgSliderCtrl.red = red;
	dlgSliderCtrl.green = green;
	dlgSliderCtrl.blue = blue;

	if (dlgSliderCtrl.DoModal() == IDOK) {
		red = dlgSliderCtrl.red;
		green = dlgSliderCtrl.green;
		blue = dlgSliderCtrl.blue;
		Invalidate();
		UpdateWindow();
	}
}
