// Cload.cpp : 实现文件
//

#include "stdafx.h"
#include "rabc1.h"
#include "Cload.h"
#include "afxdialogex.h"
#include "tianjia.h"

// Cload 对话框

IMPLEMENT_DYNAMIC(Cload, CDialog)

Cload::Cload(CWnd* pParent /*=NULL*/)
	: CDialog(Cload::IDD, pParent)
	, ROUTE(_T(""))
{

}

Cload::~Cload()
{
}

void Cload::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ROUTE);
}


BEGIN_MESSAGE_MAP(Cload, CDialog)
	ON_BN_CLICKED(IDOK, &Cload::OnBnClickedOk)
END_MESSAGE_MAP()


// Cload 消息处理程序


void Cload::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	char rout[30];
	sprintf(rout,"%s",ROUTE);
	if(ROUTE.IsEmpty())
	{
		MessageBox(_T("路径不能为空！"));
		return;
	}
	if(mann.load(rout)==0)
	{
		MessageBox(_T("读取失败！"));
		return;
	}
	CDialog::OnOK();
}
