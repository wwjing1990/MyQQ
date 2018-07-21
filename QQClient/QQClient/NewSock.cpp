// NewSock.cpp : implementation file
//

#include "stdafx.h"
#include "QQClient.h"
#include "NewSock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "UserList.h"
#include "Logon.h"
#include "QQClientDlg.h"

#include "Mmsystem.h"
#pragma comment(lib,"Winmm.lib")
/////////////////////////////////////////////////////////////////////////////
// CNewSock

CNewSock::CNewSock()
{
}

CNewSock::~CNewSock()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CNewSock, CSocket)
	//{{AFX_MSG_MAP(CNewSock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CNewSock member functions

void CNewSock::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(this->m_MainDlg)
	{
		MessageBox(NULL,_T("服务器断开连接!"), _T("系统"),MB_OK);
		this->m_MainDlg->SendMessage(WM_CLOSE,0,0);
	}
	this->Close();
	CSocket::OnClose(nErrorCode);
}

//接收消息
void CNewSock::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	char buffer[1000]="";
	int len = this->Receive(buffer,1000);
	CString st(buffer);
	CString Message = st.Mid(0,st.Find(','));//Mid功能：从左边第 0 个字符开始,获取后面nCount个字符
	//登陆成功显示好友列表
	if(0==strcmp((CStringA)Message,"FriendList"))
	{
		this->m_LogonDlg->lg();
		strcpy(((CQQClientApp*)AfxGetApp())->temp,buffer);
	}
	//登陆失败
	if(0==strcmp((CStringA)Message,"CanNotLogon"))
	{
		MessageBox(NULL,_T("登录失败"),_T("系统"),MB_OK);
	}
	//发送聊天消息
	if(0==strcmp((CStringA)Message,"Message"))
	{
		CString* Msg=new CString;
		Msg->Format(_T("%s"),buffer);
		m_MainDlg->m_MsgList.AddTail(Msg);//添加消息
		CString st(buffer);
		int i=st.Find(',',8);
		int e=st.Find(',',i+1);
		CString QQ(st.Mid(i+1,e-i-1));
		CPtrList *m_DL=&(m_UserListDlg->m_DlgList);
		POSITION pos=m_DL->GetHeadPosition();
	    CChat* dlg;
	    while(pos!=NULL)
		{
			dlg=((CChat*)m_DL->GetNext(pos));
			/*
			if(strcmp(dlg->QQ,QQ)==0)
			{
				if(dlg->m_SW)
				{
				   m_UserListDlg->DlgShow(QQ);
				   return;
				}
				else
					;
			}
			*/
		}

		//有信息 提示音///
		PlaySound(MAKEINTRESOURCE(IDR_MSG),AfxGetResourceHandle(),
		          SND_ASYNC|SND_RESOURCE|SND_NODEFAULT);
		
	}
	CSocket::OnReceive(nErrorCode);
}

void CNewSock::SetListDlg(CUserList *list)
{
	m_UserListDlg=list;
}

void CNewSock::SetLogonDlg(CLogon *Dlg)
{
	m_LogonDlg=Dlg;
}

void CNewSock::SetQQClientDlg(CQQClientDlg *Dlg)
{
	m_MainDlg=Dlg;
}
