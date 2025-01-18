#include<stdio.h>
#include<string.h>

typedef struct employee {
  char first_name[32];
  char last_name[32];
  struct employee *boss;
} Employee;

int isFinalBoss(Employee* emp){
    return strcmp(emp->first_name, emp->boss->first_name)==0 && strcmp(emp->last_name, emp->boss->last_name)==0;
}

int isEqual(Employee* emp1, Employee* emp2){
    return strcmp(emp1->first_name, emp2->first_name)==0 && strcmp(emp1->last_name, emp2->last_name)==0;
}

int relation(Employee *employee1, Employee *employee2) {
    Employee tmp1 = *employee1, tmp2 = *employee2;
    Employee final1, final2; //存兩者最高boss
    while(!isFinalBoss(&tmp1)){
        tmp1 = *(tmp1.boss);
        if(isEqual(&tmp1, &tmp2))
            return 1; //subordinate
    }
    //此時tmp1 = final of emp1
    final1 = tmp1;
    tmp1 = *employee1;
    while(!isFinalBoss(&tmp2)){
        tmp2 = *(tmp2.boss);
        if(isEqual(&tmp1, &tmp2))
            return 2; //supervisor
    }
    final2 = tmp2;
    if(isEqual(&final1, &final2))
        return 3; //colleague
    else
        return 4; //unrelated
}