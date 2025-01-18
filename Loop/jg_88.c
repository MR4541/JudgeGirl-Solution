#include<stdio.h>

int main(){
    int num1,num2;
    int dig1[4], dig2[4];
    int A = 0, B = 0;
    scanf("%d%d", &num1, &num2);
    for(int i = 0; i < 4; i++){
        dig1[i] = num1%10; num1 /= 10;
        dig2[i] = num2%10; num2 /= 10;
        if (dig1[i] == dig2[i]) A++;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if((dig1[i] == dig2[j])&&(j!=i)) B++;
        }
    }
    printf("%dA%dB", A, B);
    
}