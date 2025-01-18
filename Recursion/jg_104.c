#include<stdio.h>

int check(int cost[3][3], int num[3]){
    // printf("left %d %d %d\n", num[0], num[1], num[2]);
    if(num[0]==0 && (num[1]==0 && num[2]==0))
        return 1;
    if(num[0]<0 || (num[1]<0 || num[2]<0))
        return 0;
    num[0]-=cost[0][0]; num[1]-=cost[0][1]; num[2]-=cost[0][2]; //make 1
    int ret = check(cost, num);
    num[0]+=cost[0][0]-cost[1][0];num[1]+=cost[0][1]-cost[1][1];num[2]+=cost[0][2]-cost[1][2]; //restore + make 2
    ret = ret || check(cost, num);
    num[0]+=cost[1][0]-cost[2][0];num[1]+=cost[1][1]-cost[2][1];num[2]+=cost[1][2]-cost[2][2]; //restore + make 3
    ret = ret || check(cost, num);
    num[0]+=cost[2][0];num[1]+=cost[2][1];num[2]+=cost[2][2];
    return ret;
}

void loop(int i, int n, int num[3], int cost[3][3]){
    if(i==n) return;
    scanf("%d%d%d", &num[0], &num[1], &num[2]);
    if(check(cost, num))
        printf("yes\n");
    else
        printf("no\n");
    loop(i+1, n, num, cost);
}

int main(void){
    int cost[3][3];
    scanf("%d%d%d%d%d%d%d%d%d",&cost[0][0],&cost[0][1],&cost[0][2]
    ,&cost[1][0],&cost[1][1],&cost[1][2],&cost[2][0],&cost[2][1],&cost[2][2]);
    int n;
    scanf("%d", &n);
    int num[3];
    loop(0, n, num, cost);
}

