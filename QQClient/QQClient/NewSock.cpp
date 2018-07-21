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
		MessageBox(NULL,_T("�������Ͽ�����!"), _T("ϵͳ"),MB_OK);
		this->m_MainDlg->SendMessage(WM_CLOSE,0,0);
	}
	this->Close();
	CSocket::OnClose(nErrorCode);
}

//������Ϣ
void CNewSock::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	char buffer[1000]="";
	int len = this->Receive(buffer,1000);
	CString st(buffer);
	CString Message = st.Mid(0,st.Find(','));//Mid���ܣ�����ߵ� 0 ���ַ���ʼ,��ȡ����nCount���ַ�
	//��½�ɹ���ʾ�����б�
	if(0==strcmp((CStringA)Message,"FriendList"))
	{
		this->m_LogonDlg->lg();
		strcpy(((CQQClientApp*)AfxGetApp())->temp,buffer);
	}
	//��½ʧ��
	if(0==strcmp((CStringA)Message,"CanNotLogon"))
	{
		MessageBox(NULL,_T("��¼ʧ��"),_T("ϵͳ"),MB_OK);
	}
	//����������Ϣ
	if(0==strcmp((CStringA)Message,"Message"))
	{
		CString* Msg=new CString;
		Msg->Format(_T("%s"),buffer);
		m_MainDlg->m_MsgList.AddTail(Msg);//�����Ϣ
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

		//����Ϣ ��ʾ��///
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
