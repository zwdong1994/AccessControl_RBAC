// Caddp.cpp : 实现文件
//

#include "stdafx.h"
#include "rabc1.h"
#include "Caddp.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Caddp 对话框

IMPLEMENT_DYNAMIC(Caddp, CDialog)

Caddp::Caddp(CWnd* pParent /*=NULL*/)
	: CDialog(Caddp::IDD, pParent)
	, PNAME(_T(""))
{

}

Caddp::~Caddp()
{
}

void Caddp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, PNAME);
}


BEGIN_MESSAGE_MAP(Caddp, CDialog)
	ON_BN_CLICKED(IDOK, &Caddp::OnBnClickedOk)
END_MESSAGE_MAP()


// Caddp 消息处理程序


void Caddp::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	char pname[20];
	if(strcmp(mann.current_sname,"\0")==0)
	{
		MessageBox(_T("未登录！"));
		return;
	}
	if(PNAME.IsEmpty())
	{
		MessageBox(_T("权利名不能为空！"));
		return;
	}
	sprintf(pname,"%s",PNAME);
	if(mann.add_p(pname)==0)
	{
		MessageBox(_T("添加权利失败！"));
		return;
	}
	CDialog::OnOK();
}
