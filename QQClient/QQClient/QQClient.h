
// QQClient.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号

//引入自定义socket类
#include "NewSock.h"

// CQQClientApp:
// 有关此类的实现，请参阅 QQClient.cpp
//

class CQQClientApp : public CWinApp
{
public:
	CNewSock m_Socket;//客户端socket套接字
	char temp[1000];
	char QQ[20];

	CQQClientApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CQQClientApp theApp;

