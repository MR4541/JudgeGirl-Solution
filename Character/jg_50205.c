#include<stdio.h>

#define MY_CC 3
#define AVERAGE_CC 6.46

int map(char chr){
    return (chr=='!') + 2*(chr=='@') + 3*(chr=='#') + 4*(chr=='$') + 5*(chr=='%')
    + 6*(chr=='^') + 7*(chr=='&') + 9*(chr=='(');
}

int main(){
    char chr;
    int sum = 0;
    int tmp1 = 1, tmp2 = 0; //加法只用到tmp2, 乘法會把tmp1當prev存東西
    while (scanf("%c", &chr) != EOF){
        //if(chr == 'S') break;
        if(chr == '+'){ //plus
            sum += tmp2*tmp1;
            tmp2 = 0;
            tmp1 = 1;
            continue;
        }else if(chr == '*'){ //multiply
            tmp1 *= tmp2;
            tmp2 = 0;
            continue;
        }
        tmp2 = tmp2*10 + map(chr); //n=0-7, 9
        //printf("s %d t1 %d t2 %d\n", sum, tmp1, tmp2);
    }
    printf("%d\n", sum + tmp2*tmp1); //最後一筆會沒加到
}