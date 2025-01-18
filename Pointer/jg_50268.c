#include<stdio.h>

#define MY_CC 3
#define AVERAGE_CC 3.05

//#define MAX_PTR_ARR_SIZE 1000 
//#define MAX_ARR_SIZE 10000 //10000 會爆

int countIntersections(int* ptrArray[]){
    int cnt = 0;
    for(; ptrArray[cnt] != NULL; cnt++);

    int intersect = 0;
    for(int i = 0; i < cnt-1; i++)
        for(int j = i+1; j < cnt; j++){
            intersect += (ptrArray[i] > ptrArray[j]);
        }

    return intersect;
}

////////////////////////////////////////////
// int main(void) {
//     int array[MAX_ARR_SIZE];
//     int *ptrArray[MAX_PTR_ARR_SIZE];
//     for (int i = 0; i < MAX_ARR_SIZE; i++) {
//         array[i] = 0;
//     }
//     int n;
//     scanf("%d", &n);
//     int index[n];
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &index[i]);
//         ptrArray[i] = &array[index[i]];
//     }
//     ptrArray[n] = NULL;
//     int numIntersections = countIntersections(ptrArray);
//     printf("%d\n", numIntersections);
//     return 0;
// }