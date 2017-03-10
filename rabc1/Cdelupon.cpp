// Cdelupon.cpp : 实现文件
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cdelupon.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cdelupon 对话框

IMPLEMENT_DYNAMIC(Cdelupon, CDialog)

Cdelupon::Cdelupon(CWnd* pParent /*=NULL*/)
	: CDialog(Cdelupon::IDD, pParent)
	, RNAME(_T(""))
	, RNAMEFATHER(_T(""))
{

}

Cdelupon::~Cdelupon()
{
}

void Cdelupon::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
	DDX_Text(pDX, IDC_EDIT2, RNAMEFATHER);
}


BEGIN_MESSAGE_MAP(Cdelupon, CDialog)
	ON_BN_CLICKED(IDOK, &Cdelupon::OnBnClickedOk)
END_MESSAGE_MAP()


// Cdelupon 消息处理程序


void Cdelupon::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	char rname[20],rnamefather[20];
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
	if(RNAMEFATHER.IsEmpty())
	{
		MessageBox(_T("上级角色名不能为空！"));
		return;
	}
	sprintf(rname,"%s",RNAME);
	sprintf(rnamefather,"%s",RNAMEFATHER);
	if(mann.del_upon_r(rname,rnamefather)==0)
	{
		MessageBox(_T("上级角色删除失败！"));
		return;
	}
	CDialog::OnOK();
}
