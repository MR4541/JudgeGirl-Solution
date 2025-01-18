#include<stdio.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n%d\n", (b-a+1)*(b+a)/2, (b-a-1)*2 + a + b);
}