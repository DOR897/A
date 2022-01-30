
// NEWMFCDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "NEWMFC.h"
#include "NEWMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About
int deps = 0;
int landings = 0;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CNEWMFCDlg dialog



CNEWMFCDlg::CNEWMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NEWMFC_DIALOG, pParent)
	, Planes_Number(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNEWMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Planes_Number);
}

BEGIN_MESSAGE_MAP(CNEWMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CNEWMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CNEWMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CNEWMFCDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CNEWMFCDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CNEWMFCDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CNEWMFCDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CNEWMFCDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON11, &CNEWMFCDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON10, &CNEWMFCDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON9, &CNEWMFCDlg::OnBnClickedButton9)
	ON_EN_CHANGE(IDC_EDIT1, &CNEWMFCDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON12, &CNEWMFCDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON3, &CNEWMFCDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CNEWMFCDlg message handlers

BOOL CNEWMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	UpdateData(TRUE);
	Planes_Number.Format(_T(
		"Super Tanks :  %d\r\n"
		"Solo Planes: %d\r\n"
		"Boeings : %d\r\n"
		"F16s : %d\r\n"
		"\r\nplanes in total: %d\r\n"),
		SuperTank::Supers, SoloPlane::Solos, Boeing::PassPlanes, F16::Fighters, planes.GetSize());
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNEWMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNEWMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNEWMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//Departure Button;
void CNEWMFCDlg::OnBnClickedButton1()
{
	CString details;
	details.Format(_T("%d"), deps);
	MessageBox(details, L"Number Of Departures today right now :");
	// TODO: Add your control notification handler code here
	//MessageBox(_T("Plane is taking off !\nPlease fasten your seatbelt and enjoy your time in the air"));
	//details.Format(_T("Number Of Departures are %d", deps)); // not finished

	
}

//Arrivals Button
void CNEWMFCDlg::OnBnClickedButton2()
{
	CString details;
	details.Format(_T("%d"), landings);
	MessageBox(details, L" Number Of Arrivals right now is :");
	// TODO: Add your control notification handler code here
	//details.Format(_T("Arrivals in the past 24 hours is : %d", ) ,landings); // not finished

}
//
////planes in air button
//void CNEWMFCDlg::OnBnClickedButton3()
//{
//	
//	// TODO: Add your control notification handler code here
//	CString details;
//	Planes_Number;
//	details.Format(_T("Right Now There Are %d Planes (from all kinds) In The Air", )); // not finished
//	
//}

// New SuperTank Task
void CNEWMFCDlg::OnBnClickedButton4()
{
	planes.Add(new SuperTank());
	SuperTank::Supers++;
	deps++;
	UpdateData(TRUE);
	Planes_Number.Format(_T(
		"Super Tanks :  %d\r\n"
		"Solo Planes: %d\r\n"
		"Boeings : %d\r\n"
		"F16s : %d\r\n"
		"\r\nplanes in total: %d\r\n"),
		SuperTank::Supers, SoloPlane::Solos, Boeing::PassPlanes, F16::Fighters, planes.GetSize());
	UpdateData(FALSE);
	MessageBox(L"A SuperTank Is Now Taking Off To A New Mission !");
	// TODO: Add your control notification handler code here
}

//New F16 Task
void CNEWMFCDlg::OnBnClickedButton5()
{
	planes.Add(new F16());
	F16::Fighters++;
	deps++;
	UpdateData(TRUE);
	Planes_Number.Format(_T(
		"Super Tanks :  %d\r\n"
		"Solo Planes: %d\r\n"
		"Boeings : %d\r\n"
		"F16s : %d\r\n"
		"\r\nplanes in total: %d\r\n"),
		SuperTank::Supers, SoloPlane::Solos, Boeing::PassPlanes, F16::Fighters, planes.GetSize());
	UpdateData(FALSE);
	MessageBox(L"F16 Is Now Heading To A New Target !");
	// TODO: Add your control notification handler code here
}

//New Solo Plane Flight
void CNEWMFCDlg::OnBnClickedButton6()
{
	planes.Add(new SoloPlane());
	SoloPlane::Solos++;
	deps++;
	UpdateData(TRUE);
	Planes_Number.Format(_T(
		"Super Tanks :  %d\r\n"
		"Solo Planes: %d\r\n"
		"Boeings : %d\r\n"
		"F16s : %d\r\n"
		"\r\nplanes in total: %d\r\n"),
		SuperTank::Supers, SoloPlane::Solos, Boeing::PassPlanes, F16::Fighters, planes.GetSize());
	UpdateData(FALSE);
	MessageBox(L"A New SoloPlane Is Taking Off !\n");
	
	// TODO: Add your control notification handler code here
}

// New Passengers Flight
void CNEWMFCDlg::OnBnClickedButton7()
{ 
	planes.Add(new Boeing());
	Boeing::PassPlanes++;
	deps++;
	UpdateData(TRUE);
	Planes_Number.Format(_T(
		"Super Tanks :  %d\r\n"
		"Solo Planes: %d\r\n"
		"Boeings : %d\r\n"
		"F16s : %d\r\n"
		"\r\nplanes in total: %d\r\n"),
		SuperTank::Supers, SoloPlane::Solos, Boeing::PassPlanes, F16::Fighters, planes.GetSize());
	UpdateData(FALSE);
	MessageBox(L"A New Passengers Flight Is Taking Off !\nPlease Fasten Your Seat-Belts And Enjoy Your Flight");
	// TODO: Add your control notification handler code here

}

// new incoming supertank
void CNEWMFCDlg::OnBnClickedButton8()
{
	int i;
	if (SuperTank::Supers == 0)
		MessageBox(L"There Are No SuperTanks In the Airport flight area!");

	else
	{
		
		for (i = planes.GetSize() - 1; i >= 0; i--)
		{		
			if (planes.ElementAt(i)->isType() == 1)
			{
				planes.RemoveAt(i, 1);
				SuperTank::Supers--;
				break;
			}
		}
	}
	UpdateData(TRUE);
	Planes_Number.Format(_T(
		"Super Tanks :  %d\r\n"
		"Solo Planes: %d\r\n"
		"Boeings : %d\r\n"
		"F16s : %d\r\n"
		"\r\nplanes in total: %d\r\n"),
		SuperTank::Supers, SoloPlane::Solos, Boeing::PassPlanes, F16::Fighters, planes.GetSize());
	UpdateData(FALSE);
	landings++;
	MessageBox(L"A SuperTank Has Returned From Its Mission !");
	
	// TODO: Add your control notification handler code here
}

// incoming Boieng 
void CNEWMFCDlg::OnBnClickedButton11()
{

	int i;
	if (Boeing::PassPlanes == 0)
		MessageBox(L"There Are No Boeings In the Airport flight area!");

	else
	{
		for (i = planes.GetSize() - 1; i >= 0; i--)
		{
			if (planes.ElementAt(i)->isType() == 4)
			{
				planes.RemoveAt(i, 1);
				Boeing::PassPlanes--;
				break;
			}
		}
	}
	UpdateData(TRUE);
	Planes_Number.Format(_T(
		"Super Tanks :  %d\r\n"
		"Solo Planes: %d\r\n"
		"Boeings : %d\r\n"
		"F16s : %d\r\n"
		"\r\nplanes in total: %d\r\n"),
		SuperTank::Supers, SoloPlane::Solos, Boeing::PassPlanes, F16::Fighters, planes.GetSize());
	UpdateData(FALSE);
	landings++;
	MessageBox(L"A Boeing Has Returned From Its Mission !");
	// TODO: Add your control notification handler code here
}

// Incoming Solo Flight
void CNEWMFCDlg::OnBnClickedButton10()
{
	int i;
	if (SoloPlane::Solos == 0)
		MessageBox(L"There Are No SoloPlaness In the Airport flight area!\n");

	
	else  
	{
		
		for (i = planes.GetSize() - 1; i >= 0; i--)
		{
			if (planes.ElementAt(i)->isType() == 2)
			{
				planes.RemoveAt(i, 1);
				SoloPlane::Solos--;
				break;
			}
		}
		
	}
	
		
	

	UpdateData(TRUE);
	Planes_Number.Format(_T(
		"Super Tanks :  %d\r\n"
		"Solo Planes: %d\r\n"
		"Boeings : %d\r\n"
		"F16s : %d\r\n"
		"\r\nplanes in total: %d\r\n"),
		SuperTank::Supers, SoloPlane::Solos, Boeing::PassPlanes, F16::Fighters, planes.GetSize());
	UpdateData(FALSE);
	landings++;
	MessageBox(L" A Solo Plane Has Landed In Our Air - Port");
	
	// TODO: Add your control notification handler code here
}

//incoming F16
void CNEWMFCDlg::OnBnClickedButton9()
{
	int i;
	if (F16::Fighters == 0)
		MessageBox(L"There Are No F16s In the Airport flight area !\n");

	else
	{
		for (i = planes.GetSize() - 1; i >= 0; i--)
		{
			if (planes.ElementAt(i)->isType() == 3)
			{
			    planes.RemoveAt(i, 1);
				F16::Fighters--;
				break;
			}
		}
	}
	UpdateData(TRUE);
	Planes_Number.Format(_T(
		"Super Tanks :  %d\r\n"
		"Solo Planes: %d\r\n"
		"Boeings : %d\r\n"
		"F16s : %d\r\n"
		"\r\nplanes in total: %d\r\n"),
		SuperTank::Supers, SoloPlane::Solos, Boeing::PassPlanes, F16::Fighters, planes.GetSize());
	UpdateData(FALSE);
	landings++;
	MessageBox(L" F16 Has Returned From Its Mission");
	// TODO: Add your control notification handler code here
}


void CNEWMFCDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CNEWMFCDlg::OnBnClickedButton12()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, _T(".Planes"), NULL, 0, _T("Planes (*.Planes)|*.Planes|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		planes.Serialize(ar);
		 /*CTypedPtrArray<CObArray, Plane*> savedplanes;
		savedplanes.Serialize(ar);
		planes.Append(savedplanes);*/
		ar.Close();
		file.Close();


	}
	
}




void CNEWMFCDlg::OnBnClickedButton3()
{
	CFileDialog dlg(FALSE, _T(".Planes"), NULL, 0, _T("Planes (*.Planes)|*.Planes|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		planes.Serialize(ar);
		ar.Close();
		file.Close();
	}
	
}
	// TODO: Add your control notification handler code here

