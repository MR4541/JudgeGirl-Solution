#include<stdio.h>

int main(){
    int r, c;
    scanf("%d%d", &r, &c);
    int arr[r][c];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);

    int flag;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            flag = 1;
            if(i>0) flag *= (arr[i][j] > arr[i-1][j]);
            if(i<r-1) flag *= (arr[i][j] > arr[i+1][j]);
            if(j>0) flag *= (arr[i][j] > arr[i][j-1]);
            if(j<c-1) flag *= (arr[i][j] > arr[i][j+1]);
            if(flag) printf("%d\n", arr[i][j]);
        }
    }
}