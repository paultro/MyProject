#include<string.h>
#include<stdlib.h>
#include"class.h"
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
