
// rabc1.h : rabc1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include "mannager.h"

// Crabc1App:
// �йش����ʵ�֣������ rabc1.cpp
//

class Crabc1App : public CWinAppEx
{
public:
	Crabc1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
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
