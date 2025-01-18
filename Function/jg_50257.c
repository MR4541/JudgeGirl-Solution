#include<stdio.h>

#define MY_CC 1
#define AVERAGE_CC 1.68

int main(){
    int num, tmp;
    scanf("%d", &num);
    printf("%d\n", num);
    while(num != 1){
        tmp = (num/2)*(num%2==0) + (3*num+1)*(num%2==1);
        num = tmp;
        printf("%d\n", num);
    }
}