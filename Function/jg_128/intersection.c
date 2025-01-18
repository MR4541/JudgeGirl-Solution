#include<stdio.h>
void intersection(int map[100][100], int result[4]){
    int adj1;
    int arr[102][102] = {{0}};
    result[0]=result[1]=result[2]=result[3]=0;
    for(int index = 0; index < 10000; index++)
        arr[index/100 + 1][index%100 + 1] = map[index/100][index%100];
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            adj1= (arr[i-1][j]==arr[i][j]) + (arr[i+1][j]==arr[i][j]);
            adj1+=(arr[i][j]==arr[i][j-1]) + (arr[i][j]==arr[i][j+1]);
            adj1*=arr[i][j];
            result[0]+=(adj1==4);
            result[1]+=(adj1==3);
            result[2]+=(adj1==2)*(arr[i-1][j]!=arr[i+1][j]);
            result[3]+=(adj1==1);
        }
    }
    return;
}

