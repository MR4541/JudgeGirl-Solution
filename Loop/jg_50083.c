#include<stdio.h>

int main(){
    int A,B,R; //兩桶剩餘容量、Rule
    scanf("%d%d%d", &A, &B, &R);
    int tmp; //球重
    while (scanf("%d", &tmp) != EOF){
        if(R == 0){ //first fit
            if(tmp <= A) A-=tmp;
            else if(tmp <= B) B-=tmp;
        }else{ //best fit
            if(B < A && B >= tmp) B-=tmp;
            else if(A >= tmp) A-=tmp;
            else if(B >= tmp) B-=tmp;
        }
        printf("%d %d\n", A, B);
    }
    
}