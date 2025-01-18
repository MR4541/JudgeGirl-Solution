#include<stdio.h>

//看他人解法的

int main(){
    int k;
    scanf("%d", &k);
    int curr = 0, prev = 0; //當前與上一次數字(1 / -1)
    int set = 0; //連續組數（正正反反正正=3組）
    int cnt = 0; //連續相同數字數
    int ans_set = 0; //存最大組數
    //int length=0; //計算測資長度用/////////////////////////////////////
    scanf("%d", &curr);
    while (curr != 0){
        //length++;//////////////////////////////////////
        //第一個數會跑到else，會有cnt=1，所以不用處理
        curr = (curr > 0)? 1 : -1;
        if(curr == prev){ //同號
            cnt++;
            if(curr == 1 && cnt > k){ //當前是正數且連續正數超過（斷Com）
                if(set >= 2 && set+1 > ans_set) //已經滿足一組以上正負，且包含斷掉的這次總組數創新高
                    ans_set = set + 1;
            }
        }else { //異號
            if(cnt == k){ //剛好=k
                set ++;
                cnt = 1;
            }else if(cnt > k && prev == 1){ //超過k，但是是正數就只剩一組正
                set = 1;
                cnt = 1;
            }else{ //爛了...歸零
                set = 0;
                cnt = 1;
            }
        }
        ans_set = ((set > ans_set && set%2) && set > 1)? set : ans_set; //更新，set=3,5,7,..才算合法
        //printf("set/ans: %d %d ", set, ans_set); ///////////////////
        prev = curr; //準備下一輪
        scanf("%d", &curr);
    }
    
    if(prev == 1 && cnt >= k && set%2 == 0 && set >= 2 && set+1 > ans_set){ //此條件下會剛好沒更新到
        ans_set = set+1; //同if(prev==curr)
        //printf("cnt %d, k %d\n",cnt,k);//////////////////////
    }
    
    //重新檢查k, cnt，為處理例外：對k>1，由負換到正一個，然後是0結束，會造成set多跑2，所以要扣回來
    if(ans_set==set && k>cnt){
        ans_set -= 2;
        //printf("minus\n");
    }

    printf("%d\n", ans_set*k);
    
}