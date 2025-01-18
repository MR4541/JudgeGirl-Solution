#include <stdio.h>

#define MAX(a, b) ((a) - ((a) - (b)) * ((a) < (b)))

//回傳當前最大價值
int knapsack(int i, int n, int wLeft, int maxValueNow, int w[20], int v[20]){
    // printf("i %d ", i);///////////////////
    if(wLeft < 0) return 0; //不合法的裝法
    if(i>=n || wLeft==0) return maxValueNow; //遞回終點
    int pick = knapsack(i+1, n, wLeft-w[i], maxValueNow+v[i], w, v);
    int notpick = knapsack(i+1, n, wLeft, maxValueNow, w, v);
    int ret = pick > notpick ? pick : notpick;
    return ret;
}

int main(void){
    int n, m;
    scanf("%d%d", &n, &m);
    int w[20], v[20];
    for(int i = 0; i < n; i++)
        scanf("%d%d", &w[i], &v[i]);
    printf("%d\n", knapsack(0,n,m,0,w,v));
     
}