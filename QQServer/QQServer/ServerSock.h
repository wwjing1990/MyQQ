#if !defined(__SERVERSOCK_H__)
#define __SERVERSOCK_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerSock.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CServerSock command target
class CQQServerDlg;
class CServerSock : public CSocket
{
// Attributes
public:

// Operations
public:
	CServerSock();
	CQQServerDlg* m_Dlg;
	virtual ~CServerSock();
// Overrides
public:
	char QQ[30];
	void SetDlg(CQQServerDlg* Dlg);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerSock)
	public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CServerSock)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERSOCK_H__DFB7664D_4FBD_4DC6_86C4_C8F00120F3AE__INCLUDED_)
