#include<stdio.h>

#define MY_CC 0
#define AVERAGE_CC 0.3

int main(){
    int w, a, b, c, d, e;
    scanf("%d%d%d%d%d%d", &w,&a,&b,&c,&d,&e);
    int length = a+b+c+2*d+2*e+2 - 2*(d - (d-e)*(d>e))*(b == 0);
    printf("%d\n", w*w + length*length);
}