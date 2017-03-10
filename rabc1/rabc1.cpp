
// rabc1.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "rabc1.h"
#include "MainFrm.h"
#include "Clogin.h"
#include "Cregist.h"
#include "Caddr.h"
#include "Cload.h"
#include "Caddp.h"
#include "Csave.h"
#include "Cquanxianzhipai.h"
#include "Cquanxianchexiao.h"
#include "Cjuesezhipai.h"
#include "Cjuesechexiao.h"
#include "Caddnextr.h"
#include "Cdelnextr.h"
#include "Cdelupon.h"
#include "rabc1Doc.h"
#include "rabc1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Crabc1App

BEGIN_MESSAGE_MAP(Crabc1App, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &Crabc1App::OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
	ON_COMMAND(ID_32772, &Crabc1App::login)
	ON_COMMAND(ID_32773, &Crabc1App::regist)
	ON_COMMAND(ID_32775, &Crabc1App::addrole)
	ON_COMMAND(ID_32776, &Crabc1App::addp)
	ON_COMMAND(ID_32777, &Crabc1App::yonghujuesezhipai)
	ON_COMMAND(ID_32778, &Crabc1App::yonghujuesechexiao)
	ON_COMMAND(ID_32779, &Crabc1App::juesequanxianzhipai)
	ON_COMMAND(ID_32780, &Crabc1App::juesequanxianchexiao)
	ON_COMMAND(ID_32781, &Crabc1App::addnext)
	ON_COMMAND(ID_32782, &Crabc1App::delnext)
	ON_COMMAND(ID_32783, &Crabc1App::delupon)
	ON_COMMAND(ID_32774, &Crabc1App::save)
	ON_COMMAND(ID_32784, &Crabc1App::load)
END_MESSAGE_MAP()


// Crabc1App ����

Crabc1App::Crabc1App()
{
	m_bHiColorIcons = TRUE;

	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���:
	//     1) �����д˸������ã�������������������֧�ֲ�������������
	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("rabc1.AppID.NoVersion"));

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� Crabc1App ����

Crabc1App theApp;


// Crabc1App ��ʼ��

BOOL Crabc1App::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// ʹ�� RichEdit �ؼ���Ҫ  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(Crabc1Doc),
		RUNTIME_CLASS(CMainFrame),       // �� SDI ��ܴ���
		RUNTIME_CLASS(Crabc1View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// ������׼ shell ���DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� SDI Ӧ�ó����У���Ӧ�� ProcessShellCommand ֮����
	return TRUE;
}

int Crabc1App::ExitInstance()
{
	//TODO: �����������ӵĸ�����Դ
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// Crabc1App ��Ϣ�������


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void Crabc1App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// Crabc1App �Զ������/���淽��

void Crabc1App::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void Crabc1App::LoadCustomState()
{
}

void Crabc1App::SaveCustomState()
{
}

// Crabc1App ��Ϣ�������





void Crabc1App::login()
{
	// TODO: �ڴ���������������
	Clogin log;
	log.DoModal();
}


void Crabc1App::regist()
{
	// TODO: �ڴ���������������
	Cregist reg;
	reg.DoModal();
}


void Crabc1App::addrole()
{
	// TODO: �ڴ���������������
	Caddr ad;
	ad.DoModal();
}


void Crabc1App::addp()
{
	// TODO: �ڴ���������������
	Caddp ad;
	ad.DoModal();
}


void Crabc1App::yonghujuesezhipai()
{
	// TODO: �ڴ���������������
	Cjuesezhipai ju;
	ju.DoModal();
}


void Crabc1App::yonghujuesechexiao()
{
	// TODO: �ڴ���������������
	Cjuesechexiao ju;
	ju.DoModal();
}


void Crabc1App::juesequanxianzhipai()
{
	// TODO: �ڴ���������������
	Cquanxianzhipai qu;
	qu.DoModal();
}


void Crabc1App::juesequanxianchexiao()
{
	// TODO: �ڴ���������������
	Cquanxianchexiao qu;
	qu.DoModal();
}


void Crabc1App::addnext()
{
	// TODO: �ڴ���������������
	Caddnextr ne;
	ne.DoModal();
}


void Crabc1App::delnext()
{
	// TODO: �ڴ���������������
	Cdelnextr de;
	de.DoModal();
}


void Crabc1App::delupon()
{
	// TODO: �ڴ���������������
	Cdelupon de;
	de.DoModal();
}


void Crabc1App::save()
{
	// TODO: �ڴ���������������
	Csave sa;
	sa.DoModal();
}


void Crabc1App::load()
{
	// TODO: �ڴ���������������
	Cload lo;
	lo.DoModal();
}
