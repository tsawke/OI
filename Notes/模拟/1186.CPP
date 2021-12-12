#include <stdio.h>
 
typedef struct _STUDENT_ 
{
    char name[21];
    int recive;
}Student;
 
Student student[100];
 
int main()
{
 
    int n, final_score, class_score, papers, total_sum = 0;
    char is_cadre, is_west_student;
 
 
    scanf("%d",&n);
 
    for (int i = 0 ; i < n; i ++)
    {
        scanf("%s%d%d %c %c%d",student[i].name, &final_score, &class_score,\
            &is_cadre, &is_west_student, &papers);
        if (final_score > 80 && papers >= 1)
        {
            student[i].recive += 8000;
            total_sum += 8000;
        }
        if (final_score > 85 && class_score > 80)
        {
            student[i].recive += 4000;
            total_sum += 4000;
        }
        if (final_score > 90)
        {
            student[i].recive += 2000;
            total_sum += 2000;
        }
        if (final_score > 85 && is_west_student == 'Y')
        {
            student[i].recive += 1000;
            total_sum += 1000;
        }
        if (class_score > 80 && is_cadre == 'Y')
        {
            student[i].recive += 850;
            total_sum += 850;
        }
    }
 
    int pmax = 0;
 
    for (int j = 0; j < n; j++)
    {
        if (student[j].recive > student[pmax].recive)
        {
            pmax = j;
        }
 
    }
 
    printf("%s\n%d\n%d\n",student[pmax].name, student[pmax].recive, total_sum);
    return 0;
}