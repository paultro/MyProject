
#include<string.h>
#include<stdlib.h>
#include"student.h"
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
