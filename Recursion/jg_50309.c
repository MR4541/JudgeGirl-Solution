#include<stdio.h>
 
#define MY_CC 7
#define AVERAGE_CC 6.823 
 
int maxGroupSum(int k, int group[4][12], int groupcnt[4]){
    int tmpmax = 0, tmp;
    for(int i = 0; i < k; i++){
        tmp = 0;
        for(int j = 0; j < groupcnt[i]; j++){
            tmp += group[i][j];
        }
        tmpmax = (tmp > tmpmax)? tmp : tmpmax;
    }
    return tmpmax;
}
 
void partition(int i, int k, int n, int arr[12], int group[4][12], int groupcnt[4], int *minSum){
    if(i == n){
        int tmp = maxGroupSum(k, group, groupcnt);
        *minSum = (*minSum < tmp)? *minSum : tmp;
        return;
    }
    //try to put item in each group
    for(int g = 0; g < k; g++){
        group[g][groupcnt[g]] = arr[i];
        groupcnt[g]++;
        partition(i+1, k, n, arr, group, groupcnt, minSum);
        groupcnt[g]--;
    }
}
 
int main(void){
    int n, k;
    scanf("%d%d", &n, &k);
    int arr[12];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int minSum = 1e9;
    int group[4][12];
    int groupcnt[4] = {0};
    partition(0, k, n, arr, group, groupcnt, &minSum);
    printf("%d\n", minSum);
}