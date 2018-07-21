#if !defined(AFX_SHIN_HOTBUTTON_H__193C0EC6_67C0_4113_A458_C91C3DDE5389__INCLUDED_)
#define AFX_SHIN_HOTBUTTON_H__193C0EC6_67C0_4113_A458_C91C3DDE5389__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Shin_HotButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Shin_HotButton window

class AFX_EXT_CLASS Shin_HotButton : public CButton
{
// Construction
public:
	Shin_HotButton();

// Attributes
public:
   CBitmap m_Bitmap;
   CBitmap m_HotBitmap;
   BOOL m_IsPressed;
   BOOL m_IsInRect;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Shin_HotButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawButton();
	void SetCBitmap(CBitmap *Bitmap, CBitmap *HotBitmap);
	virtual ~Shin_HotButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(Shin_HotButton)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHIN_HOTBUTTON_H__193C0EC6_67C0_4113_A458_C91C3DDE5389__INCLUDED_)
