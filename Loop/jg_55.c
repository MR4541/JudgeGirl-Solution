#include<stdio.h>

/*
x:0 ~ M-1   y:0 ~ N-1
Robot1 : X, Y, E, N, F
n > e > n > e
robot2: e > n > e > n
*/

void RobotWalk(int m, int n, int* x, int* y, int* f,int flag){ //flag1向東，0向北
    if(*f <= 0) return;
    *x += (flag!=0); *x *= (*x<m); //到m,n歸零
    *y += (flag==0); *y *= (*y<n);
    *f -= 1; //指標不能用--, ++
}

int main(){
    int m, n, x1, y1, e1, n1, f1, x2, y2, e2, n2, f2;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &m, &n, &x1, &y1, &e1, &n1, &f1, &x2, &y2, &e2, &n2, &f2);
    int time = 0, tmp1 = -n1, tmp2 = e2; //R1 east first, R2 north first, 用正負區分xy向
    while(f1>0 || f2>0){
        time++;
        RobotWalk(m, n, &x1, &y1, &f1, tmp1>0);
        RobotWalk(m, n, &x2, &y2, &f2, tmp2>0);
        //printf("%d %d %d %d %d %d %d %d %d %d %d %d\n", m, n, x1, y1, e1, n1, f1, x2, y2, e2, n2, f2); ////////////////////
        tmp1 += -(tmp1 > 0) + (tmp1 < 0) - (tmp1 == 1)*n1 + (tmp1 == -1)*e1; //e1->1 再從 -n1 -> -1
        tmp2 += -(tmp2 > 0) + (tmp2 < 0) - (tmp2 == 1)*n2 + (tmp2 == -1)*e2;
        //printf("R1(%d %d) R2(%d %d) fuel: %d / %d\n", x1, y1, x2, y2, f1, f2); ///////////////
        if(x1 == x2 && y1 == y2){
            printf("robots explode at time %d\n", time);
            return 0;
        }
    }
    printf("robots will not explode\n");
}