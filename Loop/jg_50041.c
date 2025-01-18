#include<stdio.h>

#define Abs(x) ((x) - 2*(x)*((x)<0)) //define是直接換詞，所以要把輸入(x)，跟整個輸出都括弧起來避免誤判

int main(){
    int n;
    scanf("%d", &n);
    int prev_h, curr_h;
    int prev_isUp=0; //第一次的效果跟上次下坡一樣
    int cost=0;
    scanf("%d", &prev_h); //第一次=prev
    n--;
    while (n--)
    {
        scanf("%d", &curr_h);
        cost += Abs(curr_h - prev_h) * (2 + (curr_h>prev_h) + prev_isUp);

        prev_isUp = (curr_h-prev_h > 0);
        prev_h = curr_h;
    }

    printf("%d\n", cost);
     
}