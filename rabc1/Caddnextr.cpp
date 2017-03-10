// Caddnextr.cpp : 实现文件
//

#include "stdafx.h"
#include "rabc1.h"
#include "Caddnextr.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Caddnextr 对话框

IMPLEMENT_DYNAMIC(Caddnextr, CDialog)

Caddnextr::Caddnextr(CWnd* pParent /*=NULL*/)
	: CDialog(Caddnextr::IDD, pParent)
	, RNAME(_T(""))
	, RNAMECHILD(_T(""))
{

}

Caddnextr::~Caddnextr()
{
}

void Caddnextr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
	DDX_Text(pDX, IDC_EDIT2, RNAMECHILD);
}


BEGIN_MESSAGE_MAP(Caddnextr, CDialog)
	ON_BN_CLICKED(IDOK, &Caddnextr::OnBnClickedOk)
END_MESSAGE_MAP()


// Caddnextr 消息处理程序


void Caddnextr::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	char rname[20],rnamechild[20];
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
	if(RNAMECHILD.IsEmpty())
	{
		MessageBox(_T("下级角色名不能为空！"));
		return;
	}
	sprintf(rname,"%s",RNAME);
	sprintf(rnamechild,"%s",RNAMECHILD);
	if(mann.add_next_r(rname,rnamechild)==0)
	{
		MessageBox(_T("下级角色添加失败！"));
		return;
	}
	CDialog::OnOK();
}
