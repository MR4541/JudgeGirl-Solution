#include<stdio.h>

#define MY_CC 1
#define AVERAGE_CC 1.25

int main(){
    int n;
    scanf("%d", &n);
    int x, y, w, h, prevx, prevy, prevw, prevh;
    int area = 0;
    scanf("%d%d%d%d", &prevx, &prevy, &prevw, &prevh);
    area += prevw * prevh;
    n--;
    while (n--){
        scanf("%d%d%d%d", &x,&y,&w,&h);
        area += w*h - (prevx+prevw-x)*(prevy+prevh-y);
        prevx = x; prevy = y;
        prevw = w; prevh = h;
    }
    printf("%d\n", area);
}