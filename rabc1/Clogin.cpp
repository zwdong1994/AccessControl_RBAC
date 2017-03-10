// Clogin.cpp : 实现文件
//

#include "stdafx.h"
#include "rabc1.h"
#include "Clogin.h"
#include "afxdialogex.h"
#include "Cregist.h"

#include "stdlib.h"


mannager mann;
// Clogin 对话框

IMPLEMENT_DYNAMIC(Clogin, CDialog)

Clogin::Clogin(CWnd* pParent /*=NULL*/)
	: CDialog(Clogin::IDD, pParent)
	, SNAME(_T(""))
	, PASSWORD(_T(""))
{

}

Clogin::~Clogin()
{
}

void Clogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, SNAME);
	DDX_Text(pDX, IDC_EDIT2, PASSWORD);
}


BEGIN_MESSAGE_MAP(Clogin, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &Clogin::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &Clogin::OnBnClickedOk)
END_MESSAGE_MAP()


// Clogin 消息处理程序


void Clogin::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	Cregist reg;
	reg.DoModal();
}


void Clogin::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData();
	char sname[20];
	char password[20];
	if(SNAME.IsEmpty())
	{
		MessageBox(_T("用户名不能为空！"));
		return;
	}
	if(PASSWORD.IsEmpty())
	{
		MessageBox(_T("密码不能为空！"));
		return;
	}
	sprintf(sname,"%s",SNAME);
	sprintf(password,"%s",PASSWORD);
	if(mann.login(sname,password)==0)
	{
		MessageBox(_T("用户名或者密码错误！"));
		return;
	}
	CDialog::OnOK();
}
