#include<stdio.h>

main(){
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    int sur=2*(a*b+b*c+c*a) + 8*d*(a+b+c-6*e);
    int vol=a*b*c - 2*d*((a-2*e)*(b-2*e) + (b-2*e)*(c-2*e) + (c-2*e)*(a-2*e));
    printf("%d\n%d\n", sur, vol);
}