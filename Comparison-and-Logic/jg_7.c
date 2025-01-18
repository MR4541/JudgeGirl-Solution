#include<stdio.h>
#include<stdbool.h>

main(){
    int n;
    scanf("%d", &n);
    bool flag = ((n%15 == 0)&&(n%7 != 0))? false : true;
    printf("%d\n", flag);
}