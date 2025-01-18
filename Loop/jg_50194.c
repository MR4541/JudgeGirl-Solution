#include<stdio.h>

#define MY_CC 5
#define AVERAGE_CC 6.21

int LengthOfDigit(int n){
    int ret = 0;
    while (n!=0){
        n/=10;
        ret++;
    }
    return ret;
    //因為不會輸入0所以不用處理特例
}

int PrintN(int n, int k){
    for(int i = 0; i < (n%k); i++)
        printf("%d", n);
}

int main(){
    int k,L,n;
    scanf("%d%d", &k, &L);
    scanf("%d", &n);
    int spaceLeft = L; 
    while (n!=0){
        //換行也輸不下直接ignore
        if(LengthOfDigit(n)*(n%k) <= spaceLeft){ //同一行裝的下
            PrintN(n, k);
            spaceLeft -= LengthOfDigit(n)*(n%k);
        }else if(LengthOfDigit(n)*(n%k) <= L){ //換行裝的下
            printf("\n");
            PrintN(n, k);
            spaceLeft = L - LengthOfDigit(n)*(n%k);
        }

        scanf("%d", &n);
    }
    
}