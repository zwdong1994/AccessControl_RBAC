
// rabc1.h : rabc1 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号
#include "mannager.h"

// Crabc1App:
// 有关此类的实现，请参阅 rabc1.cpp
//

class Crabc1App : public CWinAppEx
{
public:
	Crabc1App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void login();
	afx_msg void regist();
	afx_msg void addrole();
	afx_msg void addp();
	afx_msg void yonghujuesezhipai();
	afx_msg void yonghujuesechexiao();
	afx_msg void juesequanxianzhipai();
	afx_msg void juesequanxianchexiao();
	afx_msg void addnext();
	afx_msg void delnext();
	afx_msg void delupon();
	afx_msg void save();
	afx_msg void load();
};

extern Crabc1App theApp;
