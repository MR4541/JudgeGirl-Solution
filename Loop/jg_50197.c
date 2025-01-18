#include<stdio.h>

#define MY_CC 4
#define AVERAGE_CC 5.1

//max(a, 0)
#define MAX(a) ((a) * ((a) > 0))
//min(a, 9)
#define MIN(a) (9 - (9 - (a)) * ((a) < 9))

int main(){
    int k;
    scanf("%d", &k);
    for(int a = 1; a <= 9; a++)
        for(int b = MAX(a-k); b <= MIN(a+k); b++)
            for(int c = MAX(b-k); c <= MIN(b+k); c++)
                for(int d = MAX(c-k); d <= MIN(c+k); d++)
                    printf("%d%d%d%d\n", a, b, c, d);
}