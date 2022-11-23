#pragma once

#include "ColorStaticSliderCtrl.h"

// CSliderCtrlDlg dialog

class CSliderCtrlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSliderCtrlDlg)

public:
	CSliderCtrlDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSliderCtrlDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_SLIDER_CTRL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int red{ 255 }, green{ 255 }, blue{ 255 };
	CSliderCtrl m_sliderRed;
	CSliderCtrl m_sliderGreen;
	CSliderCtrl m_sliderBlue;
	ColorStaticSliderCtrl m_staticColorWindow;
	void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
private:
	afx_msg void UpdateColorStaticCtrl();
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
