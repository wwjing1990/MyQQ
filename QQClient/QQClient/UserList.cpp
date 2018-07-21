// UserList.cpp : implementation file
//

#include "stdafx.h"
#include "QQClient.h"
#include "UserList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "QQClientDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CUserList dialog


CUserList::CUserList(CWnd* pParent /*=NULL*/)
	: CDialog(CUserList::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserList)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUserList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserList)
	DDX_Control(pDX, IDC_TREE2, m_Tree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserList, CDialog)
	//{{AFX_MSG_MAP(CUserList)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE2, OnDblclkTree2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserList message handlers

BOOL CUserList::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//初始化列表控件//
	m_Tree.MoveWindow(0,0,161,300,1);
	m_UserList.Create(16,16,ILC_COLOR24|ILC_MASK,20,0);
	HANDLE m_bmp;
	char temp[20];
	m_UserList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	m_UserList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
    for(int i=0;i<=20;i++)
	{
		sprintf(temp,"face\\%d-1.bmp",i);
	    m_bmp=LoadImage(NULL,(LPCWSTR)temp,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
        CBitmap m_Bitmap;
	    m_Bitmap.Attach(m_bmp);
		m_UserList.Add(&m_Bitmap,RGB(0,0,0));
        m_Bitmap.Detach();
	}
    m_Tree.SetImageList(&m_UserList,TVSIL_NORMAL);
	this->List((LPCTSTR)((CQQClientApp*)AfxGetApp())->temp);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

//双击好友列表
void CUserList::OnDblclkTree2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	HTREEITEM m_Item = m_Tree.GetSelectedItem();
	if(NULL==m_Tree.GetParentItem(m_Item))
		return;
	
	CString friName = m_Tree.GetItemText(m_Item);
	
	//char QQ[20]="";
	//strcpy(QQ, (const char*)(friName.GetBuffer));
	DlgShow(friName);
	*pResult = 0;
}

//
BOOL CUserList::List(LPCTSTR Str)
{
	CString m_Str(Str),temp;
	HTREEITEM m_Root = m_Tree.InsertItem(_T("根部"), 0, 0);;
	int s=11,e=0,i=3;
	e=m_Str.Find(',',s);
	while(e!=-1)
	{
		temp=m_Str.Mid(s,e-s);
		if(0==temp.Find(_T("Root")))
		{	
	        m_Root=m_Tree.InsertItem(m_Str.Mid(s+5,e-s-5),0,1);   
		}
		else
		{
			m_Tree.InsertItem(temp,i,i,m_Root);
		}
		i++;
		s=e+1;
		e=m_Str.Find(',',s);
	}
	
	return TRUE;
}

void CUserList::SetMainDlg(CQQClientDlg *dlg)
{
	m_MainDlg=dlg;
}

//与好友聊天
void CUserList::DlgShow(LPCTSTR Str)
{
	POSITION pos=m_DlgList.GetHeadPosition();
	CChat* dlg;
	while(pos!=NULL)
	{
		dlg=((CChat*)m_DlgList.GetNext(pos));
		if(strcmp(dlg->QQ, (const char*)Str)==0)
		{
			dlg->ShowWindow(SW_SHOW);
			dlg->m_SW=TRUE;
			goto END;//跳转执行
		}
	}
    m_Chat = new CChat;
	m_Chat->Create(IDD_DLG_CHAT,NULL);
	m_Chat->SetQQ(Str);
	m_Chat->ShowWindow(SW_SHOW);
	m_Chat->m_SW=TRUE;
	m_DlgList.AddTail(m_Chat);
    dlg=m_Chat;

	
END:
	
	POSITION post=m_MainDlg->m_MsgList.GetHeadPosition();
	while(post!=NULL)
	{
		CString st;
		st.Format(_T("%s"),*(CString*)m_MainDlg->m_MsgList.GetAt(post));
		int i=st.Find(',',8);
		int e=st.Find(',',i+1);
		CString QQ(st.Mid(i+1,e-i-1));
		/*
		if(0==strcmp(QQ.GetBuffer,(const char*)Str))
		{
			dlg->m_Str+=QQ;
			dlg->m_Str+=":\r\n";
			int n=st.Find(_T('\0'));
			st.Format(_T("%s"),st.Mid(e+1,n-e-1));
			dlg->m_Str+=st;
			dlg->m_Str+="\r\n";
			dlg->m_Receive.SetWindowText(dlg->m_Str);
		    POSITION m_post=post;
			m_MainDlg->m_MsgList.GetNext(post);
		    m_MainDlg->m_MsgList.RemoveAt(m_post);
		}
		else
		{
			m_MainDlg->m_MsgList.GetNext(post);
		}
		*/
		
	}
	
}
