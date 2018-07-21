#include "NewSock.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Chat.h : header file
//

//#include "code/Shin_Title.h"
//#include "code/Shin_HotButton.h"
//#include "code/ShinShare.h"
// comment( lib, "ShinShare.lib" )  

/////////////////////////////////////////////////////////////////////////////
// CChat dialog

class CChat : public CDialog
{
// Construction
public:
	CNewSock *m_Socket;
	void SetQQ(LPCTSTR Str);
	CChat(CWnd* pParent = NULL);   // standard constructor
    //Shin_Title m_Title;
	//Shin_HotButton m_Button[17];
	//Shin_HotButton m_SendButton;
	char QQ[50];//ÁÄÌì×´Ì¬ÐÅÏ¢
	CString m_Str;
	BOOL m_SW;
// Dialog Data
	//{{AFX_DATA(CChat)
	enum { IDD = IDD_DLG_CHAT };
	CEdit	m_Send;
	CEdit	m_Receive;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChat)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChat)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSend();
	afx_msg void OnClose();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
