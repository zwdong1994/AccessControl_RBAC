#include "StdAfx.h"
#include "mannager.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


mannager::mannager(void)
{
	u=NULL;
	r=NULL;
	per=NULL;
	pra=NULL;
	ura=NULL;
	rra=NULL;
	strcpy(current_sname,"\0");
}


mannager::~mannager(void)
{
}

int mannager::login(char sname[20],char password[15])
{
    struct user *p;
    p=u;
    while(p!=NULL)
    {
        if(strcmp(p->sname,sname)==0&&strcmp(p->password,password)==0)
        {
            strcpy(current_sname,sname);
            return 1;
        }
        p=p->next;
    }
    return 0;
}
int mannager::add_s(char sname[20],char password[15])
{
    struct user *p;
    p=(struct user *)malloc(sizeof(struct user));
    strcpy(p->sname,sname);
    strcpy(p->password,password);
    p->next=u;
    u=p;
    return 1;
}

int mannager::add_r(char rname[20])
{
    struct role *p,*q;
    p=r;
    while(p!=NULL)
    {
        if(strcmp(rname,p->rname)==0)
            return 0;
        else
            p=p->next;
    }
    q=(struct role *)malloc(sizeof(struct role));
    strcpy(q->rname,rname);
    q->next=r;
    r=q;
    return 1;
}
int mannager::add_p(char pname[20])
{
    struct permission *p,*q;
    p=per;
    while(p!=NULL)
    {
        if(strcmp(p->pname,pname)==0)
            return 0;
        else
            p=p->next;
    }
    q=(struct permission *)malloc(sizeof(struct permission));
    strcpy(q->pname,pname);
    q->next=per;
    per=q;
    return 1;
}
int mannager::zhipai_ua(char sname[20],char rname[20])
{
    struct ua *p,*q;
    struct role *m;
    m=r;
    p=ura;
    while(m!=NULL)
    {
        if(strcmp(m->rname,rname)==0)
            break;
        m=m->next;
    }
    if(m==NULL)
    {
        return 0;
    }
    while(p!=NULL)
    {
        if(strcmp(p->sname,sname)==0&&strcmp(p->rname,rname)==0)
        {
            return 0;
        }
        else
            p=p->next;
    }
    q=(struct ua *)malloc(sizeof(struct ua));
    strcpy(q->sname,sname);
    strcpy(q->rname,rname);
    q->next=ura;
    ura=q;
    return 1;
}

int mannager::chexiao_ua(char sname[20],char rname[20])
{
    struct ua *p,*q=NULL;
    p=ura;
    if(q==NULL)
    {
		if(p==NULL)
			return 0;
        if(strcmp(p->sname,sname)==0&&strcmp(p->rname,rname)==0)
        {
            ura=p->next;
            free(p);
            return 1;
        }
    }
    q=p;
    p=p->next;
    while(p!=NULL)
    {
        if(strcmp(p->sname,sname)==0&&strcmp(p->rname,rname)==0)
        {
            q->next=p->next;
            free(p);
            return 1;
        }
        q=p;
        p=p->next;
    }
    return 0;
}

int mannager::pa_zhipai(char rname[20],char pname[20])
{
    struct pa *p,*q;
    struct role *m=r;
    struct permission *n=per;
    p=pra;
    while(m!=NULL)
    {
        if(strcmp(m->rname,rname)==0)
            break;
        m=m->next;
    }
    if(m==NULL)
        return 0;
    while(n!=NULL)
    {
        if(strcmp(n->pname,pname)==0)
            break;
        n=n->next;
    }
    if(n==NULL)
        return 0;
    while(p!=NULL)
    {
        if(strcmp(p->rname,rname)==0&&strcmp(p->pname,pname)==0)
        {
            return 0;
        }
        p=p->next;
    }
    q=(struct pa *)malloc(sizeof(struct pa));
    strcpy(q->rname,rname);
    strcpy(q->pname,pname);
    q->next=pra;
    pra=q;
    return 1;
}
int mannager::pa_chexiao(char rname[20],char pname[20])
{
    struct pa *p,*q=NULL;
    p=pra;
    if(q==NULL)
    {
		if(p==NULL)
		{
			return 0;
		}
        if(strcmp(p->rname,rname)==0&&strcmp(p->pname,pname)==0)
        {
            pra=p->next;
            free(p);
            return 1;
        }
    }
    q=p;
    p=p->next;
    while(p!=NULL)
    {
        if(strcmp(p->rname,rname)==0&&strcmp(p->pname,pname)==0)
        {
            q->next=p->next;
            free(p);
            return 1;
        }
        q=p;
        p=p->next;
    }
    return 0;
}
int mannager::add_next_r(char rname[20],char rnamechild[20])
{
    struct role *p;
    struct ra *q,*m,*n;
    p=r;
    q=rra;
	if(strcmp(rnamechild,rname)==0)
	{
		return 0;
	}
    while(p!=NULL)
    {
        if(strcmp(p->rname,rname)==0)
            break;
        p=p->next;
    }
    if(p==NULL)
        return 0;
    p=r;
    while(p!=NULL)
    {
        if(strcmp(p->rname,rnamechild)==0)
            break;
        p=p->next;
    }
    if(p==NULL)
        return 0;
    while(q!=NULL)
    {
        if(strcmp(q->rname,rname)==0&&strcmp(q->rnamechild,rnamechild)==0)
            return 0;
        q=q->next;
    }
    if(rra==NULL)
    {
    m=(struct ra *)malloc(sizeof(struct ra));
    strcpy(m->rname,rname);
    strcpy(m->rnamechild,rnamechild);
    strcpy(m->rnamefather,"\0");
    m->next=rra;
    rra=m;
    n=(struct ra *)malloc(sizeof(struct ra));
    strcpy(n->rname,rnamechild);
    strcpy(n->rnamefather,rname);
    strcpy(n->rnamechild,"\0");
    n->next=rra;
    rra=n;
    return 1;
    }
    q=rra;
    while(q!=NULL)
    {
        if(strcmp(q->rname,rnamechild)==0&&strcmp(q->rnamechild,"\0")!=0)
        {
            if(circle_test(rname,rnamechild)==1)
            return 0;
			else
				break;
        }
        q=q->next;
    }
    m=(struct ra *)malloc(sizeof(struct ra));
    strcpy(m->rname,rname);
    strcpy(m->rnamechild,rnamechild);
    strcpy(m->rnamefather,"\0");
    m->next=rra;
    rra=m;
    n=(struct ra *)malloc(sizeof(struct ra));
    strcpy(n->rname,rnamechild);
    strcpy(n->rnamefather,rname);
    strcpy(n->rnamechild,"\0");
    n->next=rra;
    rra=n;
    return 1;
}
int mannager::del_next_r(char rname[20],char rnamechild[20])
{
    struct ra *p,*hp;
    p=rra;
    hp=NULL;
    if(hp==NULL)
    {
		if(p==NULL)
		{
			return 0;
		}
        if(strcmp(p->rname,rname)==0&&strcmp(p->rnamechild,rnamechild)==0)
        {
            rra=p->next;
            free(p);
        }
        else
        {
            hp=p;
            p=p->next;
            while(p!=NULL)
            {
                if(strcmp(p->rname,rname)==0&&strcmp(p->rnamechild,rnamechild)==0)
                {
                    hp->next=p->next;
                    free(p);
                    break;
                }
                hp=p;
                p=p->next;
            }
            if(p==NULL)
            return 0;
        }
    }
    p=rra;
    hp=NULL;
    if(hp==NULL)
    {
        if(strcmp(p->rname,rnamechild)==0&&strcmp(p->rnamefather,rname)==0)
        {
            rra=p->next;
            free(p);
            return 1;
        }
        else
        {
            hp=p;
            p=p->next;
            while(p!=NULL)
            {
                if(strcmp(p->rname,rnamechild)==0&&strcmp(p->rnamefather,rname)==0)
                {
                    hp->next=p->next;
                    free(p);
                    return 1;
                }
                hp=p;
                p=p->next;
            }
            return 0;
        }
    }
	return 0;
}
int mannager::del_upon_r(char rname[20],char rnamefather[20])
{
    struct ra *p,*hp;
    p=rra;
    hp=NULL;
    if(hp==NULL)
    {
		if(p==NULL)
			return 0;
        if(strcmp(p->rname,rname)==0&&strcmp(p->rnamefather,rnamefather)==0)
        {
            rra=p->next;
            free(p);
        }
        else
        {
            hp=p;
            p=p->next;
            while(p!=NULL)
            {
                 if(strcmp(p->rname,rname)==0&&strcmp(p->rnamefather,rnamefather)==0)
                {
                    hp->next=p->next;
                    free(p);
                    break;
                }
                hp=p;
                p=p->next;
            }
            if(p==NULL)
            return 0;
        }
    }
    p=rra;
    hp=NULL;
    if(hp==NULL)
    {
        if(strcmp(p->rname,rnamefather)==0&&strcmp(p->rnamechild,rname)==0)
        {
            rra=p->next;
            free(p);
            return 1;
        }
        else
        {
            hp=p;
            p=p->next;
            while(p!=NULL)
            {
                if(strcmp(p->rname,rnamefather)==0&&strcmp(p->rnamechild,rname)==0)
                {
                    hp->next=p->next;
                    free(p);
                    return 1;
                }
                hp=p;
                p=p->next;
            }
            return 0;
        }
    }
	return 0;
}

int mannager::circle_test(char testrname[20],char rname[20])
{
    struct ra *p,*q;
    int i=0;
    p=rra;
    q=rra;
    if(circle_more_test(testrname,rname))
		return 1;
	while(p!=NULL)
	{
		if(strcmp(rname,p->rname)==0&&strcmp(p->rnamechild,"\0")!=0)
		{
			i=circle_test(testrname,p->rnamechild);
			if(i)
				return 1;
		}
		p=p->next;
	}
    return 0;
}

int mannager::circle_more_test(char testrname[20],char rname[20])
{
	struct ra *p;
    p=rra;
	while(p!=NULL)
	{
		if(strcmp(rname,p->rname)==0&&strcmp(p->rnamechild,"\0")!=0)
		{
			if(strcmp(p->rnamechild,testrname)==0)
            return 1;
		}
		p=p->next;
	}
	return 0;
}

int mannager::save(char route[30])
{
	FILE *out1,*out2,*out3,*out4,*out5,*out6;
	struct user *p1=u;
	struct role *p2=r;
	struct permission *p3=per;
	struct pa *p4=pra;
	struct ua *p5=ura;
	struct ra *p6=rra;
	char p1name[40],p2name[40],p3name[40],p4name[40],p5name[40],p6name[40];
	sprintf(p1name,"%suser.dat",route);
	sprintf(p2name,"%srole.dat",route);
	sprintf(p3name,"%spermission.dat",route);
	sprintf(p4name,"%spa.dat",route);
	sprintf(p5name,"%sua.dat",route);
	sprintf(p6name,"%sra.dat",route);
	if((out1=fopen(p1name,"wb"))==NULL)
	{
		return 0;
	}
	if((out2=fopen(p2name,"wb"))==NULL)
	{
		return 0;
	}
	if((out3=fopen(p3name,"wb"))==NULL)
	{
		return 0;
	}
	if((out4=fopen(p4name,"wb"))==NULL)
	{
		return 0;
	}
	if((out5=fopen(p5name,"wb"))==NULL)
	{
		return 0;
	}
	if((out6=fopen(p6name,"wb"))==NULL)
	{
		return 0;
	}
	while(p1!=NULL)
	{
		fwrite(p1,sizeof(struct user),1,out1);
		p1=p1->next;
	}
	while(p2!=NULL)
	{
		fwrite(p2,sizeof(struct role),1,out2);
		p2=p2->next;
	}
	while(p3!=NULL)
	{
		fwrite(p3,sizeof(struct permission),1,out3);
		p3=p3->next;
	}
	while(p4!=NULL)
	{
		fwrite(p4,sizeof(struct pa),1,out4);
		p4=p4->next;
	}
	while(p5!=NULL)
	{
		fwrite(p5,sizeof(struct ua),1,out5);
		p5=p5->next;
	}
	while(p6!=NULL)
	{
		fwrite(p6,sizeof(struct ra),1,out6);
		p6=p6->next;
	}
	fclose(out1);
	fclose(out2);
	fclose(out3);
	fclose(out4);
	fclose(out5);
	fclose(out6);
	return 1;
}

int mannager::load(char route[30])
{
	FILE *out1,*out2,*out3,*out4,*out5,*out6;
	struct user *p1=u,*hp1=NULL;
	struct role *p2=r,*hp2=NULL;
	struct permission *p3=per,*hp3=NULL;
	struct pa *p4=pra,*hp4=NULL;
	struct ua *p5=ura,*hp5=NULL;
	struct ra *p6=rra,*hp6=NULL;
	char p1name[40],p2name[40],p3name[40],p4name[40],p5name[40],p6name[40];
	sprintf(p1name,"%suser.dat",route);
	sprintf(p2name,"%srole.dat",route);
	sprintf(p3name,"%spermission.dat",route);
	sprintf(p4name,"%spa.dat",route);
	sprintf(p5name,"%sua.dat",route);
	sprintf(p6name,"%sra.dat",route);
	if((out1=fopen(p1name,"rb"))==NULL)
	{
		return 0;
	}
	if((out2=fopen(p2name,"rb"))==NULL)
	{
		return 0;
	}
	if((out3=fopen(p3name,"rb"))==NULL)
	{
		return 0;
	}
	if((out4=fopen(p4name,"rb"))==NULL)
	{
		return 0;
	}
	if((out5=fopen(p5name,"rb"))==NULL)
	{
		return 0;
	}
	if((out6=fopen(p6name,"rb"))==NULL)
	{
		return 0;
	}
	while(!feof(out1))
	{
		p1=(struct user *)malloc(sizeof(struct user));
		fread(p1,sizeof(struct user),1,out1);
		p1->next=hp1;
		hp1=p1;
	}
	u=hp1;
	while(!feof(out2))
	{
		p2=(struct role *)malloc(sizeof(struct role));
		fread(p2,sizeof(struct role),1,out2);
		p2->next=hp2;
		hp2=p2;
	}
	r=hp2;
	while(!feof(out3))
	{
		p3=(struct permission *)malloc(sizeof(struct permission));
		fread(p3,sizeof(struct permission),1,out3);
		p3->next=hp3;
		hp3=p3;
	}
	per=hp3;
	while(!feof(out4))
	{
		p4=(struct pa *)malloc(sizeof(struct pa));
		fread(p4,sizeof(struct pa),1,out4);
		p4->next=hp4;
		hp4=p4;
	}
	pra=hp4;
	while(!feof(out5))
	{
		p5=(struct ua *)malloc(sizeof(struct ua));
		fread(p5,sizeof(struct ua),1,out5);
		p5->next=hp5;
		hp5=p5;
	}
	ura=hp5;
	while(!feof(out6))
	{
		p6=(struct ra *)malloc(sizeof(struct ra));
		fread(p6,sizeof(struct ra),1,out6);
		p6->next=hp6;
		hp6=p6;
	}
	fclose(out1);
	fclose(out2);
	fclose(out3);
	fclose(out4);
	fclose(out5);
	fclose(out6);
	return 1;
}
