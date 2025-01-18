#include<stdio.h>

#define MAX(a, b) ((a) - ((a) - (b)) * ((a) < (b)))

int main(void){
    int num, cnt, max;
    while (scanf("%d", &num) != EOF){
        cnt = 0, max = 0;
        while (num > 0){
            if(num&1){
                cnt++;
                max = MAX(max, cnt);
            }else{
                cnt = 0;
            }
            num >>= 1;
        }
        printf("%d\n", max);
    }
    
}