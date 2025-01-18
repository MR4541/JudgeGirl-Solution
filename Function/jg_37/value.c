#include<stdio.h>

int GCD(int a, int b){
    while((a%=b)&&(b%=a));
    return a+b;
}

int value(int type, int width, int height, int length){
    int unit_price = 30*(type==79)+10*(type==47)+4*(type==29);
    unit_price += 5*(type==82)+3*(type==26)+9*(type==22);
    if(unit_price == 0) return -1;
    if(width<=0 || (height<=0 || length<0)) return -2;
    int gcd = GCD(width, GCD(height,length));
    return gcd*gcd*gcd*width*height*length*unit_price;
}

// int main(void){
//     int a,b,c,d;
//     scanf("%d%d%d%d",&a,&b,&c,&d);
//     printf("%d\n", value(a,b,c,d));
// }