#include<stdio.h>

main(){
    int i;
    scanf("%d", &i);
    int a,b,c;
    c = i%10;
    i/=10;
    b = i%10;
    i/=10;
    a=i;
    printf("%d\n%d\n%d\n",a,b,c);
}