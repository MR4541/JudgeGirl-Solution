#include <stdio.h>
 
int main(){
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    int disc = (-a+b+c)/2;
    int CPU =  (a-b+c)/2;
    int GPU = (a+b-c)/2;
    printf("%d\n%d\n%d\n", disc, CPU, GPU);
}
 
/*
    disc CPU GPU
    disc = (-A+B+C)/2
 
*/