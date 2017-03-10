// Cregist.cpp : 实现文件
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cregist.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cregist 对话框

IMPLEMENT_DYNAMIC(Cregist, CDialog)

Cregist::Cregist(CWnd* pParent /*=NULL*/)
	: CDialog(Cregist::IDD, pParent)
	, SNAME(_T(""))
	, PASSWORD(_T(""))
{

}

Cregist::~Cregist()
{
}

void Cregist::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, SNAME);
	DDX_Text(pDX, IDC_EDIT2, PASSWORD);
}


BEGIN_MESSAGE_MAP(Cregist, CDialog)
	ON_BN_CLICKED(IDOK, &Cregist::OnBnClickedOk)
END_MESSAGE_MAP()


// Cregist 消息处理程序


void Cregist::OnBnClickedOk()
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
	mann.add_s(sname,password);
	CDialog::OnOK();
}
