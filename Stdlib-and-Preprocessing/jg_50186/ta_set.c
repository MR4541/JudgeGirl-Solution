#include <stdio.h>
#include <stdbool.h>
#include "ta_set.h"

void initializeSet(ta_Set* set, int numberOfElemnet){
    set->num = 0;
    set->N = numberOfElemnet;
}
void addElement(ta_Set* set, int element){
    set->num |= 1ull << (element-1);
}
void removeElement(ta_Set* set, int element){
    set->num &= ~(1ull << (element-1));
}
void printSet(ta_Set set){
    int scanner = 1;
    for(int i = 0; i < set.N; i++){
        if(set.num & scanner) printf("%d ", i+1);
        scanner <<= 1;
    }
    printf("\n");
}
bool intersect(ta_Set set1, ta_Set set2){
    return (set1.num & set2.num) != 0;
}