#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int i = 1;
    while (i<=n)
    {
        printf("%d\n", i);
        i ++;
    }
    i=n-1;
    while(i>0){
        printf("%d\n", i);
        i--;
    }
    
    
}