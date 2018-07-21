#include "NewSock.h"	// Added by ClassView
#include "afxwin.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Logon.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogon dialog

class CLogon : public CDialog
{
// Construction
public:
	void lg();
	CNewSock *m_Socket;
	CLogon(CWnd* pParent = NULL);   // standard constructor
    BOOL m_Extend;
	CFileFind m_Find;
// Dialog Data
	//{{AFX_DATA(CLogon)
	enum { IDD = IDD_DLG_LOGON};
	CEdit	m_PassWord;//√‹¬Î
	CComboBox	m_UserName;//QQ∫≈
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogon)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogon)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


public:
	afx_msg void OnBnClickedBtnLogon();
	//afx_msg void OnBnClickedBtnLogon();
	afx_msg void OnBnClickedBtnApply();
	afx_msg void OnBnClickedBtnFindpsw();
	afx_msg void OnBnClickedExtend();
	afx_msg void OnBnClickedBtnCancel();
	afx_msg void OnBnClickedBtnTest();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
