// Cquanxianzhipai.cpp : 实现文件
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cquanxianzhipai.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cquanxianzhipai 对话框

IMPLEMENT_DYNAMIC(Cquanxianzhipai, CDialog)

Cquanxianzhipai::Cquanxianzhipai(CWnd* pParent /*=NULL*/)
	: CDialog(Cquanxianzhipai::IDD, pParent)
	, RNAME(_T(""))
	, PNAME(_T(""))
{

}

Cquanxianzhipai::~Cquanxianzhipai()
{
}

void Cquanxianzhipai::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
	DDX_Text(pDX, IDC_EDIT2, PNAME);
}


BEGIN_MESSAGE_MAP(Cquanxianzhipai, CDialog)
	ON_BN_CLICKED(IDOK, &Cquanxianzhipai::OnBnClickedOk)
END_MESSAGE_MAP()


// Cquanxianzhipai 消息处理程序


void Cquanxianzhipai::OnBnClickedOk()
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
	if(mann.pa_zhipai(rname,pname)==0)
	{
		MessageBox(_T("指派失败！"));
		return;
	}
	CDialog::OnOK();
}
