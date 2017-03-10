// Caddr.cpp : 实现文件
//

#include "stdafx.h"
#include "rabc1.h"
#include "Caddr.h"
#include "afxdialogex.h"
#include "tianjia.h"


// Caddr 对话框

IMPLEMENT_DYNAMIC(Caddr, CDialog)

Caddr::Caddr(CWnd* pParent /*=NULL*/)
	: CDialog(Caddr::IDD, pParent)
	, RNAME(_T(""))
{

}

Caddr::~Caddr()
{
}

void Caddr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
}


BEGIN_MESSAGE_MAP(Caddr, CDialog)
	ON_BN_CLICKED(IDOK, &Caddr::OnBnClickedOk)
END_MESSAGE_MAP()


// Caddr 消息处理程序


void Caddr::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	char rname[20];
	if(strcmp(mann.current_sname,"\0")==0)
	{
		MessageBox(_T("未登录！"));
		return;
	}
	if(RNAME.IsEmpty())
	{
		MessageBox(_T("角色名不能为空！"));
		return;
	}
	sprintf(rname,"%s",RNAME);
	if(mann.add_r(rname)==0)
	{
		MessageBox(_T("添加角色失败！"));
		return;
	}
	CDialog::OnOK();
}
