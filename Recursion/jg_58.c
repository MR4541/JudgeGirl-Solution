#include<stdio.h>
#include<stdlib.h>

#define MAXN 400

int compareFunc(const void * a, const void * b){
    return *(int*) a < *(int*) b;
}

void flood(int i, int j, int arr[MAXN+2][MAXN+2], int *sizeNow){
    if(arr[i][j] == 0) return;
    (*sizeNow)++;
    arr[i][j] = 0;
    flood(i+1, j, arr, sizeNow);
    flood(i-1, j, arr, sizeNow);
    flood(i, j+1, arr, sizeNow);
    flood(i, j-1, arr, sizeNow);
}

int main(void){
    int n, m;
    int graph[MAXN+2][MAXN+2] = {0}; //0表示land, 1-base
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &graph[i][j]);
    ///////////////////////////////////////
    // for(int i = 0; i <= n+1; i++){
    //     for(int j = 0; j <= m+1; j++)
    //         printf("%d ", graph[i][j]);
    //     printf("\n");
    // }

    int lakesize[MAXN*MAXN/2+1];
    int lakecnt = 0, tmpSize;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(graph[i][j]){
                tmpSize = 0;
                flood(i, j, graph, &tmpSize);
                lakesize[lakecnt] = tmpSize;
                lakecnt++;
            }
        }
    }
    qsort(lakesize, lakecnt, sizeof(int), compareFunc);
    for(int i = 0; i < lakecnt; i++){
        printf("%d\n", lakesize[i]);
    }
    
}