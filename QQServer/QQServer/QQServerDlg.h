
// QQServerDlg.h: 头文件
//

#pragma once
#include "afxwin.h"

#include "ServerSock.h"	//引入套接字类头文件

// CQQServerDlg 对话框
class CQQServerDlg : public CDialog
{
// 构造
public:
	CQQServerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QQSERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


public:
	BOOL m_State;//服务是否开启
	CPtrList m_SocketList;//套接字指针列表
	CString m_Str;//服务器日志字符串
	CServerSock m_Socket;//服务器套接字
	CTime time;//系统时间
	CString curdata;//格式化系统时间字符串


	void refurbish();//刷新
	void AcceptConnect();//连接
	void ReceiveData(CServerSock* sock);//接收数据
	void Stop(CServerSock* sock);//断开连接
	


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStart();//开启服务器
	afx_msg void OnBnClickedStop();//关闭服务器

	CEdit m_Edit;// 服务器日志
	CStatic m_ServerState;// 服务器状态
	CStatic m_Static;// 在线人数
					 
	CButton m_btnStart;// 开启服务按钮
	CButton m_btnStop;// 关闭服务按钮
};
