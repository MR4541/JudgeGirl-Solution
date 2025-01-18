#include<stdio.h>

#define POS(a) ((a) * ((a) > 0))

int main(void){
    double a, b, c;
    scanf("%lf%lf%lf", &a,&b,&c);
    double area=0.0;
    double pi=3.1415926;
    area += 0.75*c*c*pi;
    area += 0.25*POS(c-b)*POS(c-b)*pi;
    area += 0.25*POS(c-a)*POS(c-a)*pi;
    printf("%f\n", area);
}