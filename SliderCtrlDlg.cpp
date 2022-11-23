// SliderCtrlDlg.cpp : implementation file
//

#include "pch.h"
#include "DemoMFCApp.h"
#include "SliderCtrlDlg.h"
#include "afxdialogex.h"


// CSliderCtrlDlg dialog

IMPLEMENT_DYNAMIC(CSliderCtrlDlg, CDialogEx)

CSliderCtrlDlg::CSliderCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_SLIDER_CTRL, pParent)
{

}

CSliderCtrlDlg::~CSliderCtrlDlg()
{
}

void CSliderCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_RED, m_sliderRed);
	DDX_Control(pDX, IDC_SLIDER_GREEN, m_sliderGreen);
	DDX_Control(pDX, IDC_SLIDER_BLUE, m_sliderBlue);
	DDX_Control(pDX, IDC_STATIC_COLOR_WINDOW, m_staticColorWindow);
}


BEGIN_MESSAGE_MAP(CSliderCtrlDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDOK, &CSliderCtrlDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSliderCtrlDlg message handlers

void CSliderCtrlDlg::UpdateColorStaticCtrl() {
	m_staticColorWindow.red = m_sliderRed.GetPos();
	m_staticColorWindow.green = m_sliderGreen.GetPos();
	m_staticColorWindow.blue = m_sliderBlue.GetPos();
	m_staticColorWindow.reDraw();
}

void CSliderCtrlDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	UpdateColorStaticCtrl();

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


BOOL CSliderCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_sliderRed.SetRange(0, 255);
	m_sliderGreen.SetRange(0, 255);
	m_sliderBlue.SetRange(0, 255);

	m_sliderRed.SetPos(red);
	m_sliderGreen.SetPos(green);
	m_sliderBlue.SetPos(blue);

	UpdateColorStaticCtrl();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CSliderCtrlDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	red = m_sliderRed.GetPos();
	green = m_sliderGreen.GetPos();
	blue = m_sliderBlue.GetPos();
	CDialogEx::OnOK();
}
