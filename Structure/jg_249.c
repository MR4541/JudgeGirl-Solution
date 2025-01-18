#include<stdio.h>
#include<string.h>

typedef struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
}Employee;

int findID(Employee* person, Employee people[], int n){
    for(int i = 0; i < n; i++){
        if(strcmp(person->first_name, people[i].first_name) == 0
        && strcmp(person->last_name, people[i].last_name) == 0)
            return i;
    }
    printf("FindName: Not Found\n");
    return -1;
}

Employee findBoss(int nextid, Employee people[], int n){
    for(int i = 0; i < n; i++){
        if(nextid == people[i].id)
            return people[i];
    }
    printf("FindID: Not Found\n");
    Employee empty;
    return empty;
}

int checkBoss(Employee sub, Employee boss, Employee people[], int n){ //嘗試sub是否為boss下屬
    //i是index，跟id是不一樣東西
    int sub_i = findID(&sub, people, n);
    int boss_i = findID(&boss, people, n);
    Employee tmpboss;
    while(people[sub_i].id != people[sub_i].boss_id){ //id==boss_id是老闆（終點）
        tmpboss = findBoss(people[sub_i].boss_id, people, n);
        sub_i = findID(&tmpboss, people, n); //subid = its boss's id
        if(sub_i == boss_i)
            return 1;
    }
    return 0;
}

int checkCollege(Employee emp1, Employee emp2, Employee people[], int n){ //最上頭boss一樣且不是上下屬就是
    int emp1_i = findID(&emp1, people, n);
    int emp2_i = findID(&emp2, people, n);\
    Employee tmpboss;
    while(people[emp1_i].id != people[emp1_i].boss_id){
        tmpboss = findBoss(people[emp1_i].boss_id, people, n);
        emp1_i = findID(&tmpboss, people, n); //subid = its boss's id
    }
    while(people[emp2_i].id != people[emp2_i].boss_id){
        tmpboss = findBoss(people[emp2_i].boss_id, people, n);
        emp2_i = findID(&tmpboss, people, n); //subid = its boss's id
    }
    if(emp1_i == emp2_i)
        return 1;
    else
        return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    Employee people[35];
    for(int i = 0; i < n; i++){
        scanf("%d%s%s%d", &people[i].id, people[i].first_name, people[i].last_name, &people[i].boss_id);
    }
    //printf("%s %s\n", people[2].first_name, people[2].last_name);//
    int q;
    scanf("%d", &q);
    Employee tmpEmp;
    Employee tmpEmp2;
    while (q--){
        scanf("%s%s", tmpEmp.first_name, tmpEmp.last_name);
        scanf("%s%s", tmpEmp2.first_name, tmpEmp2.last_name);
        if(checkBoss(tmpEmp, tmpEmp2, people, n))
            printf("subordinate\n");
        else if(checkBoss(tmpEmp2, tmpEmp, people, n))
            printf("supervisor\n");
        else if(checkCollege(tmpEmp, tmpEmp2, people, n))
            printf("colleague\n");
        else
            printf("unrelated\n");
        // printf("< %d > %d\n", checkBoss(tmpEmp, tmpEmp2, people, n), checkBoss(tmpEmp2, tmpEmp, people, n));
    }
}