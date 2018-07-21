
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewSock.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CNewSock command target
class CQQClientDlg;
class CLogon;
class CUserList;
class CNewSock : public CSocket
{
// Attributes
public:
	CQQClientDlg * m_MainDlg;
	CLogon* m_LogonDlg;
	CUserList* m_UserListDlg;
// Operations
public:
	CNewSock();
	virtual ~CNewSock();

// Overrides
public:
	void SetQQClientDlg(CQQClientDlg* Dlg);
	void SetLogonDlg(CLogon* Dlg);
	void SetListDlg(CUserList* list);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewSock)
	public:
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CNewSock)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
