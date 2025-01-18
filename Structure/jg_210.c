#include<stdio.h>
#include<string.h>
#include<assert.h>

enum Field{LastName, FirstName, ID, Salary, Age};

typedef struct data{
    char lastname[84];
    char firstname[84];
    char ID[84];
    int salary;
    int age;
} Data;

int find(char* field, char* fieldtable[]){
    int i = 0;
    while (fieldtable[i] != NULL){
        if(strcmp(field, fieldtable[i]) == 0)
            return i;
        i++;
    }
    printf("Find(): Not Found\n");
    return -1;
    
}

//按照要求印出回覆
void printRes(Data person, int selectedFields[], int selectedCnt){
    for(int i = 0; i < selectedCnt; i++){
        switch (selectedFields[i]){
        case LastName:
            printf("%s ", person.lastname);
            break;
        case FirstName:
            printf("%s ", person.firstname);
            break;
        case ID:
            printf("%s ", person.ID);
            break;
        case Salary:
            printf("%d ", person.salary);
            break;
        case Age:
            printf("%d ", person.age);
        }
    }
    printf("\n");
    return;
}

int main(){
    Data people[52];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s%s%s%d%d", people[i].lastname, people[i].firstname, 
            people[i].ID, &people[i].salary, &people[i].age);
    }
        //printf("%s %s %s %d %d\n", people[2].lastname, people[2].firstname, 
          //  people[2].ID, people[2].salary, people[2].age);
    int m; //查詢筆數
    scanf("%d", &m);
    char select[84]; //用來assert
    char field[84]; //吃要輸出field
    char *fieldTable[6] = {"lastname", "firstname", "ID", "salary", "age", NULL}; //指向字串頭的char指標，所以不用[84]
    int selectedFields[8]; //依序存field經find完後的結果
    int selectedCnt; //要輸出多少field
    int condField; //存判斷條件的field
    char opr[5]; //吃判斷運算子
    char *oprTable[5] = {"==", "!=", ">", "<", NULL};
    int operator; //存運算子（0 == 1 != 2 > 3 <）
    char condstr[84]; int condint; //看判斷是str還是數字
    for(int _ = 0; _ < m; _++){
        scanf("%s", select);
        assert(strcmp(select, "select") == 0);
        scanf("%s", field);
        for(selectedCnt = 0; strcmp(field, "where") != 0; selectedCnt++){ //輸入直到看到where結束   
            selectedFields[selectedCnt] = find(field, fieldTable);
            scanf("%s", field);
        }
        //吃入判斷條件
        scanf("%s%s", field, opr);
        condField = find(field, fieldTable);
        operator = find(opr, oprTable);
        switch (condField){ //因為不同field要吃的型別不同
        case LastName: 
            scanf("%s", condstr);
            //開始查找符合條件的並印出
            for(int i = 0; i < n; i++){
                int tmp = (strcmp(people[i].lastname, condstr)==0);
                if(tmp ^ operator){ //tmp1 opr0 或是 tmp0 opr1
                    printRes(people[i], selectedFields, selectedCnt);
                }
            }
            break;
        case FirstName: 
            scanf("%s", condstr);
            //開始查找符合條件的並印出
            for(int i = 0; i < n; i++){
                int tmp = (strcmp(people[i].firstname, condstr)==0);
                if(tmp ^ operator){ //tmp1 opr0 或是 tmp0 opr1
                    printRes(people[i], selectedFields, selectedCnt);
                }
            }
            break;
        case ID: 
            scanf("%s", condstr);
            //開始查找符合條件的並印出
            for(int i = 0; i < n; i++){
                int tmp = (strcmp(people[i].ID, condstr)==0);
                if(tmp ^ operator){ //tmp1 opr0 或是 tmp0 opr1
                    printRes(people[i], selectedFields, selectedCnt);
                }
            }
            break;
        case Salary:
            scanf("%d", &condint);
            //開始查找符合條件的並印出
            for(int i = 0; i < n; i++){
                int tmp = ((operator==0)&(people[i].salary==condint)) || 
                    (((operator==2)&(people[i].salary>condint)) || ((operator==3)&(people[i].salary<condint)));
                if(tmp){
                    printRes(people[i], selectedFields, selectedCnt);
                }
            }
            break;
        case Age:
            scanf("%d", &condint);
            //開始查找符合條件的並印出
            for(int i = 0; i < n; i++){
                int tmp = ((operator==0)&(people[i].age==condint)) || 
                    (((operator==2)&(people[i].age>condint)) || ((operator==3)&(people[i].age<condint)));
                if(tmp){
                    printRes(people[i], selectedFields, selectedCnt);
                }
            }
            break;
        }
    }
}