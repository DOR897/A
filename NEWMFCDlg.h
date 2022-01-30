
// NEWMFCDlg.h : header file
//

#pragma once

#include "Plane.h"
#include "Boeing.h"
#include "F16.h"
#include "SoloPlane.h"
#include "SuperTank.h"

// CNEWMFCDlg dialog
class CNEWMFCDlg : public CDialogEx
{
// Construction
public:
	CNEWMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEWMFC_DIALOG };
#endif
	
	//main array for plane*
	CTypedPtrArray<CObArray, Plane*> planes;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton9();
	CString Planes_Number;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton3();
};
