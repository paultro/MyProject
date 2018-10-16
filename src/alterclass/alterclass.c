#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"class.h"

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
