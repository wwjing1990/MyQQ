
// QQClientDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "QQClient.h"
#include "QQClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CQQClientDlg 对话框



CQQClientDlg::CQQClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_QQCLIENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQQClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CQQClientDlg)
	DDX_Control(pDX, IDC_EDIT1, m_Search);
	DDX_Control(pDX, IDC_TAB_QQ, m_Tab);
	//}}AFX_DATA_MAP
	
}

BEGIN_MESSAGE_MAP(CQQClientDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CQQClientDlg 消息处理程序

BOOL CQQClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//初始化透明按钮 用于显示用户昵称//
	m_Name.MoveWindow(80, 40, 80, 17, 1);
	//窗体初始位置和大小///
	CBitmap	bitmap;
	BITMAP  bmp;
	bitmap.LoadBitmap(IDB_MAIN);//加载位图
	bitmap.GetObject(sizeof(BITMAP), &bmp);
	this->MoveWindow(1060, 60, bmp.bmWidth, bmp.bmHeight, 1);
	
	//初始化标题栏
	m_Title.Create(this);
	
	char temp[6][20];
	sprintf(temp[0], "picture\\01.bmp");
	sprintf(temp[1], "picture\\04.bmp");
	sprintf(temp[2], "picture\\02.bmp");
	sprintf(temp[3], "picture\\05.bmp");
	sprintf(temp[4], "picture\\03.bmp");
	sprintf(temp[5], "picture\\06.bmp");
	//m_Title.SetBitmap((LPCTSTR)temp[0], (LPCTSTR)temp[1], (LPCTSTR)temp[2], (LPCTSTR)temp[3], (LPCTSTR)temp[4], (LPCTSTR)temp[5]);
	//m_Title.SetHide(TRUE);//设置最小化时隐藏任务框//
	//绘制头像及工具栏按钮//
	
	char bt[50];
	HANDLE m_hBmp;
	for (int i = 0; i<7; i++)
	{
		sprintf(bt, "picture\\bt%d.bmp", i);
		m_hBmp = LoadImage(NULL, (LPCWSTR)bt, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		CBitmap bt_map;
		bt_map.Attach(m_hBmp);
		m_HotButton[i].SetCBitmap(&bt_map, &bt_map);
		BITMAP m_Bmp;
		bt_map.GetBitmap(&m_Bmp);
		switch (i)//设置位图按钮位置//////////
		{
		case 0:
			m_HotButton[i].MoveWindow(12, 32, m_Bmp.bmWidth - 2, m_Bmp.bmHeight - 2, 1);
			break;
		case 1:
			m_HotButton[i].MoveWindow(14, 100, m_Bmp.bmWidth - 2, m_Bmp.bmHeight - 2, 1);
			break;
		case 2:
			m_HotButton[i].MoveWindow(40, 100, m_Bmp.bmWidth - 2, m_Bmp.bmHeight - 2, 1);
			break;
		case 3:
			m_HotButton[i].MoveWindow(66, 100, m_Bmp.bmWidth - 2, m_Bmp.bmHeight - 2, 1);
			break;
		case 4:
			m_HotButton[i].MoveWindow(92, 100, m_Bmp.bmWidth - 2, m_Bmp.bmHeight - 2, 1);
			break;
		case 5:
			m_HotButton[i].MoveWindow(118, 100, m_Bmp.bmWidth - 2, m_Bmp.bmHeight - 2, 1);
			break;
		case 6:
			m_HotButton[i].MoveWindow(144, 100, m_Bmp.bmWidth - 2, m_Bmp.bmHeight - 2, 1);
			break;
		}
		bt_map.Detach();//释放位图对象//
	}

	
	//初始化标签控件///
	m_TabImageList.Create(30, 36, ILC_COLOR24 | ILC_MASK, 1, 0);
	HANDLE m_bmp;
	char Tab[20];
	for (int j = 1; j<8; j++)
	{
		sprintf(Tab, "picture\\Tab%d.bmp", j);
		m_bmp = LoadImage(NULL, (LPCWSTR)Tab, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		CBitmap m_Bitmap;
		m_Bitmap.Attach(m_bmp);
		m_TabImageList.Add(&m_Bitmap, RGB(0, 0, 0));
		m_Bitmap.Detach();
	}

	m_Tab.SetImageList(&m_TabImageList);
	m_Tab.SetItemSize(CSize(36, 30));
	m_Tab.SetPadding(CSize(0, 2));
	m_Tab.InsertItem(0, NULL, 0);
	m_Tab.InsertItem(1, NULL, 1);
	m_Tab.InsertItem(2, NULL, 2);
	m_Tab.InsertItem(3, NULL, 3);
	m_Tab.InsertItem(4, NULL, 4);
	m_Tab.InsertItem(5, NULL, 5);
	m_Tab.InsertItem(6, NULL, 6);
	m_Tab.MoveWindow(1, 126, 194, 300, 1);
	
	//显示列表对话框及树状列表//
	m_UserList = new CUserList;
	m_UserList->SetMainDlg(this);
	m_UserList->Create(IDD_DLG_LIST, &m_Tab);//创建好友列表对话框
	m_UserList->MoveWindow(33, 1, 161, 297);
	m_UserList->ShowWindow(SW_SHOW);
	((CQQClientApp*)AfxGetApp())->m_Socket.SetListDlg(m_UserList);//传递UserList指针给套接字

	m_Search.MoveWindow(14, 515, 144, 20);


	NOTIFYICONDATA notl;//创建托盘图标对象
	notl.cbSize = sizeof(notl);
	notl.hIcon = AfxGetApp()->LoadIcon(IDI_QQ);//指定托盘图标
	notl.hWnd = this->m_hWnd;				   //指定窗口句柄
	notl.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;//指定有效成员
	notl.uCallbackMessage = WM_TRAYNOTIFY;	 //自定义消息
	//strcpy((char*)notl.szTip, "QQ\0");	//添加气泡提示
	wcscpy(notl.szTip, L"QQ");
	notl.uID = IDD_QQCLIENT_DIALOG;
	::Shell_NotifyIcon(NIM_ADD, &notl);//在托盘区添加图标 
	this->SetWindowText(_T("我的聊天程序"));
	
	//创建一个线程来更新托盘图标
	m_Thread = CreateThread(NULL, 0, ThreadProc, this, 0, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//线程函数
DWORD _stdcall ThreadProc(LPVOID lpParameter)//线程函数///
{
	CQQClientDlg* m_Dlg = (CQQClientDlg *)lpParameter;
	NOTIFYICONDATA notl;
	notl.cbSize = sizeof(notl);
	notl.hIcon = AfxGetApp()->LoadIcon(IDI_QQ);
	notl.hWnd = m_Dlg->m_hWnd;
	notl.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	notl.uCallbackMessage = WM_TRAYNOTIFY;
	//strcpy((char*)notl.szTip, "QQ");
	wcscpy(notl.szTip, L"QQ");
	notl.uID = IDD_QQCLIENT_DIALOG;

	while (1)
	{
		//将消息指针列表里的消息读出来
		POSITION pos = m_Dlg->m_MsgList.GetHeadPosition();
		if (pos == NULL)
		{
			Sleep(10);
		}
		else
		{
			notl.hIcon = NULL;
			::Shell_NotifyIcon(NIM_MODIFY, &notl);
			
			HTREEITEM m_Item[50], m_RootItem[20];
			int m_Num[50], n = 0, x = 0; CString text[20];
			while (pos != NULL)
			{
				CString st;
				st.Format(_T("%s"), *(CString*)m_Dlg->m_MsgList.GetAt(pos));
				int i = st.Find(',', 8);
				int e = st.Find(',', i + 1);
				CString QQ(st.Mid(i + 1, e - i - 1));
				/*
				HTREEITEM m_Root;
				m_Root = m_Dlg->m_UserList->m_Tree.GetFirstVisibleItem();
				BOOL m_Flag = TRUE;
				while (m_Root != NULL)
				{
					HTREEITEM m_Child;
					m_Child = m_Dlg->m_UserList->m_Tree.GetChildItem(m_Root);
					while (m_Child != NULL)
					{
						CString st(m_Dlg->m_UserList->m_Tree.GetItemText(m_Child));
						if (0 == strcmp(st, QQ))
						{

							for (int u = 0; u<50; u++)
							{
								if (m_Child == m_Item[u])
									goto END;
							}
							m_Dlg->m_UserList->m_Tree.GetItemImage(m_Child, m_Num[n], m_Num[n]);
							m_Item[n] = m_Child;
							m_Dlg->m_UserList->m_Tree.SetItemImage(m_Child, 2, 2);
							n++;
							if (m_Flag)
							{
								if (x>0)
								{
									for (u = 0; u<20; u++)
									{
										if (m_Root == m_RootItem[u])
											goto END;
									}
								}
								m_RootItem[x] = m_Root;
								m_Flag = FALSE;
								text[x].Format("%s", m_Dlg->m_UserList->m_Tree.GetItemText(m_Root));
								m_Dlg->m_UserList->m_Tree.SetItemText(m_Root, "");
								x++;
							}
						}
					END:					m_Child = m_Dlg->m_UserList->m_Tree.GetNextItem(m_Child, TVGN_NEXT);
					}
					m_Root = m_Dlg->m_UserList->m_Tree.GetNextItem(m_Root, TVGN_NEXT);

				}
				*/

				m_Dlg->m_MsgList.GetNext(pos);
				//m_Flag = TRUE;
			}

			Sleep(600);

			notl.hIcon = AfxGetApp()->LoadIcon(IDI_QQ);
			::Shell_NotifyIcon(NIM_MODIFY, &notl);
			for (int t = 0; t<n; t++)
			{
				//m_Dlg->m_UserList->m_Tree.SetItemImage(m_Item[t], m_Num[t], m_Num[t]);
				m_Item[t] = NULL;
			}
			//for (t = 0; t<x; t++)
				//m_Dlg->m_UserList->m_Tree.SetItemText(m_RootItem[t], text[t]);
			Sleep(600);
		}
	}

	return 0;
}

void CQQClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CQQClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CQQClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

