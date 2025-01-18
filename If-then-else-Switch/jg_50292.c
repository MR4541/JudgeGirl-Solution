#include<stdio.h>

/*
     /  P2
    P1   /
*/

int main(){
    int x1,y1,x2,y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int qua1, qua2, qua3, qua4;
    qua1 = (x2 > 0)*(x2 - x1*(x1 > 0)) * (y2 > 0)*(y2 - y1*(y1 > 0));
    qua2 = (x1 < 0)*(x2*(x2 < 0) - x1) * (y2 > 0)*(y2 - y1*(y1 > 0));
    qua3 = (x1 < 0)*(x2*(x2 < 0) - x1) * (y1 < 0)*(y2*(y2 < 0) - y1);
    qua4 = (x2 > 0)*(x2 - x1*(x1 > 0)) * (y1 < 0)*(y2*(y2 < 0) - y1);
    printf("%d\n%d\n%d\n%d\n", qua1, qua2, qua3, qua4);
}


/*
From 財政廳：可用
#define MAX(x) ((x > 0)*x)
#define MIN(x) ((x < 0)*x)
作整流函數（只保留正/負值）簡化畫面
記得在外面包括號以免誤判
例如#define AA(x) x+x
會把3*AA(x)*2 變成3*x+x*2而非10x
*/