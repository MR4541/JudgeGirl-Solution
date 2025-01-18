#include <stdio.h>
#include <stdbool.h>
 
typedef struct set{
    unsigned long long num;
    int len;
}Set;
 
void initializeSet(Set* set, int numberOfElement);
bool intersect(Set set1, Set set2);
void addElement(Set* set, int element);
void removeElement(Set* set, int element);
void printSet(Set set);