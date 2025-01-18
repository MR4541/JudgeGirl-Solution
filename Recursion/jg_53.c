#include<stdio.h>
#include<stdlib.h>

int compareFunc(const void *a, const void *b){
    return *(int*)a > *(int*)b;
}

//from > to
void extract(int from, int to, int arr[]){
    int tmp = arr[from];
    for(int i = from-1; i >= to; i--)
        arr[i+1] = arr[i];
    arr[to] = tmp;
    return;
}

//from < to
void putback(int from, int to, int arr[]){
    int tmp = arr[from];
    for(int i = from; i < to; i++)
        arr[i] = arr[i+1];
    arr[to] = tmp;
    return;
}

void permutation(int i, int n, int arr[]){
    if(i == n-1){ //終止條件
        for(int j = 0; j < n; j++){
            printf("%d ", arr[j]);
        }
        printf("\n");
        return;
    }
    //讓每位都當一次頭看看
    permutation(i+1, n, arr);
    for(int j = i+1; j < n; j++){
        extract(j, i, arr);
        permutation(i+1, n, arr);
        putback(i, j, arr);
    }
    return;
}

int main(void){
    int n;
    scanf("%d", &n);
    int arr[10];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), compareFunc);
    permutation(0, n, arr);
}