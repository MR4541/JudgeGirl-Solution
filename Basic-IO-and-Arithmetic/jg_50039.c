#include<stdio.h>

int main(){
    int a1,a2,a3,b1,b2,b3;
    scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &b1, &b2, &b3);
    printf("%d\n%d %d %d\n", a1*b1+a2*b2+a3*b3, a2*b3-b2*a3, a3*b1-a1*b3, a1*b2-a2*b1);
}