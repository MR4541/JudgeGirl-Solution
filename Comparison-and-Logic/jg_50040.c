#include<stdio.h>

int main(){
    int m;
    scanf("%d", &m);
    printf("%d\n", (m>0 && m%2==0 ) && (m>10000 || m<1000));
}