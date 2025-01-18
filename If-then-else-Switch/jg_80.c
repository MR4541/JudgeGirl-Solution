#include <stdio.h>

int main(){
    int a,b,c;
    int x1,y1, x2,y2, x3,y3;
    int n;
    scanf("%d", &n);
    for(int _ = 0; _ < n; _++){
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
        a = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        b = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
        c = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
        if((a==b)||(b==c)||(c==a))
            printf("isosceles\n");
        else if ((a+b<c)||(a+c<b)||(b+c<a))
            printf("obtuse\n");
        else if ((a+b==c)||(a+c==b)||(b+c==a))
            printf("right\n");
        else
            printf("acute\n");
    }
}