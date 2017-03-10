
// rabc1.cpp : 定义应用程序的类行为。
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
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// 标准打印设置命令
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


// Crabc1App 构造

Crabc1App::Crabc1App()
{
	m_bHiColorIcons = TRUE;

	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// 如果应用程序是利用公共语言运行时支持(/clr)构建的，则:
	//     1) 必须有此附加设置，“重新启动管理器”支持才能正常工作。
	//     2) 在您的项目中，您必须按照生成顺序向 System.Windows.Forms 添加引用。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: 将以下应用程序 ID 字符串替换为唯一的 ID 字符串；建议的字符串格式
	//为 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("rabc1.AppID.NoVersion"));

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 Crabc1App 对象

Crabc1App theApp;


// Crabc1App 初始化

BOOL Crabc1App::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// 使用 RichEdit 控件需要  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// 注册应用程序的文档模板。文档模板
	// 将用作文档、框架窗口和视图之间的连接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(Crabc1Doc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架窗口
		RUNTIME_CLASS(Crabc1View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// 分析标准 shell 命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// 调度在命令行中指定的命令。如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// 仅当具有后缀时才调用 DragAcceptFiles
	//  在 SDI 应用程序中，这应在 ProcessShellCommand 之后发生
	return TRUE;
}

int Crabc1App::ExitInstance()
{
	//TODO: 处理可能已添加的附加资源
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// Crabc1App 消息处理程序


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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

// 用于运行对话框的应用程序命令
void Crabc1App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// Crabc1App 自定义加载/保存方法

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

// Crabc1App 消息处理程序





void Crabc1App::login()
{
	// TODO: 在此添加命令处理程序代码
	Clogin log;
	log.DoModal();
}


void Crabc1App::regist()
{
	// TODO: 在此添加命令处理程序代码
	Cregist reg;
	reg.DoModal();
}


void Crabc1App::addrole()
{
	// TODO: 在此添加命令处理程序代码
	Caddr ad;
	ad.DoModal();
}


void Crabc1App::addp()
{
	// TODO: 在此添加命令处理程序代码
	Caddp ad;
	ad.DoModal();
}


void Crabc1App::yonghujuesezhipai()
{
	// TODO: 在此添加命令处理程序代码
	Cjuesezhipai ju;
	ju.DoModal();
}


void Crabc1App::yonghujuesechexiao()
{
	// TODO: 在此添加命令处理程序代码
	Cjuesechexiao ju;
	ju.DoModal();
}


void Crabc1App::juesequanxianzhipai()
{
	// TODO: 在此添加命令处理程序代码
	Cquanxianzhipai qu;
	qu.DoModal();
}


void Crabc1App::juesequanxianchexiao()
{
	// TODO: 在此添加命令处理程序代码
	Cquanxianchexiao qu;
	qu.DoModal();
}


void Crabc1App::addnext()
{
	// TODO: 在此添加命令处理程序代码
	Caddnextr ne;
	ne.DoModal();
}


void Crabc1App::delnext()
{
	// TODO: 在此添加命令处理程序代码
	Cdelnextr de;
	de.DoModal();
}


void Crabc1App::delupon()
{
	// TODO: 在此添加命令处理程序代码
	Cdelupon de;
	de.DoModal();
}


void Crabc1App::save()
{
	// TODO: 在此添加命令处理程序代码
	Csave sa;
	sa.DoModal();
}


void Crabc1App::load()
{
	// TODO: 在此添加命令处理程序代码
	Cload lo;
	lo.DoModal();
}
