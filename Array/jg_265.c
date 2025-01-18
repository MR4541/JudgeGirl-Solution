#include<stdio.h>

#define MAX(a, b) ((a) - ((a) - (b)) * ((a) < (b)))
#define MIN(a, b) ((a) - ((a) - (b)) * ((a) > (b)))

int main(){
    int minx= 99999, maxx = -99999, miny = 99999, maxy = -99999;
    int x, y;
    while (scanf("%d%d", &x, &y) != EOF){
        minx = MIN(minx, x); maxx = MAX(maxx, x);
        miny = MIN(miny, y); maxy = MAX(maxy, y);
    }
    printf("%d\n", (maxx-minx)*(maxy-miny));
    
}