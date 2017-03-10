// Cquanxianchexiao.cpp : 实现文件
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cquanxianchexiao.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cquanxianchexiao 对话框

IMPLEMENT_DYNAMIC(Cquanxianchexiao, CDialog)

Cquanxianchexiao::Cquanxianchexiao(CWnd* pParent /*=NULL*/)
	: CDialog(Cquanxianchexiao::IDD, pParent)
	, RNAME(_T(""))
	, PNAME(_T(""))
{

}

Cquanxianchexiao::~Cquanxianchexiao()
{
}

void Cquanxianchexiao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
	DDX_Text(pDX, IDC_EDIT2, PNAME);
}


BEGIN_MESSAGE_MAP(Cquanxianchexiao, CDialog)
	ON_BN_CLICKED(IDOK, &Cquanxianchexiao::OnBnClickedOk)
END_MESSAGE_MAP()


// Cquanxianchexiao 消息处理程序


void Cquanxianchexiao::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	char rname[20],pname[20];
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
	if(PNAME.IsEmpty())
	{
		MessageBox(_T("权利名不能为空！"));
		return;
	}
	sprintf(rname,"%s",RNAME);
	sprintf(pname,"%s",PNAME);
	if(mann.pa_chexiao(rname,pname)==0)
	{
		MessageBox(_T("撤销失败！"));
		return;
	}
	CDialog::OnOK();
}
