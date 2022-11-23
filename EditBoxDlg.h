#pragma once


// CEditBoxDlg dialog

class CEditBoxDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditBoxDlg)

public:
	CEditBoxDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CEditBoxDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_EDIT_BOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	int m_age;
	double m_height;
	int m_id;
	CString m_personalInfo;
	CString m_info;
	afx_msg void OnBnClickedBtnShowInfo();
};
