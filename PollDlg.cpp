// PollDlg.cpp : implementation file
//

#include "pch.h"
#include "DemoMFCApp.h"
#include "PollDlg.h"
#include "afxdialogex.h"


// CPollDlg dialog

IMPLEMENT_DYNAMIC(CPollDlg, CDialogEx)

CPollDlg::CPollDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_RADIO_BTN, pParent)
	, m_participationPollValue(PARTICIPATE_POLL_LATER)
	, m_answerPollValue(ANSWER_POLL_MERCEDES)
{

}

CPollDlg::~CPollDlg()
{
}

void CPollDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_NO, m_participationPollValue);
	DDX_Radio(pDX, IDC_RADIO_MERCEDES, m_answerPollValue);
	DDX_Control(pDX, IDC_RADIO_MERCEDES, m_ctrlMercedes);
	DDX_Control(pDX, IDC_RADIO_FERRARI, m_ctrlFerrari);
	DDX_Control(pDX, IDC_RADIO_BMW, m_ctrlBmw);
	DDX_Control(pDX, IDC_ANSWER_POLL, m_ctrlAnswerPoll);
}

void CPollDlg::ShowAnswerPoll(bool show)
{
	int cmdShow = show ? SW_SHOW : SW_HIDE;
	m_ctrlAnswerPoll.ShowWindow(cmdShow);
	m_ctrlMercedes.ShowWindow(cmdShow);
	m_ctrlFerrari.ShowWindow(cmdShow);
	m_ctrlBmw.ShowWindow(cmdShow);
}


BEGIN_MESSAGE_MAP(CPollDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_NO, &CPollDlg::OnBnClickedRadioNo)
	ON_BN_CLICKED(IDC_RADIO_LATER, &CPollDlg::OnBnClickedRadioLater)
	ON_BN_CLICKED(IDC_RADIO_YES, &CPollDlg::OnBnClickedRadioYes)
END_MESSAGE_MAP()


// CPollDlg message handlers


void CPollDlg::OnBnClickedRadioNo()
{
	// TODO: Add your control notification handler code here
	ShowAnswerPoll(false);
}


void CPollDlg::OnBnClickedRadioLater()
{
	// TODO: Add your control notification handler code here
	ShowAnswerPoll(false);
}


void CPollDlg::OnBnClickedRadioYes()
{
	// TODO: Add your control notification handler code here
	ShowAnswerPoll(true);
}



BOOL CPollDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	ShowAnswerPoll(m_participationPollValue == PARTICIPATE_POLL_YES);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
