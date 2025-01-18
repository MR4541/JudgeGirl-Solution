#include<stdio.h>

//            陣列    還需多少k   現在i   最大   計算
int check(int arr[],int now_k,int i, int n, int cnt){
    // printf("%d %d %d\n", i, now_k, cnt);//////////////////////
    if(now_k == 0){
        // printf("sol: %d %d %d\n", i, now_k, cnt);
        return cnt+1; //有新的解
    }
    if(now_k < 0) return cnt; //沒有新的解
    if(i == n) return cnt; //沒有新的解；他要排到終止條件的最下面不然可能剛好選到最後一項有解的就吃不到
    //要選和不選
    return check(arr, now_k-arr[i], i+1, n, cnt) + check(arr, now_k, i+1, n, cnt);
}


int main(void){
    int n;
    scanf("%d", &n);
    int arr[15];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int k;
    while(scanf("%d", &k) != EOF){
        printf("%d\n", check(arr, k, 0, n, 0));
    }
}