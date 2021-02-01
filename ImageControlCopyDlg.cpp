#pragma once
#include "pch.h"
#include "ImageControlCopyDlg.h"

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

BOOL CAboutDlg::OnInitDialog()
{
	CString buff;

	CDialogEx::OnInitDialog();

	buff.LoadString(IDS_STRING001); SetWindowText(buff);
	buff.LoadString(IDS_STRING002); GetDlgItem(IDC_GROUP_AUTHOR)->SetWindowText(buff);
	buff.LoadString(IDS_STRING003); GetDlgItem(IDC_STATIC_VERSION)->SetWindowText(buff);
	buff.LoadString(IDS_STRING004); GetDlgItem(IDC_GROUP_AKNOWLEDGMENTS)->SetWindowText(buff);
	buff.LoadString(IDS_STRING005); GetDlgItem(IDC_STATIC1)->SetWindowText(buff);
	buff.LoadString(IDS_STRING006); GetDlgItem(IDC_STATIC2)->SetWindowText(buff);
	buff.LoadString(IDS_STRING007); GetDlgItem(IDC_STATIC3)->SetWindowText(buff);
	buff.LoadString(IDS_STRING008); GetDlgItem(IDC_STATIC4)->SetWindowText(buff);
	buff.LoadString(IDS_STRING009); GetDlgItem(IDC_STATIC5)->SetWindowText(buff);
	buff.LoadString(IDS_STRING010); GetDlgItem(IDOK)->SetWindowText(buff);

	return TRUE;
}

CImageControlCopyDlg::CImageControlCopyDlg(CWnd* pParent /*=NULL*/)
	: CResizableDlg(CImageControlCopyDlg::IDD, 400, 490, pParent), m_pRes(NULL), m_isOnEnChangeEditWidthHeight(true)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_rl.setResourceType(CResourceList::resourceType::RESOURCE_IMAGE); // m_rl.setResourceType((UINT)RT_GROUP_ICON);
}

void CImageControlCopyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_IMAGEFRAME, m_image);
}

BEGIN_MESSAGE_MAP(CImageControlCopyDlg, CResizableDlg)
	ON_WM_SIZE()
	ON_MESSAGE(WM_APP + 1, OnCustom)
	ON_BN_CLICKED(IDC_BUTTON_LOADIMAGE, &CImageControlCopyDlg::OnBnClickedButtonLoadimage)
	ON_BN_CLICKED(IDC_CHECK_PAN, &CImageControlCopyDlg::OnBnClickedCheckPan)
	ON_BN_CLICKED(IDC_CHECK_ZOOM, &CImageControlCopyDlg::OnBnClickedCheckZoom)
	ON_BN_CLICKED(IDC_CHECK_MAR, &CImageControlCopyDlg::OnBnClickedCheckMar)
	ON_CBN_SELCHANGE(IDC_COMBO_ALIGNMENT, &CImageControlCopyDlg::OnCbnSelchangeComboAlignment)
	ON_CBN_SELCHANGE(IDC_COMBO_SIZETYPE, &CImageControlCopyDlg::OnCbnSelchangeComboSizetype)
	ON_EN_CHANGE(IDC_EDIT_WIDTH, &CImageControlCopyDlg::OnEnChangeEditWidth)
	ON_EN_CHANGE(IDC_EDIT_HEIGHT, &CImageControlCopyDlg::OnEnChangeEditHeight)
END_MESSAGE_MAP()

BOOL CImageControlCopyDlg::OnInitDialog()
{
	CString buff;

	moveResizeControl(IDC_STATIC_IMAGEFRAME, tControl::anchor::TOP_LEFT, 0, 0, 1, 1);
	moveResizeControl(IDC_BUTTON_LOADIMAGE, tControl::anchor::TOP_LEFT, 1, 0, 0, 0);
	moveResizeControl(IDC_STATIC_SIZETYPE, tControl::anchor::TOP_LEFT, 1, 0, 0, 0);
	moveResizeControl(IDC_COMBO_SIZETYPE, tControl::anchor::TOP_LEFT, 1, 0, 0, 0);
	moveResizeControl(IDC_STATIC_WIDTH, tControl::anchor::TOP_LEFT, 1, 0, 0, 0);
	moveResizeControl(IDC_EDIT_WIDTH, tControl::anchor::TOP_LEFT, 1, 0, 0, 0);
	moveResizeControl(IDC_STATIC_WIDTHUNITS, tControl::anchor::TOP_LEFT, 1, 0, 0, 0);
	moveResizeControl(IDC_STATIC_HEIGHT, tControl::anchor::TOP_LEFT, 1, 0, 0, 0);
	moveResizeControl(IDC_EDIT_HEIGHT, tControl::anchor::TOP_LEFT, 1, 0, 0, 0);
	moveResizeControl(IDC_STATIC_HEIGHTUNITS, tControl::anchor::TOP_LEFT, 1, 0, 0, 0);
	moveResizeControl(IDC_CHECK_MAR, tControl::anchor::TOP_LEFT, 1, 0, 0, 0);
	moveResizeControl(IDC_STATIC_ALIGNMENT, tControl::anchor::TOP_LEFT, 1, 0, 0, 0);
	moveResizeControl(IDC_COMBO_ALIGNMENT, tControl::anchor::TOP_LEFT, 1, 0, 0, 0);
	moveResizeControl(IDC_CHECK_PAN, tControl::anchor::TOP_LEFT, 1, 0, 0, 0);
	moveResizeControl(IDC_CHECK_ZOOM, tControl::anchor::TOP_LEFT, 1, 0, 0, 0);
	moveResizeControl(IDOK, tControl::anchor::TOP_LEFT, 1, 1, 0, 0);

	CResizableDlg::OnInitDialog();

	SetIcon(m_hIcon, TRUE); 
	SetIcon(m_hIcon, FALSE);

	buff.LoadString(IDS_STRING101); SetWindowText(buff);
	buff.LoadString(IDS_STRING115); GetDlgItem(IDC_BUTTON_LOADIMAGE)->SetWindowText(buff);
	buff.LoadString(IDS_STRING117); GetDlgItem(IDC_STATIC_SIZETYPE)->SetWindowText(buff);
	buff.LoadString(IDS_STRING121); GetDlgItem(IDC_STATIC_WIDTH)->SetWindowText(buff);
	buff.LoadString(IDS_STRING140); GetDlgItem(IDC_STATIC_WIDTHUNITS)->SetWindowText(buff);
	buff.LoadString(IDS_STRING122); GetDlgItem(IDC_STATIC_HEIGHT)->SetWindowText(buff);
	buff.LoadString(IDS_STRING140); GetDlgItem(IDC_STATIC_HEIGHTUNITS)->SetWindowText(buff);
	buff.LoadString(IDS_STRING123); GetDlgItem(IDC_CHECK_MAR)->SetWindowText(buff);
	buff.LoadString(IDS_STRING124); GetDlgItem(IDC_STATIC_ALIGNMENT)->SetWindowText(buff);
	buff.LoadString(IDS_STRING134); GetDlgItem(IDC_CHECK_PAN)->SetWindowText(buff);
	buff.LoadString(IDS_STRING135); GetDlgItem(IDC_CHECK_ZOOM)->SetWindowText(buff);
	buff.LoadString(IDS_STRING138); GetDlgItem(IDOK)->SetWindowText(buff);

	m_toolTip.Create(this);
	m_toolTip.Activate(TRUE);

	buff.LoadString(IDS_STRING118); ((CComboBox*)GetDlgItem(IDC_COMBO_SIZETYPE))->AddString(buff);   // Original
	buff.LoadString(IDS_STRING119); ((CComboBox*)GetDlgItem(IDC_COMBO_SIZETYPE))->AddString(buff);   // Scale to fit
	buff.LoadString(IDS_STRING120); ((CComboBox*)GetDlgItem(IDC_COMBO_SIZETYPE))->AddString(buff);   // Custom
	((CComboBox*)GetDlgItem(IDC_COMBO_SIZETYPE))->SetCurSel(0);
	OnCbnSelchangeComboSizetype();

	((CButton*)GetDlgItem(IDC_CHECK_MAR))->SetCheck(TRUE);
	OnBnClickedCheckMar();

	buff.LoadString(IDS_STRING125); ((CComboBox*)GetDlgItem(IDC_COMBO_ALIGNMENT))->AddString(buff);  // Top-left
	buff.LoadString(IDS_STRING126); ((CComboBox*)GetDlgItem(IDC_COMBO_ALIGNMENT))->AddString(buff);  // Top-center
	buff.LoadString(IDS_STRING127); ((CComboBox*)GetDlgItem(IDC_COMBO_ALIGNMENT))->AddString(buff);  // Top-right
	buff.LoadString(IDS_STRING128); ((CComboBox*)GetDlgItem(IDC_COMBO_ALIGNMENT))->AddString(buff);  // Middle-left
	buff.LoadString(IDS_STRING129); ((CComboBox*)GetDlgItem(IDC_COMBO_ALIGNMENT))->AddString(buff);  // Middle-center
	buff.LoadString(IDS_STRING130); ((CComboBox*)GetDlgItem(IDC_COMBO_ALIGNMENT))->AddString(buff);  // Middle-right
	buff.LoadString(IDS_STRING131); ((CComboBox*)GetDlgItem(IDC_COMBO_ALIGNMENT))->AddString(buff);  // Bottom-left
	buff.LoadString(IDS_STRING132); ((CComboBox*)GetDlgItem(IDC_COMBO_ALIGNMENT))->AddString(buff);  // Bottom-center
	buff.LoadString(IDS_STRING133); ((CComboBox*)GetDlgItem(IDC_COMBO_ALIGNMENT))->AddString(buff);  // Bottom-right
	buff.LoadString(IDS_STRING134); ((CComboBox*)GetDlgItem(IDC_COMBO_ALIGNMENT))->SetCurSel(0);
	OnCbnSelchangeComboAlignment();

	m_image.erase();
	GetDlgItem(IDC_BUTTON_LOADIMAGE)->EnableWindow();

	//check zoom default
	((CButton*)GetDlgItem(IDC_CHECK_ZOOM))->SetCheck(TRUE);
	OnBnClickedCheckZoom();
	//check pan default
	((CButton*)GetDlgItem(IDC_CHECK_PAN))->SetCheck(TRUE);
	OnBnClickedCheckPan();


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CImageControlCopyDlg::OnSize(UINT nType, int cx, int cy)
{

}


void CImageControlCopyDlg::OnBnClickedButtonLoadimage()
{
	int i;
	IStream* pStream = NULL;
	CFile cFile;
	BYTE* pBuffer = NULL;
	DWORD dwRead;
	CString buff;
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_CREATEPROMPT | OFN_PATHMUSTEXIST, _T("All Image Files (*.bmp;*.dib;*.jpg;*.jpeg;*.jpe;*.jfif;*.gif;*.tif;*.tiff;*.png;*.ico;*.wmf;*.emf)|*.bmp;*.dib;*.jpg;*.jpeg;*.jpe;*.jfif;*.gif;*.tif;*.tiff;*.png;*.ico;*.wmf;*.emf|Windows Bitmap (*.bmp;*.dib)|*.bmp;*.dib|JPEG Compressed Image (*.jpg;*.jpeg;*.jpe;*.jfif)|*.jpg;*.jpeg;*.jpe;*.jfif|Graphics Interchange Format (*.gif)|*.gif|Tagged Image File Format (*.tif;*.tiff)|*.tif;*.tiff|Portable Network Graphics (*.png)|*.png|Icon (*.ico)|*.ico|Windows Meta File (*.wmf)|*.wmf|Windows Enhanced Meta File (*.emf)|*.emf||"), this);

	if (fileDlg.DoModal() == IDOK) m_image.load(fileDlg.GetPathName());
	GetDlgItem(IDC_EDIT_FILEPATH)->SetWindowTextW(fileDlg.GetPathName()); //경로출력
	GetDlgItem(IDC_EDIT_FILENAME)->SetWindowTextW(PathFindFileName(fileDlg.GetPathName()));

	m_isOnEnChangeEditWidthHeight = false;
	buff.Format(_T("%d"), (int)m_image.getWidth());
	GetDlgItem(IDC_EDIT_WIDTH)->SetWindowTextW(buff);
	buff.Format(_T("%d"), (int)m_image.getHeight());
	GetDlgItem(IDC_EDIT_HEIGHT)->SetWindowTextW(buff);
	m_isOnEnChangeEditWidthHeight = true;

	((CComboBox*)GetDlgItem(IDC_COMBO_ALIGNMENT))->SetCurSel(0);
	OnCbnSelchangeComboAlignment();
}

void CImageControlCopyDlg::OnCbnSelchangeComboSizetype()
{
	int i; CString buff; CRect rect;

	if ((i = ((CComboBox*)GetDlgItem(IDC_COMBO_SIZETYPE))->GetCurSel()) != CB_ERR)
	{
		m_image.setSizeType(i);

		m_image.update();
		m_isOnEnChangeEditWidthHeight = false;
		buff.Format(_T("%d"), (int)m_image.getWidth());
		GetDlgItem(IDC_EDIT_WIDTH)->SetWindowTextW(buff);
		buff.Format(_T("%d"), (int)m_image.getHeight());
		GetDlgItem(IDC_EDIT_HEIGHT)->SetWindowTextW(buff);
		m_isOnEnChangeEditWidthHeight = true;

		if (i == CImageCtrl::sizeType::SIZE_ORIGINAL)
		{
			GetDlgItem(IDC_EDIT_WIDTH)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_HEIGHT)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHECK_MAR)->EnableWindow(FALSE);
			GetDlgItem(IDC_COMBO_ALIGNMENT)->EnableWindow();
		}
		else if (i == CImageCtrl::sizeType::SIZE_SCALETOFIT)
		{
			if (!m_image.isImageShown())
			{
				GetDlgItem(IDC_STATIC_IMAGEFRAME)->GetClientRect(rect);
				m_image.setWidth(rect.Width()); 
				m_image.setHeight(rect.Height());
				m_isOnEnChangeEditWidthHeight = false;
				buff.Format(_T("%d"), rect.Width());
				GetDlgItem(IDC_EDIT_WIDTH)->SetWindowText(buff);
				buff.Format(_T("%d"), rect.Height());
				GetDlgItem(IDC_EDIT_HEIGHT)->SetWindowText(buff);
				m_isOnEnChangeEditWidthHeight = true;
			}
			GetDlgItem(IDC_EDIT_WIDTH)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT_HEIGHT)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHECK_MAR)->EnableWindow();
			GetDlgItem(IDC_COMBO_ALIGNMENT)->EnableWindow(((CButton*)GetDlgItem(IDC_CHECK_MAR))->GetCheck());
		}
		else if (i == CImageCtrl::sizeType::SIZE_CUSTOM)
		{
			GetDlgItem(IDC_EDIT_WIDTH)->EnableWindow();
			GetDlgItem(IDC_EDIT_HEIGHT)->EnableWindow();
			GetDlgItem(IDC_CHECK_MAR)->EnableWindow();
			GetDlgItem(IDC_COMBO_ALIGNMENT)->EnableWindow();
		}
	}
}

void CImageControlCopyDlg::OnEnChangeEditWidth()
{
	int i, j; double ch, cw; CString buff;

	if (m_isOnEnChangeEditWidthHeight)
	{
		GetDlgItem(IDC_EDIT_WIDTH)->GetWindowText(buff);
		if ((cw = _wtof(buff)) > 99999 + 1e-6)
		{
			buff.LoadString(IDS_STRING141);
			AfxMessageBox(buff, MB_OK | MB_ICONINFORMATION);
			m_isOnEnChangeEditWidthHeight = false; buff.Format(_T("%d"), (int)m_image.getWidth());
			GetDlgItem(IDC_EDIT_WIDTH)->SetWindowText(buff);
			((CEdit*)GetDlgItem(IDC_EDIT_WIDTH))->SetSel(0, -1);
			m_isOnEnChangeEditWidthHeight = true;
		}
		else
			if (((CButton*)GetDlgItem(IDC_CHECK_MAR))->GetCheck())
			{
				if ((ch = cw * m_image.getAspectRatio()) > 99999 + 1e-6)
				{
					buff.LoadString(IDS_STRING141);
					AfxMessageBox(buff, MB_OK | MB_ICONINFORMATION);
					m_isOnEnChangeEditWidthHeight = false; 
					buff.Format(_T("%d"), (int)m_image.getWidth());
					GetDlgItem(IDC_EDIT_WIDTH)->SetWindowText(buff);
					((CEdit*)GetDlgItem(IDC_EDIT_WIDTH))->SetSel(0, -1);
					buff.Format(_T("%d"), (int)m_image.getHeight());
					GetDlgItem(IDC_EDIT_HEIGHT)->SetWindowText(buff);
					m_isOnEnChangeEditWidthHeight = true;
				}
				else
				{
					m_image.setWidth(cw); m_image.setHeight(ch);
					m_isOnEnChangeEditWidthHeight = false; 
					buff.Format(_T("%d"), (int)m_image.getHeight());
					GetDlgItem(IDC_EDIT_HEIGHT)->SetWindowText(buff); 
					m_isOnEnChangeEditWidthHeight = true;
					m_image.update();
				}
			}
			else
			{
				m_image.setWidth(cw);
				m_image.update();
			}
	}
}

void CImageControlCopyDlg::OnEnChangeEditHeight()
{
	int i, j; double ch, cw; CString buff;

	if (m_isOnEnChangeEditWidthHeight)
	{
		GetDlgItem(IDC_EDIT_HEIGHT)->GetWindowText(buff);
		if ((ch = _wtof(buff)) > 99999 + 1e-6)
		{
			buff.LoadString(IDS_STRING141);
			AfxMessageBox(buff, MB_OK | MB_ICONINFORMATION);
			m_isOnEnChangeEditWidthHeight = false;
			buff.Format(_T("%d"), (int)m_image.getHeight());
			GetDlgItem(IDC_EDIT_HEIGHT)->SetWindowText(buff);
			((CEdit*)GetDlgItem(IDC_EDIT_HEIGHT))->SetSel(0, -1);
			m_isOnEnChangeEditWidthHeight = true;
		}
		else
			if (((CButton*)GetDlgItem(IDC_CHECK_MAR))->GetCheck())
			{
				if ((cw = (ch / m_image.getAspectRatio())) > 99999 + 1e-6)
				{
					buff.LoadString(IDS_STRING141);
					AfxMessageBox(buff, MB_OK | MB_ICONINFORMATION);
					m_isOnEnChangeEditWidthHeight = false;
					buff.Format(_T("%d"), (int)m_image.getHeight());
					GetDlgItem(IDC_EDIT_HEIGHT)->SetWindowText(buff);
					((CEdit*)GetDlgItem(IDC_EDIT_HEIGHT))->SetSel(0, -1);
					buff.Format(_T("%d"), (int)m_image.getWidth());
					GetDlgItem(IDC_EDIT_WIDTH)->SetWindowText(buff);
					m_isOnEnChangeEditWidthHeight = true;
				}
				else
				{
					m_image.setHeight(ch);
					m_image.setWidth(cw);
					m_isOnEnChangeEditWidthHeight = false;
					buff.Format(_T("%d"), (int)m_image.getWidth());
					GetDlgItem(IDC_EDIT_WIDTH)->SetWindowText(buff);
					m_isOnEnChangeEditWidthHeight = true;
					m_image.update();
				}
			}
			else
			{
				m_image.setHeight(ch);
				m_image.update();
			}
	}
}

void CImageControlCopyDlg::OnBnClickedCheckMar()
{
	BOOL check; CString buff;

	m_image.setMaintainAspectRatio((check = ((CButton*)GetDlgItem(IDC_CHECK_MAR))->GetCheck()) > 0);
	if (((CComboBox*)GetDlgItem(IDC_COMBO_SIZETYPE))->GetCurSel() == CImageCtrl::sizeType::SIZE_SCALETOFIT)
		GetDlgItem(IDC_COMBO_ALIGNMENT)->EnableWindow(check);

	m_image.update(); if (!m_image.isImageShown()) OnEnChangeEditWidth();
	m_isOnEnChangeEditWidthHeight = false;
	buff.Format(_T("%d"), (int)m_image.getHeight()); GetDlgItem(IDC_EDIT_HEIGHT)->SetWindowText(buff);
	buff.Format(_T("%d"), (int)m_image.getWidth()); GetDlgItem(IDC_EDIT_WIDTH)->SetWindowText(buff);
	m_isOnEnChangeEditWidthHeight = true;
}

void CImageControlCopyDlg::OnCbnSelchangeComboAlignment()
{
	int i;

	if ((i = ((CComboBox*)GetDlgItem(IDC_COMBO_ALIGNMENT))->GetCurSel()) != CB_ERR) m_image.setAllignmentType(i);
	m_image.update();
}

void CImageControlCopyDlg::OnBnClickedCheckPan()
{
	m_image.setPanMode(((CButton*)GetDlgItem(IDC_CHECK_PAN))->GetCheck() > 0);
}

void CImageControlCopyDlg::OnBnClickedCheckZoom()
{
	m_image.setZoomMode(((CButton*)GetDlgItem(IDC_CHECK_ZOOM))->GetCheck() > 0);
}

LRESULT CImageControlCopyDlg::OnCustom(WPARAM wparam, LPARAM lparam)
{
	CString buff;

	if (wparam == 12345 && lparam == 0) // ZOOM action.
	{
		m_isOnEnChangeEditWidthHeight = false;
		buff.Format(_T("%d"), (int)m_image.getWidth()); 
		GetDlgItem(IDC_EDIT_WIDTH)->SetWindowText(buff);
		buff.Format(_T("%d"), (int)m_image.getHeight()); 
		GetDlgItem(IDC_EDIT_HEIGHT)->SetWindowText(buff);
		m_isOnEnChangeEditWidthHeight = true;
	}

	return 0;
}

BOOL CImageControlCopyDlg::PreTranslateMessage(MSG* pMsg)
{
	CString buff;

	m_toolTip.RelayEvent(pMsg);

	return CDialog::PreTranslateMessage(pMsg);
}

