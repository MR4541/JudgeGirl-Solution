#include<stdio.h>

int main(){
    int a1,a2,b1,b2,c1,c2;
    scanf("%d%d%d%d%d%d", &a1,&a2,&b1,&b2,&c1,&c2);
    printf("%d\n%d\n", b1+c1-a1, b2+c2-a2);
    printf("%d\n%d\n", -b1+c1+a1, -b2+c2+a2);
    printf("%d\n%d\n", b1-c1+a1, b2-c2+a2);
}