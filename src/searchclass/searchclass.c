#include<stdio.h>
#include<string.h>
#include"class.h"

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
