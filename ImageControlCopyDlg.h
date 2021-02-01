#pragma once
#include "resource.h"
#include "ResizableDlg.h"
#include "ImageCtrl.h"
#include "ResourceList.h"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual BOOL OnInitDialog();
};

class CImageControlCopyDlg : public CResizableDlg
{
public:
	CImageControlCopyDlg(CWnd* pParent = NULL);	// standard constructor
	enum { IDD = IDD_IMAGECONTROLCOPY_DIALOG };

private:
	CResourceList m_rl;                  // Resource list.          
	CArray<tResourceLCID*>* m_pRes;      // Array of resource "Locale Culture Identifier"-s from National Language Support Information (https://msdn.microsoft.com/en-us/goglobal/bb896001.aspx).
	CString m_resFilePath;               // Resource file path.
	bool m_isOnEnChangeEditWidthHeight;  // Enabled/disabled OnEnChangeEditWidth() and OnEnChangeEditHeight() events.

	CImageCtrl m_image;                  // Image control.
	HICON m_hIcon;
	CMFCButton m_btnFileOpen;
	CToolTipCtrl m_toolTip;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);

	afx_msg void OnBnClickedButtonLoadimage();
	afx_msg void OnCbnSelchangeComboSizetype();
	afx_msg void OnEnChangeEditWidth();
	afx_msg void OnEnChangeEditHeight();
	afx_msg void OnBnClickedCheckMar();
	afx_msg void OnCbnSelchangeComboAlignment();
	afx_msg void OnBnClickedCheckPan();
	afx_msg void OnBnClickedCheckZoom();
	afx_msg LRESULT OnCustom(WPARAM wparam, LPARAM lparam);
	afx_msg BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()
};