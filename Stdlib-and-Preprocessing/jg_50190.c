#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
    Warning: 這道題目的sets[i]跟query兩個set, matched到的意思是
    query = sets[i]，而不是 query IN sets[i]
    不可能有人像我這麼蠢吧
    吧
    ：（
*/

typedef struct{
    int *num; // array, use malloc to save memory
    int size;
}Set;

int int_comp(const void *a, const void *b){
    return *(int*)a > *(int*)b;
}

int set_comp(const void *a, const void *b){
    Set* sa = (Set*)a;
    Set* sb = (Set*)b;
    int ia = sa->size-1, ib = sb->size-1;
    while(sa->num[ia] == sb->num[ib]){
        ia--; ib--;
        if(ia < 0 && ib < 0) return 0; //sa = sb: which is we want
        if(ia < 0) return -1; //sb is greater
        if(ib < 0) return 1;
    }
    return 2*(sa->num[ia] > sb->num[ib]) - 1;
}

// void printSets(Set* sets, int N){
//     for(int i = 0; i < N; i++){
//         for(int j = 0; j < sets[i].size; j++){
//             printf("%d ", sets[i].num[j]);
//         }
//         printf("\n");
//     }
// }

// int isSubset(Set* query, Set* set){
//     if(query->size != set->size) return 0;
//     int iq = query->size-1, is = set->size-1;
//     for(int i = 0; i < query->size; i++)
//         if(query->num[i] != set->num[i])
//             return 0;
//     return 1;
// }

int main(void){
    int N;
    scanf("%d", &N);
    Set* sets = (Set*)malloc(sizeof(Set)*N);
    for(int i = 0; i < N; i++){
        scanf("%d", &sets[i].size);
        sets[i].num = (int*)malloc(sizeof(int) * sets[i].size); //size = 1 ~ 1000, reduce overall size
        for(int j = 0; j < sets[i].size; j++){
            scanf("%d", &sets[i].num[j]);
        }
        qsort(sets[i].num, sets[i].size, sizeof(int), int_comp);
    }
    qsort(sets, N, sizeof(Set), set_comp);
    // printSets(sets, N);

    int M;
    scanf("%d", &M);
    Set* query = (Set*)malloc(sizeof(Set));
    for(int _ = 0; _ < M; _++){
        scanf("%d", &query->size);
        query->num = (int*)malloc(sizeof(int) * query->size);
        for(int i = 0; i < query->size; i++){
            scanf("%d", &query->num[i]);
        }
        qsort(query->num, query->size, sizeof(int), int_comp);

        int matched = 0;
        Set* found = bsearch(query, sets, N, sizeof(Set), set_comp);
        if(found == NULL)
            printf("-1\n");
        else{
            printf("%d\n", found - sets);
        }
        free(query->num);
    }
}