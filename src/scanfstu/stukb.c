#include<stdio.h>
#include"student.h"

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
