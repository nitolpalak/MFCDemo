// EditBoxDlg.cpp : implementation file
//

#include "pch.h"
#include "DemoMFCApp.h"
#include "EditBoxDlg.h"
#include "afxdialogex.h"


// CEditBoxDlg dialog

IMPLEMENT_DYNAMIC(CEditBoxDlg, CDialogEx)

CEditBoxDlg::CEditBoxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_EDIT_BOX, pParent)
	, m_name(_T(""))
	, m_age(0)
	, m_height(0)
	, m_id(0)
	, m_personalInfo(_T(""))
	, m_info(_T(""))
{

}

CEditBoxDlg::~CEditBoxDlg()
{
}

void CEditBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_AGE, m_age);
	DDX_Text(pDX, IDC_EDIT_AGE, m_age);
	DDV_MinMaxInt(pDX, m_age, 0, 100);
	DDX_Text(pDX, IDC_EDIT_HEIGHT, m_height);
	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDX_Text(pDX, IDC_EDIT_PERSONAL_INFO, m_personalInfo);
	DDX_Text(pDX, IDC_EDIT_INFO, m_info);
}


BEGIN_MESSAGE_MAP(CEditBoxDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_SHOW_INFO, &CEditBoxDlg::OnBnClickedBtnShowInfo)
END_MESSAGE_MAP()


// CEditBoxDlg message handlers


void CEditBoxDlg::OnBnClickedBtnShowInfo()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_info.Format(
		_T("Name: %s, Age: %d, Height: %.2f, "
			"It is nice to learn MFC. \r\n"
			"It is nice to learn MFC. \r\n"
			"It is nice to learn. \r\n"
			"It is nice to learn MFC. \r\n"
			"It is nice to learn MFC. \r\n"
			"It is. \r\n"
			"It is nice to learn MFC. \r\n"
			"It is nice to learn MFC. \r\n"
		),
		m_name, m_age, m_height
	);
	UpdateData(FALSE);
}
