#include<stdlib.h>
#include"class.h"

//初始化课程双向链表
Classlist initclasslist(Classlist l)
{
     l=(classlist*)malloc(sizeof(classlist));
     l->next=NULL;
     l->prev=l;
     return l;
}
