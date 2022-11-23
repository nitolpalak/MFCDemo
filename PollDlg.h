#pragma once


// CPollDlg dialog
const int PARTICIPATE_POLL_NO{ 0 };
const int PARTICIPATE_POLL_LATER{ 1 };
const int PARTICIPATE_POLL_YES{ 2 };

const int ANSWER_POLL_MERCEDES{ 0 };
const int ANSWER_POLL_FERRARI{ 1 };
const int ANSWER_POLL_BMW{ 2 };

class CPollDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPollDlg)

public:
	CPollDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPollDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_RADIO_BTN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	void ShowAnswerPoll(bool show);
public:
	int m_participationPollValue;
	int m_answerPollValue;
	afx_msg void OnBnClickedRadioNo();
	afx_msg void OnBnClickedRadioLater();
	afx_msg void OnBnClickedRadioYes();
	CButton m_ctrlMercedes;
	CButton m_ctrlFerrari;
	CButton m_ctrlBmw;
	CStatic m_ctrlAnswerPoll;
	virtual BOOL OnInitDialog();
};
