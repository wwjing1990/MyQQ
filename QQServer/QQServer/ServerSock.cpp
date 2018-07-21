// ServerSock.cpp : implementation file
//

#include "stdafx.h"
#include "QQServer.h"
#include "ServerSock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSock
#include "QQServerDlg.h"
CServerSock::CServerSock()
{
}

CServerSock::~CServerSock()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSock, CSocket)
	//{{AFX_MSG_MAP(CServerSock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSock member functions

void CServerSock::SetDlg(CQQServerDlg *Dlg)
{
	m_Dlg=Dlg;
}

void CServerSock::OnAccept(int nErrorCode) 
{
	// TODO: Add your special ized code here and/or call the base class
	MessageBox(NULL,L"有用户连接",L"系统",MB_OK);
	m_Dlg->AcceptConnect();
	CSocket::OnAccept(nErrorCode);
}

void CServerSock::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
    if(m_Dlg)
		m_Dlg->Stop(this);
	
	CSocket::OnClose(nErrorCode);
}

void CServerSock::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_Dlg)
		m_Dlg->ReceiveData(this);
	CSocket::OnReceive(nErrorCode);
}
