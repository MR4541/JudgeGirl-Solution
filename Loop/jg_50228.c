#include<stdio.h>

#define MY_CC 5
#define AVERAGE_CC 5

int main(){
    int bestfrom = 0, bestdif = 0, bestcnt = 0, bestsum = 0;
    int from, dif, cnt, num, sum, prev_num;
    int n;
    scanf("%d%d", &n, &prev_num); //數字一
    cnt = 1;
    from = prev_num;
    bestcnt = 1; bestsum = prev_num; bestfrom = prev_num;
    if(n >= 2){
        scanf("%d", &num); //數字二（算出初始公差）
        cnt = 2;
        dif = num-prev_num;
        prev_num = num;
    }
    n -= 2;
    int pushflag; //是否更新最大值
    int tmp; //解決MLE
    while (n-->0){
        scanf("%d", &num);
        if(num - prev_num == dif){ //同一數列
            cnt++;
        }else{ //不同數列
            tmp = (2*from+(cnt-1)*dif);
            sum = tmp/2*cnt + (tmp%2)*cnt/2;
            tmp = (2*bestfrom+(bestcnt-1)*bestdif);
            bestsum = tmp/2*bestcnt + (tmp%2)*bestcnt/2;
            //printf("%d %d %d\n", sum, cnt, from);/////////////////////////////////////////////////////////////////
            if(sum>bestsum || ((sum==bestsum&&cnt>bestcnt) || (sum==bestsum&&(cnt==bestcnt&&from>bestfrom)))){
                //push
                bestsum = sum;
                bestfrom = from;
                bestcnt = cnt;
                bestdif = dif;
            }
            cnt = 2;
            from = prev_num;
            dif = num-prev_num;
        }
        prev_num = num; //push
    //  printf("%d %d %d nowcnt %d\n", bestsum, bestcnt, bestfrom, cnt);/////////////////////////
        
    }

    //結束再判斷一次
    tmp = (2*from+(cnt-1)*dif);
    sum = tmp/2*cnt + (tmp%2)*cnt/2;
    tmp = (2*bestfrom+(bestcnt-1)*bestdif);
    bestsum = tmp/2*bestcnt + (tmp%2)*bestcnt/2;
    if(sum>bestsum || ((sum==bestsum&&cnt>bestcnt) || (sum==bestsum&&(cnt==bestcnt&&from>bestfrom)))){
        //push
        bestsum = sum;
        bestfrom = from;
        bestcnt = cnt;
        bestdif = dif;
    }
    printf("%d %d %d\n", bestsum, bestcnt, bestfrom);
}
//test 10
//dif = 2 1~39999
//dif = 5 39999~139994              = 1 799 930 000
//dif = -4 139994~59998 這個        = 1 999 920 000
//dif = 3 59998~119995              = 1 799 930 000
//dif = -2 119995~79997             = 1 999 920 000
//除二之前爆int..