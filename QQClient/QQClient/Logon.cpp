// Logon.cpp : implementation file
//

#include "stdafx.h"
#include "QQClient.h"
#include "Logon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "Mmsystem.h"
#pragma comment(lib,"Winmm.lib")
/////////////////////////////////////////////////////////////////////////////
// CLogon dialog


CLogon::CLogon(CWnd* pParent /*=NULL*/)
	: CDialog(CLogon::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogon)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLogon::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogon)
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_PassWord);
	DDX_Control(pDX, IDC_COMBO_QQNO, m_UserName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogon, CDialog)
	//{{AFX_MSG_MAP(CLogon)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BTN_LOGON, &CLogon::OnBnClickedBtnLogon)
	ON_BN_CLICKED(IDC_BTN_APPLY, &CLogon::OnBnClickedBtnApply)
	ON_BN_CLICKED(IDC_BTN_FINDPSW, &CLogon::OnBnClickedBtnFindpsw)
	ON_BN_CLICKED(IDC_EXTEND, &CLogon::OnBnClickedExtend)
	ON_BN_CLICKED(IDC_BTN_CANCEL, &CLogon::OnBnClickedBtnCancel)
	ON_BN_CLICKED(IDC_BTN_TEST, &CLogon::OnBnClickedBtnTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogon message handlers

BOOL CLogon::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Extend=FALSE;
	this->MoveWindow(470,260,327,230,1);

	m_Socket=&((CQQClientApp*)AfxGetApp())->m_Socket;//获取全局的套接字指针//
    this->SetIcon(AfxGetApp()->LoadIcon(IDI_QQ),TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/* 暂时不知道何用？
void CLogon::OnButton3() 
{
	// TODO: Add your control notification handler code here
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(),
		     SND_ASYNC|SND_RESOURCE|SND_NODEFAULT);
	if(m_Extend)
	{
		this->MoveWindow(470,260,327,230,1);
		GetDlgItem(IDC_EXTEND)->SetWindowText("高级设置↓");		
		m_Extend=FALSE;
	}
	else
	{
		this->MoveWindow(470,260,327,390,1);
		GetDlgItem(IDC_EXTEND)->SetWindowText("高级设置↑");
		m_Extend=TRUE;
	}
}
*/
BOOL CLogon::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rc;
	GetClientRect(&rc);
	CBrush brush, *pOldbrush;
	brush.CreateSolidBrush(RGB(236, 246, 255));
	pOldbrush=pDC->SelectObject(&brush);
	pDC->FillRect(&rc, &brush);
	pDC->SelectObject(pOldbrush);
	return true;
//	return CDialog::OnEraseBkgnd(pDC);
}


//申请QQ号
void CLogon::OnBnClickedBtnApply()
{
	// TODO: Add your control notification handler code here
	PROCESS_INFORMATION pi;//创建进程信息结果
	STARTUPINFO si; //指定新进程的主窗口特性
	//初始化变量
	memset(&si,0,sizeof(si));
	si.cb=sizeof(si);			//指定该结构大小
	si.wShowWindow=SW_SHOW;		//新窗口的显示状态
	si.dwFlags=STARTF_USESHOWWINDOW;//创建窗口标志
	//打开浏览器程序
	TCHAR cmd[256] = _T("C:\\Program Files\\Internet Explorer\\iexplore.exe  http://www.baidu.com");  //设置外部程序名
	BOOL fRet = CreateProcess(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	if(!fRet)
	{//创建失败，显示错误信息
		MessageBox(L"奇怪，打不开浏览器!且问题无法解决",L"友情提示", MB_OK);
		return;
	}
}

//找回密码
void CLogon::OnBnClickedBtnFindpsw()
{
	// TODO: Add your control notification handler code here
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	//初始化变量
	memset(&si,0,sizeof(si));
	si.cb=sizeof(si);
	si.wShowWindow=SW_SHOW;
	si.dwFlags=STARTF_USESHOWWINDOW;
	//打开游览器程序
	TCHAR cmd[256] = _T("C:\\Program Files\\Internet Explorer\\iexplore.exe  http://www.qq.com");
	BOOL fRet=CreateProcess(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

	if(!fRet)
	{//创建失败，显示错误信息
		MessageBox(L"奇怪，打不开游览器!且问题无法解决",L"友情提示", MB_OK);
		return;
	}	
}


//取消登陆
void CLogon::OnBnClickedBtnCancel()
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}


//logon登陆OK
void CLogon::lg()
{
	this->OnOK();
}


void CLogon::OnBnClickedExtend()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CLogon::OnBnClickedBtnTest()
{
	// TODO: 在此添加控件通知处理程序代码
}


//登陆
void CLogon::OnBnClickedBtnLogon()
{
	// TODO: Add your control notification handler code here
	CString UserName, PassWord, m_Str;
	m_UserName.GetWindowText(UserName);
	m_PassWord.GetWindowText(PassWord);
	if (UserName.IsEmpty() || PassWord.IsEmpty())
	{
		MessageBox(_T("用户名和密码不能为空!"));
		return;
	}

	UINT port;
	port = atoi("1000");
	m_Socket->Create();//创建套接字//
	if (m_Socket->Connect(_T("127.0.0.1"), port))
	{
		m_Str += "logon,UserName";
		m_Str += UserName;
		m_Str += "PassWord";
		m_Str += PassWord;
		//向一个已经连接的socket发送数据，如果无错误，返回值为所发送数据的总数
		int iSend = send(*m_Socket, (CStringA)m_Str.GetBuffer(m_Str.GetLength()), m_Str.GetLength(), 0);
		if (iSend == SOCKET_ERROR)
		{
			MessageBox(_T("连接失败"), NULL, MB_OK);
		}

		strcpy(((CQQClientApp*)AfxGetApp())->QQ, CStringA(UserName));
		MessageBox(_T("登陆成功"), NULL, MB_OK);

	}
	else
	{
		MessageBox(_T("连接失败"), NULL, MB_OK);
	}

}