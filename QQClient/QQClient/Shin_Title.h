// Shin_Title.h: interface for the Shin_Title class.
//
//////////////////////////////////////////////////////////////////////


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS Shin_Title  
{
public:
	void SetHide(BOOL i);
	BOOL m_Hide;
	CFont m_Font;
	void SetText(LPCTSTR text);
	char m_Text[50];
	void MouseMove();
	void DrawTitle();
	BOOL SetBitmap(LPCTSTR Min_Normal,LPCTSTR Min_Hot,LPCTSTR Max_Normal,
		           LPCTSTR Max_Hot,LPCTSTR Close_Normal,LPCTSTR Close_Hot);
	BOOL m_MinPressed;
	BOOL m_MaxPressed;
	BOOL m_ClosePressed;
	BOOL m_MinInRect;
	BOOL m_MaxInRect;
	BOOL m_CloseInRect;
	CRect m_MaxRect;
	CRect m_MinRect;
	CRect m_CloseRect;
	CRect m_TitleRect;
	void LButtonUp();
	void LButtonDown();
	void Timer();
	BOOL Create(CWnd *wnd);
	void Message(UINT message, WPARAM wParam, LPARAM lParam);
	Shin_Title(); 
	BOOL m_TitlePressed;
	HANDLE m_Thread;
	CWnd *m_hWnd;

	CBitmap m_MinNormal;
	CBitmap m_MinHot;
	CBitmap m_MaxNormal;
    CBitmap m_MaxHot;
	CBitmap m_CloseNormal; 
	CBitmap m_CloseHot;
	int x,y;
	virtual ~Shin_Title();

};
