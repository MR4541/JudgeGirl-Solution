#include<stdio.h>

#define ull (unsigned long long int)
#define MIN(a, b) ((a) - ((a) - (b)) * ((a) > (b)))

unsigned long long int makeColumn(int i){
    return 1<<i | 1<<i+8 | 1<<i+16 | ull 1<<i+24 | ull 1<<i+32 | ull 1<<i+40 | ull 1<<i+48 | ull 1<<i+56;
}

unsigned long long int diagonal1(){
    return 1 | (1<<9) | (1<<18) | (1<<27) | (ull 1<<36) | (ull 1<<45) | (ull 1<<54) | (ull 1<<63);
}

unsigned long long int diagonal2(){
    return (1<<7) | (1<<14) | (1<<21) | (1<<28) | (ull 1<<35) | (ull 1<<42) | (ull 1<<49) | (ull 1<<56);
}

int bingo(const unsigned long long int *board, int *rowColumn){
    int ret = 0;
    *rowColumn = 1<<10;
    //左上右下diagonal
    if((*board&diagonal1()) == diagonal1()){
        ret = 3; *rowColumn = 0;
    }else if((*board&diagonal2()) == diagonal2()){
        ret = 3; *rowColumn = MIN(1, *rowColumn);
    }

    //column
    for(int i = 7; i >= 0; i--){
            // printf("%llu\n", makeColumn(7-i));
        if((*board&makeColumn(7-i)) == makeColumn(7-i)){
            ret = 2;
            *rowColumn = i; //覆蓋過去diagnal
        }
    }

    //row
    for(int i = 7; i >= 0; i--){
             //printf("%llu\n", (unsigned long long int)255 << 8*(7-i));/////////
        if((*board&(unsigned long long int)255 << 8*(7-i)) == ((unsigned long long int)255 << 8*(7-i))){
            ret = 1;
            *rowColumn = i; //覆蓋column, diagonal
        }
    }

    return ret;
}

//////////////////////////////////////////////////////////////
    // int main(void)
    // {
    //     unsigned long long int board;
    //     int res = 0, rowColumn = 0;
    //     scanf("%llu", &board);
    //     res = bingo(&board, &rowColumn);
    //     if(res == 0) printf("no\n");
    //     else printf("%d %d\n", res, rowColumn);
    //     return 0;
    // }