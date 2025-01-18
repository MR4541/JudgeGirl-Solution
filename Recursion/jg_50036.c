#include<stdio.h>

void solve(int i, int k, int N, int M, int arr[], int* kNow, int* MNow, int* cnt, int takeLastTime){ //上次沒有拿就不能判斷cnt
    // printf("\ni %d MNOW %d", i, *MNow);///////////////////
    if(takeLastTime && *kNow >= k && *MNow <= M){
        (*cnt)++; //valid
        // printf(" [SOL]");/////////////////    
    }
    if(i == N) return;
    if(*MNow > M) return; //剪枝
    (*kNow)++; *MNow += arr[i]; //取i
    solve(i+1, k, N, M, arr, kNow, MNow, cnt, 1);
    (*kNow)--; *MNow -= arr[i]; //不取i
    solve(i+1, k, N, M, arr, kNow, MNow, cnt, 0);
    return;
}

int main(){
    int k, N, M;
    int arr[20];
    scanf("%d%d%d", &k, &N, &M);
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
    int MNow = 0, kNow = 0;
    int cnt = 0;
    solve(0, k, N, M, arr, &kNow, &MNow, &cnt, 0);
    printf("%d\n", cnt);
}