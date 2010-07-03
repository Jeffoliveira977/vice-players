// launch3Dlg.h : header file
//

#include "afxwin.h"
#if !defined(AFX_LAUNCH3DLG_H__D2D144EB_AE74_4340_9B02_485CDD4A8666__INCLUDED_)
#define AFX_LAUNCH3DLG_H__D2D144EB_AE74_4340_9B02_485CDD4A8666__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLaunch3Dlg dialog

class CLaunch3Dlg : public CDialog
{
// Construction
public:
	CLaunch3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLaunch3Dlg)
	enum { IDD = IDD_LAUNCH3_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLaunch3Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLaunch3Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangeNick();
	afx_msg void OnLaunch();
	afx_msg void OnButton2();
	afx_msg void OnHelpButton();
	afx_msg void OnStartServer();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CButton m_windowedCheckBox;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAUNCH3DLG_H__D2D144EB_AE74_4340_9B02_485CDD4A8666__INCLUDED_)
