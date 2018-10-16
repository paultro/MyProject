#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"class.h"
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
