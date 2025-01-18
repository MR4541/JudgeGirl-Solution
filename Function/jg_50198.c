#include<stdio.h>

#define MY_CC 3
#define AVERAGE_CC 7.42

int Check(int num){
    int dig1 = num%10, dig2 = -1;
    num /= 10;
    int tmp;
    int ret = 1;
    while (num != 0){
        tmp = num%10;
        ret *= !((tmp != dig1 && tmp != dig2) && dig2 != -1); //ture = return 0;
        dig2 -= (dig2-tmp)*(tmp != dig1 && tmp != dig2);
        num /= 10;
    }
    return ret;
}

int main(){
    int a, b, x;
    while (scanf("%d%d%d", &a, &b, &x) != EOF){
        while (!Check(x)) x = (a*x) % b;
        printf("%d\n", x);
    }
    
}