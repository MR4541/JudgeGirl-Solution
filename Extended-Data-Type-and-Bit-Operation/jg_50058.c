#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int word[22] = {0}; //第i lsb存是否有第i字母
    int cost[22] = {0};
    char str[52];
    for(int i = 0; i < n; i++){ //處理輸入
        scanf("%s%d", str, &cost[i]);
        for(int pos = 0; str[pos] != '\0'; pos++){
            word[i] = word[i] | (1 << (str[pos]-'a'));
        }
    }

    int maxn = 1<<n; //遍歷所有組合，其中bit是1代表要取
    int mincost = 2147483647;
    int tmpcost, tmpwordsum;
    for(int i = 1; i < maxn; i++){
        tmpcost = 0; tmpwordsum = 0;
        for(int test = 0; test < n; test++){ //取出test-th 資料
            if(i&(1<<test)){ //要取他
                tmpcost += cost[test];
                tmpwordsum = tmpwordsum | word[test];
            }
        }
        if(tmpwordsum == (1<<26)-1){ //有整組
            mincost = (tmpcost < mincost)? tmpcost : mincost;
        }
    }
    printf("%d\n", mincost);
    // printf("%d %d %d %d\n", word[0], word[1], word[0] | word[1], (1<<26)-1);//////////
}