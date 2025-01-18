#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct locks {
    int n;
    int sensor[100][3];
} Locks;
 
Locks* init(int lockSeq[][3], int n){
    Locks* L = (Locks*)malloc(sizeof(Locks));
    L->n = n;
    for(int i = 0; i < n; i++){
        L->sensor[i][0] = lockSeq[i][0];
        L->sensor[i][1] = lockSeq[i][1];
        L->sensor[i][2] = lockSeq[i][2];
    }
    return L;
}
 
int numUnlocked(Locks *locks, bool lights[], int m){
    int ret = 0;
    for(int i = 0; i < locks->n; i++){
        for(int j = 0; j < 3; j++){
            if((locks->sensor[i][j]>0 && lights[locks->sensor[i][j]-1]) ||
               (locks->sensor[i][j]<0 && !lights[-locks->sensor[i][j]-1])){
                ret++;
                break;
            }
        }
    }
    return ret;
}