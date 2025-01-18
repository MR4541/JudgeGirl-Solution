#include<stdio.h>
#include<stdlib.h>

#define MAXN 1000100

int compare(const void* a, const void* b){
    return *(int*)a > *(int*)b; //小到大
}

int main(void){
    int nP;
    scanf("%d", &nP);
    int* squDists = (int*)malloc(sizeof(int)*MAXN);
    for(int i = 0; i < nP; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        squDists[i] = x*x + y*y;
    }
    qsort(squDists, nP, sizeof(int), compare);

    int MaxCirDist = -1, MaxCirN = -1;
    int prevDist = -1, prevN = 0;
    for(int i = 0; i < nP; i++){
        if(prevDist != squDists[i]){ //new circle
            if(prevN >= MaxCirN){
                MaxCirDist = prevDist;
                MaxCirN = prevN;
            }
            prevN = 1;
        }else{
            prevN++;
        }
        prevDist = squDists[i];
    }
    if(prevN >= MaxCirN){
        MaxCirDist = prevDist;
    }

    printf("%d\n", MaxCirDist);
}