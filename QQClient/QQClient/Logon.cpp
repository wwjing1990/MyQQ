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

	m_Socket=&((CQQClientApp*)AfxGetApp())->m_Socket;//��ȡȫ�ֵ��׽���ָ��//
    this->SetIcon(AfxGetApp()->LoadIcon(IDI_QQ),TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/* ��ʱ��֪�����ã�
void CLogon::OnButton3() 
{
	// TODO: Add your control notification handler code here
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(),
		     SND_ASYNC|SND_RESOURCE|SND_NODEFAULT);
	if(m_Extend)
	{
		this->MoveWindow(470,260,327,230,1);
		GetDlgItem(IDC_EXTEND)->SetWindowText("�߼����á�");		
		m_Extend=FALSE;
	}
	else
	{
		this->MoveWindow(470,260,327,390,1);
		GetDlgItem(IDC_EXTEND)->SetWindowText("�߼����á�");
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


//����QQ��
void CLogon::OnBnClickedBtnApply()
{
	// TODO: Add your control notification handler code here
	PROCESS_INFORMATION pi;//����������Ϣ���
	STARTUPINFO si; //ָ���½��̵�����������
	//��ʼ������
	memset(&si,0,sizeof(si));
	si.cb=sizeof(si);			//ָ���ýṹ��С
	si.wShowWindow=SW_SHOW;		//�´��ڵ���ʾ״̬
	si.dwFlags=STARTF_USESHOWWINDOW;//�������ڱ�־
	//�����������
	TCHAR cmd[256] = _T("C:\\Program Files\\Internet Explorer\\iexplore.exe  http://www.baidu.com");  //�����ⲿ������
	BOOL fRet = CreateProcess(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	if(!fRet)
	{//����ʧ�ܣ���ʾ������Ϣ
		MessageBox(L"��֣��򲻿������!�������޷����",L"������ʾ", MB_OK);
		return;
	}
}

//�һ�����
void CLogon::OnBnClickedBtnFindpsw()
{
	// TODO: Add your control notification handler code here
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	//��ʼ������
	memset(&si,0,sizeof(si));
	si.cb=sizeof(si);
	si.wShowWindow=SW_SHOW;
	si.dwFlags=STARTF_USESHOWWINDOW;
	//������������
	TCHAR cmd[256] = _T("C:\\Program Files\\Internet Explorer\\iexplore.exe  http://www.qq.com");
	BOOL fRet=CreateProcess(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

	if(!fRet)
	{//����ʧ�ܣ���ʾ������Ϣ
		MessageBox(L"��֣��򲻿�������!�������޷����",L"������ʾ", MB_OK);
		return;
	}	
}


//ȡ����½
void CLogon::OnBnClickedBtnCancel()
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}


//logon��½OK
void CLogon::lg()
{
	this->OnOK();
}


void CLogon::OnBnClickedExtend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CLogon::OnBnClickedBtnTest()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


//��½
void CLogon::OnBnClickedBtnLogon()
{
	// TODO: Add your control notification handler code here
	CString UserName, PassWord, m_Str;
	m_UserName.GetWindowText(UserName);
	m_PassWord.GetWindowText(PassWord);
	if (UserName.IsEmpty() || PassWord.IsEmpty())
	{
		MessageBox(_T("�û��������벻��Ϊ��!"));
		return;
	}

	UINT port;
	port = atoi("1000");
	m_Socket->Create();//�����׽���//
	if (m_Socket->Connect(_T("127.0.0.1"), port))
	{
		m_Str += "logon,UserName";
		m_Str += UserName;
		m_Str += "PassWord";
		m_Str += PassWord;
		//��һ���Ѿ����ӵ�socket�������ݣ�����޴��󣬷���ֵΪ���������ݵ�����
		int iSend = send(*m_Socket, (CStringA)m_Str.GetBuffer(m_Str.GetLength()), m_Str.GetLength(), 0);
		if (iSend == SOCKET_ERROR)
		{
			MessageBox(_T("����ʧ��"), NULL, MB_OK);
		}

		strcpy(((CQQClientApp*)AfxGetApp())->QQ, CStringA(UserName));
		MessageBox(_T("��½�ɹ�"), NULL, MB_OK);

	}
	else
	{
		MessageBox(_T("����ʧ��"), NULL, MB_OK);
	}

}