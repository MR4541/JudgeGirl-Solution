#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int x1, y1;
    int a,b,c,d;
    scanf("%d%d", &x1, &y1);
    a = x1;
    b = y1;
    int sum = 0;
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &c, &d);
        sum += a*d - b*c;
        a = c;
        b = d;
    }
    sum += a*y1 - b*x1;
    printf("%d\n", sum);
    return 0;
}