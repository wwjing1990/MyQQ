
// QQClientDlg.h: 头文件
//
//#include "code/Shin_TransparentButton.h"

#pragma once
#include "UserList.h"
#include "NewSock.h"
#include "afxcmn.h"


//线程函数声明
DWORD _stdcall ThreadProc(LPVOID lpParameter);

// CQQClientDlg 对话框
class CQQClientDlg : public CDialog
{
// 构造
public:
	CQQClientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QQCLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


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
	Shin_TransparentButton m_Name; //透明按钮
	Shin_Title m_Title;				//标题栏对象
	Shin_HotButton m_HotButton[7]; //热点按钮//
	
	CPtrList m_MsgList;//消息指针列表
	HANDLE m_Thread;//线程句柄
	CUserList* m_UserList;//对话框对象 用于显示好友列表

	CImageList m_TabImageList; //标签控件位图列表
	CTabCtrl	m_Tab;//标签控件
	CEdit	m_Search;//搜索好友

};
