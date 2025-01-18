#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int m;
    scanf("%d", &m);

    int remain[200001] = {0}; //初始化全0
    for(int i = 0; i < n; i++){
        remain[arr[i]%m]++;
    }
    for(int i = 0; i < m; i++) printf("%d\n", remain[i]);
}