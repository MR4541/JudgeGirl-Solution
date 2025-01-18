#include <stdio.h>

int main(){
    int a,b,c,CPU,GPU,disk;
    scanf("%d%d%d", &a, &b, &c);
    CPU = (a-b+c)/2;
    GPU = (a+b-c)/2;
    disk = (-a+b+c)/2;
    printf("%d\n%d\n%d\n", disk, CPU, GPU);
}