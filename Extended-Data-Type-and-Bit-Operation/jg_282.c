#include<stdio.h>

int main(void){
    long long int num;
    int cnt;
    while (scanf("%lld", &num) != EOF){
        cnt = 0;
        while (num > 0){
            cnt += num&1;
            num >>= 1;
        }
        printf("%d\n", cnt);
    }
    
}