#include <stdio.h>

int GCD(int a, int b){
    int tmp;
    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
    }
    if (a % b == 0) return b;
    GCD(b, a%b);
}

int main(){
    int a,b,c,d,e,f,g;
    /*
        a(b/c) <d> e(f/g)
    */
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    int deno = c*g/GCD(c, g); //通分，分母=最小公倍數
    int nu1 = ((a>=0)? a*c + b : a*c - b) * deno / c; //通分
    int nu2 = ((e>=0)? e*g + f : e*g - f) * deno / g;

    int ansNu, ansDeno, _int, gcd; //帶分數輸出
    switch (d){
        case 0:
            ansNu = ((nu1 + nu2 >= 0)? 1:-1) * (nu1 + nu2); //恆正
            ansDeno = deno; //恆正
            _int = (nu1 + nu2) / deno; //有正有負
            gcd = GCD(ansNu, ansDeno); //約分用
            ansNu = (ansNu % deno) / gcd;
            ansDeno = ansDeno / gcd;
            break;
        case 1:
            ansNu = ((nu1 - nu2 >= 0)? 1:-1) * (nu1 - nu2); //恆正
            ansDeno = deno; //恆正
            _int = (nu1 - nu2) / deno; //有正有負
            gcd = GCD(ansNu, ansDeno); //約分用
            ansNu = (ansNu % deno) / gcd;
            ansDeno = ansDeno / gcd;
            break;
        case 2:
            ansNu = (nu1*nu2 >= 0)? nu1*nu2 : -nu1*nu2; //正
            ansDeno = deno*deno; //正
            _int = (nu1*nu2) / ansDeno; //有正有負
            gcd = GCD(ansNu, ansDeno); //約分用
            ansNu = (ansNu % ansDeno) / gcd;
            ansDeno = ansDeno / gcd;
            break;
        case 3:
            ansNu = (nu1<0)? -nu1: nu1;
            ansDeno = (nu2<0)? -nu2: nu2;
            _int = nu1 / nu2; //有正有負
            gcd = GCD(ansNu, ansDeno); //約分用
            ansNu = (ansNu % ansDeno) / gcd;
            ansDeno = ansDeno / gcd;
            break;
        default:
            printf("error!");
            return 0;
    }
    printf("%d\n%d\n%d\n", _int, ansNu, ansDeno);
}