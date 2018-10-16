#include<stdlib.h>
#include"student.h"

Stulist initstulist(Stulist l)
{
    l=(Stulist)malloc(sizeof(stulist));
    l->next=NULL;
    l->prev=l;
    /*if(!l)
        exit(OVERFLOW);
    return OK;*/
    return l;
}
