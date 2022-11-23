// SetTextDlg.cpp : implementation file
//

#include "pch.h"
#include "DemoMFCApp.h"
#include "SetTextDlg.h"
#include "afxdialogex.h"


// CSetTextDlg dialog

IMPLEMENT_DYNAMIC(CSetTextDlg, CDialogEx)

CSetTextDlg::CSetTextDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_SET_TEXT, pParent)
	, m_text(_T(""))
{

}

CSetTextDlg::~CSetTextDlg()
{
}

void CSetTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_text);
}


BEGIN_MESSAGE_MAP(CSetTextDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_TEXT, &CSetTextDlg::OnEnChangeEditText)
END_MESSAGE_MAP()


// CSetTextDlg message handlers


void CSetTextDlg::OnEnChangeEditText()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
