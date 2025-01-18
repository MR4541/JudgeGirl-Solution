#include <stdio.h>

main(){
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    int sur = 2*(a*b + b*c + a*c);
    int vol = a*b*c;
    printf("%d\n%d\n", sur, vol);
}