// Cjuesezhipai.cpp : 实现文件
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cjuesezhipai.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cjuesezhipai 对话框

IMPLEMENT_DYNAMIC(Cjuesezhipai, CDialog)

Cjuesezhipai::Cjuesezhipai(CWnd* pParent /*=NULL*/)
	: CDialog(Cjuesezhipai::IDD, pParent)
	, RNAME(_T(""))
{

}

Cjuesezhipai::~Cjuesezhipai()
{
}

void Cjuesezhipai::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, RNAME);
}


BEGIN_MESSAGE_MAP(Cjuesezhipai, CDialog)
	ON_BN_CLICKED(IDOK, &Cjuesezhipai::OnBnClickedOk)
END_MESSAGE_MAP()


// Cjuesezhipai 消息处理程序


void Cjuesezhipai::OnBnClickedOk()
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
	if(mann.zhipai_ua(mann.current_sname,rname)==0)
	{
		MessageBox(_T("指派失败！"));
		return;
	}
	CDialog::OnOK();
}
