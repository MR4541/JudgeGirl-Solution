#include <stdio.h>
 
main(){
    int a,b, c,d, e,f, g,h;
    scanf("%d%d%d%d%d%d%d%d", &a,&b,&c,&d,&e,&f,&g,&h);
    int flag = 1;
    if(a*d - b*c <= 0) flag = 0;
    if(c*f - d*e <= 0) flag = 0;
    if(e*h - f*g <= 0) flag = 0;
    if(g*b - h*a <= 0) flag = 0;
    printf("%d", flag);
}
 
/*
題目是給逆時針座標，所以任兩個座標外積<0表示原點在四邊形外
*/