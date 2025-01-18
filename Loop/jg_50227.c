#include<stdio.h>

#define MY_CC 4
#define AVERAGE_CC 4.5

void Swap(int *a, int *b){
    int tmp = *a;
    *a -= (*b > *a)*(*a - *b);
    *b -= (*b > tmp)*(*b - tmp); 
}

int main(){
    int sum1, sum2, sum3, sum4;
    scanf("%d%d%d%d", &sum1, &sum2, &sum3, &sum4);
    int d;
    for(int a = 4; a < 1000; a++){
        for(int b = 3; b < a && a*a*a*a+b*b*b*b<sum4; b++){
            for(int c = 2; c < b && a*a*a*a+b*b*b*b+c*c*c*c<sum4; c++){
                d = sum1-a-b-c;
                if(a*a+b*b+c*c+d*d==sum2 && a*a*a+b*b*b+c*c*c+d*d*d==sum3
                && a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d==sum4){
                    Swap(&c,&d);Swap(&b,&c);Swap(&a,&b); //排序d
                    printf("%d\n%d\n%d\n%d\n", a, b, c, d);
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
}