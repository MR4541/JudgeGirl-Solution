#include<stdio.h>

#define MY_CC 2
#define AVERAGE_CC 3.82

int main(){
    int num;
    scanf("%d", &num);
    int sign = 1 - 2*(num<0);
    int cnt = 1;
    int flag = 0; //壓CC用
    while (scanf("%d", &num) != EOF){
        flag = (num*sign > 0);
        cnt += flag;
        if(!flag)
            printf("%d ", sign*cnt);
        sign -= 2*sign*(!flag);
        cnt -= (cnt-1)*(!flag);
    }
    printf("%d\n", sign*cnt);
    
}