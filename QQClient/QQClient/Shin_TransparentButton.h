#if !defined(AFX_SHIN_TRANSPARENTBUTTON_H__D60949B4_4488_4F6B_AF72_4F5FFDD6AF98__INCLUDED_)
#define AFX_SHIN_TRANSPARENTBUTTON_H__D60949B4_4488_4F6B_AF72_4F5FFDD6AF98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Shin_TransparentButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Shin_TransparentButton window

class AFX_EXT_CLASS Shin_TransparentButton : public CButton
{
// Construction
public:
	Shin_TransparentButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Shin_TransparentButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL m_IsInRect;
	BOOL m_IsPressed;
	void SetActiveTextColor(COLORREF color);///设置活动按钮颜色//
	void DrawText();//画画按钮文字//
	virtual ~Shin_TransparentButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(Shin_TransparentButton)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	COLORREF m_clActiveText;//活动按钮颜色
	COLORREF m_clNormalText;//正常按钮颜色
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHIN_TRANSPARENTBUTTON_H__D60949B4_4488_4F6B_AF72_4F5FFDD6AF98__INCLUDED_)
