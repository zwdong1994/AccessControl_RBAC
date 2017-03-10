#pragma once
class mannager
{
public:
	mannager(void);
	~mannager(void);
public:
	struct user
{
    char sname[20];           /*用户名*/
    char password[15];      /*用户密码*/
    struct user *next;
}*u;
struct role
{
    char rname[20];     /*角色名*/
    struct role *next;
}*r;
struct permission
{
    char pname[20];  /*权限名*/
    struct permission *next;
}*per;
struct ua
{
    char sname[20];
    char rname[20];
    struct ua *next;
}*ura;
struct pa
{
    char rname[20];
    char pname[20];
    struct pa *next;
}*pra;
struct ra
{
    char rnamefather[20];
    char rnamechild[20];
    char rname[20];
    struct ra *next;
}*rra;
char current_sname[20];
public:
int login(char sname[20],char password[15]);
int add_s(char sname[20],char password[15]);
int add_r(char rname[20]);
int add_p(char pname[20]);
public:
int zhipai_ua(char sname[20],char rname[20]);
int chexiao_ua(char sname[20],char rname[20]);
int pa_zhipai(char rname[20],char pname[20]);
int pa_chexiao(char rname[20],char pname[20]);
int add_next_r(char rname[20],char rnamechild[20]);
int del_next_r(char rname[20],char rnamechild[20]);
int del_upon_r(char rname[20],char rnamefather[20]);
int circle_test(char testrname[20],char rname[20]);
int circle_more_test(char testrname[20],char rname[20]);
int save(char route[30]);
int load(char route[30]);
};

