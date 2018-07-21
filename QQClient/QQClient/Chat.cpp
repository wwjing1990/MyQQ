// Chat.cpp : implementation file
//

#include "stdafx.h"
#include "QQClient.h"
#include "Chat.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "Logon.h"
/////////////////////////////////////////////////////////////////////////////
// CChat dialog


CChat::CChat(CWnd* pParent /*=NULL*/)
	: CDialog(CChat::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChat)
	//}}AFX_DATA_INIT
	m_SW=FALSE;
}


void CChat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChat)
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_EDIT2, m_Send);
	DDX_Control(pDX, IDC_EDIT1, m_Receive);
	/*
	DDX_Control(pDX, Send, m_SendButton);
	DDX_Control(pDX, 2001, m_Button[0]);
	DDX_Control(pDX, 2002, m_Button[1]);
	DDX_Control(pDX, 2003, m_Button[2]);
	DDX_Control(pDX, 2004, m_Button[3]);
	DDX_Control(pDX, 2005, m_Button[4]);
	DDX_Control(pDX, 2006, m_Button[5]);
	DDX_Control(pDX, 2007, m_Button[6]);
	DDX_Control(pDX, 2008, m_Button[7]);
	DDX_Control(pDX, 2009, m_Button[8]);
	DDX_Control(pDX, 3000, m_Button[9]);
	DDX_Control(pDX, 3001, m_Button[10]);
	DDX_Control(pDX, 3002, m_Button[11]);
	DDX_Control(pDX, 3003, m_Button[12]);
	DDX_Control(pDX, 3004, m_Button[13]);
	DDX_Control(pDX, 3005, m_Button[14]);
	DDX_Control(pDX, 4000, m_Button[15]);
	DDX_Control(pDX, 4001, m_Button[16]);
	*/
}


BEGIN_MESSAGE_MAP(CChat, CDialog)
	//{{AFX_MSG_MAP(CChat)
	ON_WM_PAINT()
	ON_BN_CLICKED(Send, OnSend)
	ON_WM_CLOSE()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChat message handlers

BOOL CChat::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	this->MoveWindow(370,145,523,436,1);

	    //初始化标题栏
    //m_Title.Create(this);
	//char temp[6][20];
	
	//sprintf(temp[0],"picture\\07.bmp");
    /*sprintf(temp[1],"picture\\04.bmp");
	sprintf(temp[2],"picture\\08.bmp");
	sprintf(temp[3],"picture\\05.bmp");
	sprintf(temp[4],"picture\\09.bmp");
	sprintf(temp[5],"picture\\06.bmp");*/
	//m_Title.SetBitmap((LPCTSTR)temp[0], (LPCTSTR)temp[1], (LPCTSTR)temp[2], (LPCTSTR)temp[3], (LPCTSTR)temp[4], (LPCTSTR)temp[5]);
	m_Receive.MoveWindow(10,90,360,185,1);
	m_Send.MoveWindow(10,310,360,75,1);

	/////
	/*
    char bt[50];
	HANDLE m_hBmp;
    for(int i=1;i<18;i++)
	{
		sprintf(bt,"picture\\ToolBar%d.bmp",i);
	    m_hBmp=LoadImage(NULL,bt,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	    CBitmap bt_map;
	    bt_map.Attach(m_hBmp);
	    m_Button[i-1].SetCBitmap(&bt_map,&bt_map);
	    BITMAP m_Bmp;
	    bt_map.GetBitmap(&m_Bmp);
	    switch(i)//设置位图按钮位置//////////
		{
		case 1 : 
		    m_Button[i-1].MoveWindow(12,45,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
	        break;
	    case 2 :
            m_Button[i-1].MoveWindow(50,45,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
		    break;
	    case 3:
		    m_Button[i-1].MoveWindow(88,45,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
	        break;
	    case 4:
		    m_Button[i-1].MoveWindow(126,45,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
	        break;
	    case 5:
		    m_Button[i-1].MoveWindow(164,45,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
	        break;
	    case 6:
		    m_Button[i-1].MoveWindow(202,45,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
	        break;
	    case 7:
		    m_Button[i-1].MoveWindow(238,45,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
	        break;
		case 8:
			m_Button[i-1].MoveWindow(390,90,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
			break;
		case 9:
			m_Button[i-1].MoveWindow(390,260,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
			break;
		case 10:
			m_Button[i-1].MoveWindow(10,284,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
			break;
		case 11:
			m_Button[i-1].MoveWindow(47,284,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
			break;
		case 12:
			m_Button[i-1].MoveWindow(80,284,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
			break;
		case 13:
			m_Button[i-1].MoveWindow(117,284,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
			break;
		case 14:
			m_Button[i-1].MoveWindow(152,284,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
			break;
		case 15:
			m_Button[i-1].MoveWindow(188,284,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
			break;
		case 16:
			m_Button[i-1].MoveWindow(10,384,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
			break;
		case 17:
			m_Button[i-1].MoveWindow(34,384,m_Bmp.bmWidth-2,m_Bmp.bmHeight-2,1);
			break;
		}
		bt_map.Detach();//释放位图对象//
	}

	m_hBmp=LoadImage(NULL,"picture\\SendNormal.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	CBitmap m_Bitmap[2];
	m_Bitmap[0].Attach(m_hBmp);
	m_hBmp=LoadImage(NULL,"picture\\SendHot.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	m_Bitmap[1].Attach(m_hBmp);
	m_SendButton.SetCBitmap(&m_Bitmap[0],&m_Bitmap[1]);
    m_Bitmap[0].Detach();
	m_Bitmap[1].Detach();
    m_SendButton.MoveWindow(300,390,69,21);

	m_Socket=&((CMSNApp*)AfxGetApp())->m_Socket;//获取全局套接字的地址
	*/
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CChat::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CDC memDC;
	CBitmap	bitmap;
	BITMAP  bmp;
	bitmap.LoadBitmap(IDB_CHAT);
	bitmap.GetObject (sizeof(BITMAP),&bmp);
	memDC.CreateCompatibleDC (&dc);
	memDC.SelectObject (bitmap);
    dc.BitBlt(0,0,bmp.bmWidth,bmp.bmHeight,&memDC,0,0,SRCCOPY);//显示背景位图
	memDC.DeleteDC();
	bitmap.Detach();


	//m_Title.DrawTitle();
	// Do not call CDialog::OnPaint() for painting messages
}

LRESULT CChat::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	//m_Title.Message(message,wParam,lParam);
	return CDialog::DefWindowProc(message, wParam, lParam);
}

void CChat::SetQQ(LPCTSTR Str)
{
	strcpy(QQ, (const char *)Str);
	CString m_Str;
	m_Str.Format(_T("与%s聊天中...."),Str);
	//m_Title.SetText(m_Str);
}

void CChat::OnSend() 
{
	// TODO: Add your control notification handler code here
	CString Str,str,m_st;
	m_Send.GetWindowText(str);
    m_st.Format(_T("%s"),((CQQClientApp*)AfxGetApp())->QQ);
	Str.Format(_T("Message,%s,%s,%s"),QQ,m_st,str);
	send(*m_Socket, CStringA(Str),Str.GetLength(),0);
	m_Str+=m_st;
	m_Str+=":\r\n";
	m_Str+=str;
	m_Str+="\r\n";
	m_Receive.SetWindowText(m_Str);
	m_Send.SetWindowText(_T(""));
}

void CChat::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	this->m_SW=FALSE;
	CDialog::OnClose();
}

BOOL CChat::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CDialog::OnEraseBkgnd(pDC);
}
