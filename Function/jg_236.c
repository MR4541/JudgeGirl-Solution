#include<stdio.h>

int LCM(int a, int b){
    int tmpa = a,tmpb = b;
    while((a%=b)&&(b%=a));
    return tmpa/(a+b)*tmpb;
}

int main(void){
    int tmplcm = 1;
    int num;
    while (scanf("%d",&num)!=-1){
        tmplcm = LCM(tmplcm, num); 
    }
    printf("%d\n",tmplcm);
    
}