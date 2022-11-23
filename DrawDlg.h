#pragma once

#include "ColorStaticCtrl.h"

// CDrawDlg dialog

class CDrawDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDrawDlg)

public:
	CDrawDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDrawDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_DRAW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	ColorStaticCtrl m_staticDraw;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
