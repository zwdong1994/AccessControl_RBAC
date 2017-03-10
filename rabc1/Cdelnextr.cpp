// Cdelnextr.cpp : 实现文件
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cdelnextr.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cdelnextr 对话框

IMPLEMENT_DYNAMIC(Cdelnextr, CDialog)

Cdelnextr::Cdelnextr(CWnd* pParent /*=NULL*/)
	: CDialog(Cdelnextr::IDD, pParent)
	, RNAME(_T(""))
	, RNAMECHILD(_T(""))
{

}

Cdelnextr::~Cdelnextr()
{
}

void Cdelnextr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
	DDX_Text(pDX, IDC_EDIT2, RNAMECHILD);
}


BEGIN_MESSAGE_MAP(Cdelnextr, CDialog)
	ON_BN_CLICKED(IDOK, &Cdelnextr::OnBnClickedOk)
END_MESSAGE_MAP()


// Cdelnextr 消息处理程序


void Cdelnextr::OnBnClickedOk()
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
	if(mann.del_next_r(rname,rnamechild)==0)
	{
		MessageBox(_T("下级角色删除失败！"));
		return;
	}
	CDialog::OnOK();
}
