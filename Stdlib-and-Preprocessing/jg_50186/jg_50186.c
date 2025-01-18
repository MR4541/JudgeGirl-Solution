#include<stdio.h>
#include"ta_set.h"

// #define LARGESTDICTIONARYORDER
// #define SMALLESTDICTIONARYORDER

void solve(ta_Set* now, ta_Set* best, ta_Set* T, int* bestSize, int size, int i, int n, int k, int maxElem[]){
    if(i > n+1) return;
    // printSet(*now);////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //cut
    for(int j = 0; i-1 >= maxElem[j] && j < k; j++)
        if(!intersect(*now, T[j])){
            // printf("cut!\n");
            return;
        }
    //solved check
    int solved = 1;
    for(int j = 0; j < k; j++){
        if(!intersect(*now, T[j])){
            // printf("!intersect!\n");
            solved = 0;
            break;
        }
    }
    if(solved){
        // printf("A valid Solution: ");
        // printSet(*now);
        #ifdef LARGESTDICTIONARYORDER
            if(size <= *bestSize){
                *best = *now;
                *bestSize = size;
                return;
            }
        #endif
        #ifdef SMALLESTDICTIONARYORDER
            if(size < *bestSize){
                *best = *now;
                *bestSize = size;
                return;
            }
        #endif
    }
    //放或不放
    addElement(now, i);
    solve(now, best, T, bestSize, size+1, i+1, n, k, maxElem);
    removeElement(now, i);
    solve(now, best, T, bestSize, size, i+1, n, k, maxElem);
    return;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    ta_Set T[100];
    for(int i = 0; i < k; i++) initializeSet(&T[i], n);
    int maxElem[100]; //存第T個set最大數字
    int size, num;
    for(int i = 0; i < k; i++){
        scanf("%d", &size);
        for(int _ = 0; _ < size; _++){
            scanf("%d", &num);
            addElement(&T[i], num);
            if(_ == size-1) maxElem[i] = num;
        }
        // printSet(T[i]);///////////////////////////////////////////////////////////
        // printf("MaxElem: %d\n", maxElem[i]);
    }

    ta_Set now, best;
    int bestSize = 10000;
    initializeSet(&now, n);
    solve(&now, &best, T, &bestSize, 0, 1, n, k, maxElem);
    printSet(best);
}