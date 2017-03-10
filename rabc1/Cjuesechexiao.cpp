// Cjuesechexiao.cpp : 实现文件
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cjuesechexiao.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cjuesechexiao 对话框

IMPLEMENT_DYNAMIC(Cjuesechexiao, CDialog)

Cjuesechexiao::Cjuesechexiao(CWnd* pParent /*=NULL*/)
	: CDialog(Cjuesechexiao::IDD, pParent)
	, RNAME(_T(""))
{

}

Cjuesechexiao::~Cjuesechexiao()
{
}

void Cjuesechexiao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
}


BEGIN_MESSAGE_MAP(Cjuesechexiao, CDialog)
	ON_BN_CLICKED(IDOK, &Cjuesechexiao::OnBnClickedOk)
END_MESSAGE_MAP()


// Cjuesechexiao 消息处理程序


void Cjuesechexiao::OnBnClickedOk()
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
	if(mann.chexiao_ua(mann.current_sname,rname)==0)
	{
		MessageBox(_T("撤销失败！"));
		return;
	}
	CDialog::OnOK();
}
