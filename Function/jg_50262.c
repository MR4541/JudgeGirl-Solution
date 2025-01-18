#include<stdio.h>

#define MY_CC 3
#define AVERAGE_CC 4.95

int Dist(int x1, int y1, int x2, int y2){
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

int main(){
    int n;
    scanf("%d\n", &n);
    int p[50000][3]; //本地端50000會爆, [][2]存dist
    for(int i = 0; i < n; i++)
        scanf("%d%d", &p[i][0], &p[i][1]);
    int x, y;
    scanf("%d%d", &x, &y);

    int mindist = 2147483647;
    for(int i = 0; i < n; i++){
        p[i][2] = Dist(x,y,p[i][0],p[i][1]);
        mindist -= (mindist-p[i][2]) * (p[i][2] < mindist); 
    }
    for(int i = 0; i < n; i++){
        if(mindist == p[i][2]) printf("%d\n", i);
    }
}