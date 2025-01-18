#include <stdio.h>
#include <stdbool.h>

main(){
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    bool flag = 1;
    if (a+b <= c) flag = 0;
    if (a+c <= b) flag = 0;
    if (b+c <= a) flag = 0;
    printf("%d\n", flag);
}