#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"student.h"
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
