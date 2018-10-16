#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stu
{
    int classnum;
    char no[11];
    char name[10];
    char class[10][100];
    int score;
}Stu;

typedef struct stulist{
    struct stulist *next;
    struct stulist *prev;
    Stu n;
}stulist,*Stulist;

typedef struct class
{
    char no[8];
    char name[20];
    char type[20];
    int time;
    int score;
    int stunum;
    int lim;
}Class;

typedef struct classlist{
    struct classlist *next;
    struct classlist *prev;
    Class nc;
}classlist,*Classlist;

Class clakb()
{
    Class n;
    printf("class no: ");
    scanf("%s",n.no);
    printf("class name: ");
    scanf("%s",n.name);
    printf("class type: ");
    scanf("%s",n.type);
    printf("time for one class: ");
    scanf("%d",&n.time);
    printf("class score: ");
    scanf("%d",&n.score);
    printf("how many students choose this class? ");
    scanf("%d",&n.stunum);
    printf("the high limit of students'number: ");
    scanf("%d",&n.lim);
    return n;
}

Stu stukb()
{
    Stu n;
    int i;
    printf("your no: ");
    scanf("%s",n.no);
    printf("your name: ");
    scanf("%s",n.name);
    printf("how many class you choose:");
    scanf("%d",&n.classnum);
    for(i=0;i<n.classnum;i++)
    {
        printf("class name: ");
	scanf("%s",n.class[i]);
    }
    printf("all class score:");
    scanf("%d",&n.score);
    return n;
}

//初始化学生双向链表
Stulist initstulist(Stulist l)
{
    l=(Stulist)malloc(sizeof(stulist));
    l->next=NULL;
    l->prev=l;
    /*if(!l)
        exit(OVERFLOW);
    return OK;*/
    return l;
}

//初始化课程双向链表
Classlist initclasslist(Classlist l)
{
     l=(classlist*)malloc(sizeof(classlist));
     l->next=NULL;
     l->prev=l;
     return l;
}

//查找学号为×××的学生信息
Stulist searchstu(Stulist l,char no[])
{
    stulist *p;
    p=l;
    while(p!=NULL)
    {
        if(strcmp(p->n.no,no)==0)
	{
	    return p;
	}
	p=p->next;
    }
    printf("%s is not exist",no);
    return NULL;
}

//查找课程号为×××的课程信息
Classlist searchclass(Classlist l,char no[])
{
    classlist *p;
    p=l;
    while(p!=NULL)
    {
        if(strcmp(p->nc.no,no)==0)
	{
	    return p;
	}
	p=p->next;
    }
    printf("%s is not exist",no);
    return NULL;
}

//增加一个学生信息
Stulist addstu(Stulist l,Stu n)
{
    int i;
    Stulist p=NULL,t=NULL;
    t=(Stulist)malloc(sizeof(stulist));
    p=l;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    t->prev=p;
    t->next=NULL;
    p->next=t;
    strcpy(t->n.no,n.no);
    strcpy(t->n.name,n.name);
    for(i=0;i<n.classnum;i++)
    {
       strcpy(t->n.class[i],n.class[i]);
    }
    t->n.classnum=n.classnum;
    t->n.score=n.score;
    return l;
}

//增加一个课程信息
Classlist addclass(Classlist l,Class n)
{
    Classlist p=NULL,t=NULL;
    t=(Classlist)malloc(sizeof(Classlist));
    p=l;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    t->prev=p;
    t->next=NULL;
    p->next=t;
    strcpy(t->nc.no,n.no);
    strcpy(t->nc.name,n.name);
    strcpy(t->nc.type,n.type);
    t->nc.time=n.time;
    t->nc.score=n.score;
    t->nc.stunum=n.stunum;
    t->nc.lim=n.lim;
    return l;
}

//删除某个学生的信息
Stulist deletestulist(Stulist l,char no[])
{
    stulist *p;
    p=l;
    while(p->next!=NULL)
    {
        if(strcmp(p->n.no,no)==0)
	{
	    p->prev->next=p->next;
            p->next->prev=p->prev;
            free(p);
            return l;
	}
	p=p->next;
    }
    if(strcmp(p->n.no,no)==0)
    {
	p->prev->next=NULL;
        free(p);
        return l;
    }
    printf("%s is not exist",no);
    return NULL;
}

//删除某个课程的信息
Classlist deleteclasslist(Classlist l,char no[])
{
    classlist *p;
    p=l;
    while(p->next!=NULL)
    {
        if(strcmp(p->nc.no,no)==0)
	{
	    p->prev->next=p->next;
            p->next->prev=p->prev;
            free(p);
            return l;
	}
	p=p->next;
    }
    if(strcmp(p->nc.no,no)==0)
    {
	p->prev->next=NULL;
        free(p);
        return l;
    }
    printf("%s is not exist",no);
    return NULL;
}

//修改学生信息
Stulist alterstulist(Stulist l,char no[])
{
    int i;
    stulist *p;
    p=l;
    while(p!=NULL)
    {
        if(strcmp(p->n.no,no)==0)
	{
            printf("now you can alter---------------------\n");
            printf("your name: ");
            scanf("%s",p->n.name);
            printf("how many class you choose:");
            scanf("%d",&p->n.classnum);
            for(i=0;i<p->n.classnum;i++)
            {
                printf("class name: ");
	        scanf("%s",p->n.class[i]);
            }
            printf("all class score:");
            scanf("%d",&p->n.score);
            return l;
	}
	p=p->next;
    }
    printf("%s is not exist",no);
    return NULL;
}

//修改课程信息
Classlist alterclasslist(Classlist l,char no[])
{
    classlist *p;
    p=l;
    while(p!=NULL)
    {
        if(strcmp(p->nc.no,no)==0)
	{
            printf("now you can alter---------------------\n");
            printf("class name: ");
            scanf("%s",p->nc.name);
            printf("type: ");
            scanf("%s",p->nc.type);
            printf("class time: ");
            scanf("%d",&p->nc.time);
            printf("class score: ");
            scanf("%d",&p->nc.score);
            printf("this class student number: ");
            scanf("%d",&p->nc.stunum);
            printf("this class student number limit: ");
            scanf("%d",&p->nc.lim);
            return l;
	}
	p=p->next;
    }
    printf("%s is not exist",no);
    return NULL;
}

int main()
{
    int i=0,j=0,tag,exit;
    Stulist stu=NULL;
    Stu s;
    Classlist cla=NULL;
    Class c;
    printf("---------->HELLO WORLD<----------\n");
    /*printf("you can enter 1 to exit: ");
    scanf("%d",&exit);
    if(exit==1)
    {return 0;}*/
    //初始化
    stu=initstulist(stu);
    cla=initclasslist(cla);
    //从键盘读入第一个数据
    /*s=stukb();
    printf("\n");
    c=clakb();
    //输出输入的第一个批数据
    /*printf("this student's name: %s\n",s.name);
    for(i=0;i<s.classnum;i++)
    {
        printf("this student's class: %s\n",s.class[i]);
    }
    printf("this student's all class score: %d\n",s.score);
    printf("this class's name: %s\n",c.name);
    printf("this class's type: %s\n",c.type);
    printf("this class's score: %d\n",c.score);
    printf("this class's time: %d\n",c.time);
    printf("this class's students number: %d\n",c.stunum);
    printf("this class's students number limit: %d\n",c.lim);*/
    //将学生数据放到学生链表中
    /*strcpy(stu->n.no,s.no);
    strcpy(stu->n.name,s.name);
    for(i=0;i<s.classnum;i++)
    {
       strcpy(stu->n.class[i],s.class[i]);
    }
    stu->n.classnum=s.classnum;
    stu->n.score=s.score;
    //将课程数据放到课程链表
    strcpy(cla->nc.no,c.no);
    strcpy(cla->nc.name,c.name);
    strcpy(cla->nc.type,c.type);
    cla->nc.time=c.time;
    cla->nc.score=c.score;
    cla->nc.stunum=c.stunum;
    cla->nc.lim=c.lim;*/
    while(1)
    {
        printf("\n");
        printf("you can enter 1 to exit: ");
        scanf("%d",&exit);
        if(exit==1)
        {return 0;}
        printf("1.add student's information\n2.delete student's information\n3.alter student's information\n4.search student's information\n");
        printf("5.add class's information\n6.delete class's information\n7.alter class's information\n8.search class's information\n");
        printf("you choose: ");
        scanf("%d",&tag);
        if(tag==1)
        {
            Stu l;
            l=stukb();//printf("warning!!!");
            stu=addstu(stu,l);//printf("warning!!!");
        }
        else if(tag==5)
        {
            Class l;
            l=clakb();//printf("warning!!!");
            cla=addclass(cla,l);//printf("warning!!!");
        }
        else if(tag==4)
        {
            char str[11];
            Stulist p=NULL;
            //p=initstulist(p);
            printf("which student you want search:");
            scanf("%s",str);
            p=searchstu(stu,str);
            if(p!=NULL)
            {
                printf("this student's name: %s\n",p->n.name);
                printf("this student's classnum: %d\n",p->n.classnum);
                for(i=0;i<p->n.classnum;i++)
                {
                    printf("this student's class: %s\n",p->n.class[i]);
                }
                printf("this student's all class score: %d\n",p->n.score);
            }
        }
        else if(tag==8)
        {
            char str[8];
            Classlist p=NULL;
            //p=initstulist(p);
            printf("which class you want search:");
            scanf("%s",str);
            p=searchclass(cla,str);
            if(p!=NULL)
            {
                printf("this class's name: %s\n",p->nc.name);
                printf("this class's type: %s\n",p->nc.type);
                printf("this class's score: %d\n",p->nc.score);
                printf("this class's time: %d\n",p->nc.time);
                printf("this class's students number: %d\n",p->nc.stunum);
                printf("this class's students number limit: %d\n",p->nc.lim);
            }
        }
        else if(tag==2)
        {
            char str[11];
            printf("which student you want delete:");
            scanf("%s",str);
            stu=deletestulist(stu,str);
        }
        else if(tag==6)
        {
            char str[8];
            printf("which class you want delete:");
            scanf("%s",str);
            cla=deleteclasslist(cla,str);
        }
        else if(tag==3)
        {
            char str[11];
            printf("which student you want alter: ");
            scanf("%s",str);
            stu=alterstulist(stu,str);
        }
        else if(tag==7)
        {
            char str[8];
            printf("which class you want alter: ");
            scanf("%s",str);
            cla=alterclasslist(cla,str);
        }
        else
        {
            printf("敬请期待\n");
        }
        //j++;
    }
    return 0;
}
