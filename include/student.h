
typedef struct stu
{
    int classnum;
    char no[11];
    char name[10];
    char class[10][100];
    int score;
}Stu;

typedef struct stulist{
    struct stulist *next;
    struct stulist *prev;
    Stu n;
}stulist,*Stulist;
