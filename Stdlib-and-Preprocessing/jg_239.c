#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Expense{
    int y, m, d;
    char category[36];
    unsigned int amount;
}Expense;

int compare(const void* ptra, const void* ptrb){
    Expense *a = (Expense*)ptra;
    Expense *b = (Expense*)ptrb;
    if(a->y != b->y) return a->y > b->y;
    if(a->m != b->m) return a->m > b->m;
    if(a->d != b->d) return a->d > b->d;
    return strcmp(a->category, b->category);
}

int main(void){
    int n = 0;
    Expense list[10000];
    Expense tmp;
    while(scanf("%d%d%d%s%d", &tmp.y, &tmp.m, &tmp.d, tmp.category, &tmp.amount) != EOF){
        int newflag = 1;
        for(int i = 0; i < n; i++){
            if(list[i].y == tmp.y && list[i].m == tmp.m && list[i].d == tmp.d && strcmp(list[i].category, tmp.category) == 0){
                list[i].amount += tmp.amount;
                newflag = 0;
                break;
            }
        }
        if(newflag){
            list[n] = tmp;
            n++;
        }
    }

    // for(int i = 0; i < n; i++) printf("%d %d %d %s %d\n", list[i].y, list[i].m, list[i].d, list[i].category, list[i].amount);

    qsort(list, n, sizeof(Expense), compare);
    for(int i = 0; i < n; i++) printf("%d %d %d %s %d\n", list[i].y, list[i].m, list[i].d, list[i].category, list[i].amount);
}