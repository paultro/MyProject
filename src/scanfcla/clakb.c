#include<stdio.h>
#include"class.h"

Class clakb()
{
    Class n;
    printf("class no: ");
    scanf("%s",n.no);
    printf("class name: ");
    scanf("%s",n.name);
    printf("class type: ");
    scanf("%s",n.type);
    printf("time for one class: ");
    scanf("%d",&n.time);
    printf("class score: ");
    scanf("%d",&n.score);
    printf("how many students choose this class? ");
    scanf("%d",&n.stunum);
    printf("the high limit of students'number: ");
    scanf("%d",&n.lim);
    return n;
}
