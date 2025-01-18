#include<stdio.h>

/*
每loop：算gold 移動 檢查teleport fuel--
跳出回圈後再算一次gold
*/

int Abs(int n){
    return n - 2*n*(n<0);
}

int GoldAt(int x, int y, int c, int d, int e, int p, int q, int r, int s){ //傳送點gold為零
    if((x==p && y==q) || (x==r && y==s)) return 0;
    return Abs(c*x + d*y) % e;
}

int main(){
    int a, b, c, d, e, p, q, r, s, x, y, F;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &p, &q, &r, &s, &x, &y, &F);
    //printf("%d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, p, q, r, s, x, y, F);
    int tolGold = 0, dir; //獲得gold總量, 移動方向
    while(F > 0){
        tolGold += GoldAt(x, y, c, d, e, p, q, r, s); //算gold

        dir = Abs(a*x + b*y) % 4; //move
        switch (dir){
        case 0:
            y++; break;
        case 1:
            x++; break;
        case 2:
            y--; break;
        case 3:
            x--; break;
        }

        //teleport
        if(x == p && y == q){
            x = r; y = s;
        }else if(x == r && y == s){
            x = p; y = q;
        }

        F--;
    }
    tolGold += GoldAt(x, y, c, d, e, p, q, r, s); //結束地也算gold
    printf("%d\n%d %d\n", tolGold, x, y);
}