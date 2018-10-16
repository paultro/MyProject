#include<stdio.h>
#include<string.h>
#include"student.h"

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
