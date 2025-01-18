#include<stdio.h>

int main(void){
    int num, cnt;
    while (scanf("%d", &num) != EOF){
        cnt = 0;
        while (num > 0){
            cnt += num & 1;
            num >>= 1;
        }
        printf("%d\n", cnt);
    }
    
}