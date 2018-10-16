#include<stdio.h>
#include<string.h>
#include"student.h"

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

