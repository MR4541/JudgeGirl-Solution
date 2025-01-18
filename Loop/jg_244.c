#include<stdio.h>

int main(){
    int prize_num[6]; //0-2 special 3-5 first prize
    int prize_digit[3][8]; //把輸入拆分成位數
    for(int i = 0; i < 6; i++){
        scanf("%d", &prize_num[i]);
        for(int j = 0; j < 8 && i > 2; j++){ //只需計算first prize的i=3-5, 記入i=0-2
            prize_digit[i-3][7-j] = prize_num[i]%10;
            prize_num[i]/=10;
        }
    }
    int sum = 0;
    int lottery_num, tmp_num, same_cnt;//當前號碼、有多少位重複
    while (scanf("%d", &lottery_num) != EOF){
        for(int i = 0; i < 3; i++){ //同步處理ith special, ith first
            if(lottery_num == prize_num[i]) sum += 2000000; //特別獎
            tmp_num = lottery_num; //初始化
            same_cnt = 0; //重置
            for(int j = 0; j < 8; j++){ //計算跟ith first有多少重複
                if(tmp_num%10 == prize_digit[i][7-j]) same_cnt++;
                else break;
                tmp_num /= 10;
            }
            switch(same_cnt){
                case 8:
                    sum += 200000;
                    break;
                case 7:
                    sum += 40000;
                    break;
                case 6:
                    sum += 10000;
                    break;
                case 5:
                    sum += 4000;
                    break;
                case 4:
                    sum += 1000;
                    break;
                case 3:
                    sum += 200;
                    break;
            }
        }
    }
    printf("%d\n", sum);
}