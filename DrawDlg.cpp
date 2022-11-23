// DrawDlg.cpp : implementation file
//

#include "pch.h"
#include "DemoMFCApp.h"
#include "DrawDlg.h"
#include "afxdialogex.h"


// CDrawDlg dialog

IMPLEMENT_DYNAMIC(CDrawDlg, CDialogEx)

CDrawDlg::CDrawDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_DRAW, pParent)
{

}

CDrawDlg::~CDrawDlg()
{
}

void CDrawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_DRAW_BOX, m_staticDraw);
}


BEGIN_MESSAGE_MAP(CDrawDlg, CDialogEx)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CDrawDlg message handlers


void CDrawDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_staticDraw.red = point.x % 256;
	m_staticDraw.green = point.y % 256;

	m_staticDraw.point = point;

	m_staticDraw.reDraw();

	CDialogEx::OnMouseMove(nFlags, point);
}
