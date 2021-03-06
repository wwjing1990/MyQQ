
// QQServerDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "QQServer.h"
#include "QQServerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma warning(suppress : 4996)

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


// CQQServerDlg 对话框



CQQServerDlg::CQQServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_QQSERVER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQQServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	DDX_Control(pDX, IDC_STATIC2, m_ServerState);
	DDX_Control(pDX, IDC_STATIC1, m_Static);
	DDX_Control(pDX, IDC_START, m_btnStart);
	DDX_Control(pDX, IDC_STOP, m_btnStop);
}

BEGIN_MESSAGE_MAP(CQQServerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CQQServerDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_STOP, &CQQServerDlg::OnBnClickedStop)
END_MESSAGE_MAP()


// CQQServerDlg 消息处理程序

BOOL CQQServerDlg::OnInitDialog()
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
	m_State = FALSE;
	this->refurbish();
	m_Str.Format(_T(""));
	m_Edit.SetWindowText(_T(""));
	curdata.Format(_T(""));

	m_btnStart.EnableWindow(TRUE);//设置按钮可用
	m_btnStop.EnableWindow(FALSE);//设置按钮不可用

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CQQServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CQQServerDlg::OnPaint()
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
HCURSOR CQQServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//开启服务
void CQQServerDlg::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_State)
	{
		MessageBox(_T("服务器已经打开!"));
	}
	else
	{
		//创建套件字
		m_Socket.Create(1000, SOCK_STREAM, _T("127.0.0.1"));
		m_Socket.SetDlg(this);
		//监听
		if (m_Socket.Listen(100))
		{
			m_State = TRUE;
			this->refurbish();
			//获取系统当前时间
			time = CTime::GetCurrentTime();
			curdata = time.Format("【%Y-%m-%d %H:%M:%S %a】服务器开启\r\n");
			m_Str += curdata;
			m_Edit.SetWindowText(m_Str);
			MessageBox(_T("服务成功开启"));

			m_btnStart.EnableWindow(FALSE);
			m_btnStop.EnableWindow(TRUE);
		}
	}
}

//关闭服务
void CQQServerDlg::OnBnClickedStop()
{
	// TODO: 在此添加控件通知处理程序代码
	if (MessageBox(_T("确定关闭服务吗?"), _T("系统"), MB_YESNO) == IDYES)
	{
		//关闭套接字
		m_Socket.Close();
		//将套接字列表CPtrList里所有记录读出来
		POSITION pos = m_SocketList.GetHeadPosition();
		while (pos != NULL)
		{
			CServerSock* socket = (CServerSock*)m_SocketList.GetNext(pos);
			if (socket != NULL)
			{
				socket->Close();
				delete socket;
			}
		}
		m_SocketList.RemoveAll();

		m_State = FALSE;
		this->refurbish();
		//获取系统当前时间
		time = CTime::GetCurrentTime();
		curdata = time.Format("【%Y-%m-%d %H:%M:%S %a】服务器终止\r\n");
		m_Str += curdata;
		m_Edit.SetWindowText(m_Str);
		MessageBox(_T("服务终止成功"));

		m_btnStart.EnableWindow(TRUE);
		m_btnStop.EnableWindow(FALSE);
	}
}

//刷新服务器状态
void CQQServerDlg::refurbish()
{
	int Num = 0;
	POSITION pos = m_SocketList.GetHeadPosition();
	while (pos != NULL)
	{
		m_SocketList.GetNext(pos);
		Num++;
	}
	CString st;
	st.Format(_T("当前在线人数:%4d"), Num);
	m_Static.SetWindowText(st);

	if (m_State)
	{
		m_ServerState.SetWindowText(_T("服务器开启"));
	}
	else
	{
		m_ServerState.SetWindowText(_T("服务器关闭"));
	}
}

//建立连接及接收消息
void CQQServerDlg::AcceptConnect()
{
	CServerSock* pSocket = new CServerSock();
	pSocket->SetDlg(this);
	if (m_Socket.Accept(*pSocket))
	{
	}
	else
	{
		pSocket->Close();
		delete pSocket;
	}
}

//与客户端断开连接
void CQQServerDlg::Stop(CServerSock* sock)
{
	CString st;
	st.Format(_T("%s下线\r\n"), sock->QQ);
	m_Str += st;
	m_Edit.SetWindowText(m_Str);
	m_SocketList.RemoveAt(m_SocketList.Find(sock, NULL));
	delete sock;
	this->refurbish();
}

//接收数据
void CQQServerDlg::ReceiveData(CServerSock *sock)
{
	char buffer[100] = "";
	int len = sock->Receive(buffer, 100);
	//MessageBox(_T("接收数据：%s"), (LPCTSTR)buffer);

	CString st(buffer);
	CString Message = st.Mid(0, st.Find(','));//从左边第 0 个字符开始,获取后面nCount个字符

	if (0 == strcmp((CStringA)Message, "logon"))
	{
		//提取用户名
		CString UserName = st.Mid(st.Find(_T("UserName")) + 8, st.Find(_T("PassWord")) - 14);
		//提取密码
		CString PassWord = st.Mid(st.Find(_T("PassWord")) + 8, st.Find(_T('\0')));
		
		
		/////////////////////////////////////////////
		int i = strcmp("1", (CStringA)UserName);
		int j = strcmp("1", (CStringA)PassWord);
		if (!i && !j)//验证密码成功
		{
			//MessageBox(_T("验证密码成功"));
			m_SocketList.AddTail(sock);//将套接字添加到容器里
			CFile m_File;
			char data[1000] = "";
			char path[20];
			sprintf(path, ".//Users_%s.dat", UserName);
			//if (!m_File.Open((LPCTSTR)path, CFile::modeRead))//打开存放好友列表的文件
			if (!m_File.Open(L"Users_1.dat", CFile::modeRead))
				return;
			m_File.Read(data, 1000);//读取用户好友列表
			m_File.Close();//关闭文件
			send(*sock, data, sizeof(data), 0);//传输好友列表//

			strcpy(sock->QQ, (CStringA)UserName);//把qq保存到套接字对象里
			CString link;//显示上线信息
			link.Format(_T("%s上线\r\n"), UserName);
			m_Str += link;
			m_Edit.SetWindowText(m_Str);
			this->refurbish();
		}
		/////////////////////////////////////////////////////////////////////////////
		
		/*
		//查询用户名和密码//
		ADO m_Ado;
		m_Ado.OnInitADOConn();
		CString SQL = "select * from Users order by UserName";
		m_Ado.m_pRecordset = m_Ado.OpenRecordset(SQL);

		CString str;
		str.Format("UserName = '%s'", UserName);
		m_Ado.m_pRecordset->Filter = (_bstr_t)str;

		if (m_Ado.m_pRecordset->adoEOF)
		{
			send(*sock, "CanNotLogon,", sizeof("CanNotLogon,"), 0);
			sock->Close();
			delete sock;
		}
		else
		{
			int i = stricmp((char *)(_bstr_t)m_Ado.m_pRecordset->GetCollect("PassWord"), PassWord);
			if (!i)//验证密码成功
			{
				m_SocketList.AddTail(sock);//将套接字添加到容器里
				CFile m_File;
				char data[1000] = "";
				char path[20];
				sprintf(path, "Users\\%s.dat", UserName);
				if (!m_File.Open(path, CFile::modeRead))//打开存放好友列表的文件
					return;
				m_File.Read(data, 1000);//读取用户好友列表
				m_File.Close();//关闭文件
				send(*sock, data, sizeof(data), 0);//传输好友列表//
				strcpy(sock->QQ, UserName);//把qq保存到套接字对象里
				CString link;//显示上线信息
				link.Format("%s上线\r\n", UserName);
				m_Str += link;
				m_Edit.SetWindowText(m_Str);
				this->refurbish();

			}
			else//断开连接
			{
				send(*sock, "CanNotLogon,", sizeof("CanNotLogon,"), 0);
				sock->Close();
				delete sock;
			}

		}
		

		m_Ado.CloseRecordset();
		m_Ado.CloseConn();
		*/
	}
	if (0 == strcmp((CStringA)Message, "Message"))
	{
		CString st(buffer);
		int i = st.Find(_T(','), 8);
		POSITION pos = m_SocketList.GetHeadPosition();
		while (pos != NULL)
		{
			CServerSock* socket = (CServerSock*)m_SocketList.GetNext(pos);
			if (socket != NULL)
			{
				//if (0 == strcmp(st.Mid(8, i - 8), socket->QQ))
				//	send(*socket, buffer, sizeof(buffer), 0);
			}
		}

	}


}



