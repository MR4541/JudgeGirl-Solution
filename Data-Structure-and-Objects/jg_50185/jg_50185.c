#include <stdio.h>
#include <stdbool.h>
 
typedef struct set{
    unsigned long long num;
    int len;
}Set;
 
void initializeSet(Set* set, int numberOfElement){
    set->num = 0;
    set->len = 0;
}
bool intersect(Set set1, Set set2){
    return set1.num & set2.num;
}
void addElement(Set* set, int element){
    if((set->num & (1ull<<(element-1))) == 0) set->len++;
    set->num |= 1ull<<(element-1);
}
void removeElement(Set* set, int element){
    if((set->num & (1ull<<(element-1))) != 0){
        set->len--;
        set->num ^= (1ull<<(element-1));
    }
}
void printSet(Set set){
    unsigned long long scanner = 1;
    for(int i = 0; i < 64; i++){
        if(set.num & scanner)
            printf("%d ", i+1);
        scanner <<= 1;
    }
    printf("\n");
}

////////////////////////////////////////////////////////////// 
// int main(){
//     Set s1, s2;
//     int numberOfElement = 5;
//     initializeSet(&s1, numberOfElement);
//     initializeSet(&s2, numberOfElement);
 
//     addElement(&s1, 1);
//     addElement(&s1, 3);
//     addElement(&s2, 1);
//     addElement(&s2, 5);
 
//     if(intersect(s1, s2))
//         printf("intersect!\n");
// }