#include<stdio.h>

#define MY_CC 4
#define AVERAGE_CC 6.21

int main(){
    int num = -1;
    int sum = 0;
    int tmp1 = 1, tmp2 = 0; //加法只用到tmp2, 乘法會把tmp1當prev存東西
    while (scanf("%d", &num) != EOF){
        if(num == 0) break;
        if(num == 8){ //plus
            sum += tmp2*tmp1;
            tmp2 = 0;
            tmp1 = 1;
            continue;
        }else if(num == 9){ //multiply
            tmp1 *= tmp2;
            tmp2 = 0;
            continue;
        }
        tmp2 = tmp2*10 + num; //n=1-7 
        //printf("s %d t1 %d t2 %d\n", sum, tmp1, tmp2);
    }
    printf("%d\n", sum + tmp2*tmp1); //最後一筆會沒加到
}