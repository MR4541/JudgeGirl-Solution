#include<stdio.h>

main(){
    int s,f,t;
    scanf("%d%d%d", &s, &f, &t);
    int a = -f/2 + 4*s - 2*t;
    int b = f/2 - 4*s + 3*t;
    int c = s - t;
    printf("%d\n%d\n%d\n", a,b,c);
}

/*
    a+b+c = s
    2a+4b+8c = f
    a+b = t

    c = s-t
    2b = f-2t-8(s-t) = f-8s+6t
    b = 0.5f - 4s +3t
    a = -0.5f + 4s -2t
*/