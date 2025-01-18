#include<stdio.h>

#define MY_CC 2
#define AVERAGE_CC 5.12

int LCM(int a, int b){ //最小公倍數
    int tmpa = a, tmpb = b;
    while((a%=b) && (b%=a)); //gcd = a+b
    return tmpa/(a+b)*tmpb;
}

int main(){
    int a,b,c,d;
    int lcm;
    while (scanf("%d%d%d%d", &a,&b,&c,&d) != EOF){
        lcm = LCM(a, LCM(b, LCM(c, d)));
        printf("%d\n", lcm/a);
    }
    
}