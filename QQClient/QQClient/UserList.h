#if !defined(AFX_USERLIST_H__FED6D057_F5AD_4C5E_99D4_B8C52D0BF7F3__INCLUDED_)
#define AFX_USERLIST_H__FED6D057_F5AD_4C5E_99D4_B8C52D0BF7F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserList.h : header file
//
#include "Chat.h"
/////////////////////////////////////////////////////////////////////////////
// CUserList dialog
class CQQClientDlg;
class CUserList : public CDialog
{
// Construction
public:
	void DlgShow(LPCTSTR Str);
	void SetMainDlg(CQQClientDlg* dlg);
	BOOL List(LPCTSTR Str);
	CUserList(CWnd* pParent = NULL);   // standard constructor
    CImageList m_UserList;
	CChat* m_Chat;
	CPtrList m_DlgList;
	CQQClientDlg* m_MainDlg;

// Dialog Data
	//{{AFX_DATA(CUserList)
	enum { IDD = IDD_DLG_LIST};
	CTreeCtrl	m_Tree;	//好友列表树形控件
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserList)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkTree2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERLIST_H__FED6D057_F5AD_4C5E_99D4_B8C52D0BF7F3__INCLUDED_)
