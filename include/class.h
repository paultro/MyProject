
typedef struct class
{
    char no[8];
    char name[20];
    char type[20];
    int time;
    int score;
    int stunum;
    int lim;
}Class;

typedef struct classlist{
    struct classlist *next;
    struct classlist *prev;
    Class nc;
}classlist,*Classlist;
