#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"
#include"class.h"
#include"addclass.h"
#include"addstu.h"
#include"alterclass.h"
#include"alterstu.h"
#include"deleteclass.h"
#include"deletestu.h"
#include"initcla.h"
#include"initstu.h"
#include"clakb.h"
#include"stukb.h"
#include"searchclass.h"
#include"searchstu.h"

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
