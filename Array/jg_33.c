#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int road[102][102] = {{0}}; //0剛好就是沒路
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &road[i][j]);
    int adj1 = 0;
    int inter=0, Tjunc=0, turn=0, dead=0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            adj1 = road[i][j]*(road[i-1][j] + road[i+1][j] + road[i][j-1] + road[i][j+1]);
            inter += (adj1 == 4); Tjunc+= (adj1 == 3);
            turn  += (adj1 == 2)*(road[i-1][j] != road[i+1][j]); //已保證四方向只有兩個1，加上後面那條可以篩掉直路 
            dead += (adj1 == 1);
            //if(adj1 == 2) printf("turn (%d %d)\n", i, j);
        }
    }
    printf("%d\n%d\n%d\n%d\n", inter, Tjunc, turn, dead);
}