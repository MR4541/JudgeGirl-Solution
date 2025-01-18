#include <stdio.h>

int main(){
    int s,f,t;
    scanf("%d%d%d", &s, &f, &t);
    int a = -f/2 + 4*s - 2*t;
    int b = f/2 - 4*s + 3*t;
    int c = s - t;
    if (((a<0) || (b<0)) || ((c<0) || (f%2)))
        printf("0\n");
    else
        printf("%d\n%d\n%d\n", a,b,c);
}