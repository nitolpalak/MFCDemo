
// DemoMFCAppView.h : interface of the CDemoMFCAppView class
//

#pragma once

constexpr UINT IDC_BTN_PRESS_ME{ 101 };

class CDemoMFCAppView : public CView
{
protected: // create from serialization only
	CDemoMFCAppView() noexcept;
	DECLARE_DYNCREATE(CDemoMFCAppView)

// Attributes
public:
	CDemoMFCAppDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CDemoMFCAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

private:
	int m_mercedesCount = 0;
	int m_ferrariCount = 0;
	int m_bmwCount = 0;
	int red{ 255 }, green{ 255 }, blue{ 255 };
// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnBtnPressMeClicked();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawDrawacircle();
	afx_msg void OnDrawDrawarectangle();
private:
	bool m_drawCircle{ true };
	CButton m_button;
	bool m_redBackCol{ false };
	bool m_followMouse{ false };
	void MoveButton(CPoint point, bool coordFromCustom = false);
	friend LRESULT CALLBACK CustomButtonProc(HWND hWnd, UINT uMsg, WPARAM wParam,
		LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData);
public:
	afx_msg void OnUpdateDrawDrawacircle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawDrawarectangle(CCmdUI *pCmdUI);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
//	afx_msg void OnBtnMove();
	afx_msg void OnBtnMove();
	afx_msg void OnActionPoll();
	afx_msg void OnActionDrawindialogue();
	afx_msg void OnActionSlidercontrol();
};

#ifndef _DEBUG  // debug version in DemoMFCAppView.cpp
inline CDemoMFCAppDoc* CDemoMFCAppView::GetDocument() const
   { return reinterpret_cast<CDemoMFCAppDoc*>(m_pDocument); }
#endif

