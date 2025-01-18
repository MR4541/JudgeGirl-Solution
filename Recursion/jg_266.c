#include<stdio.h>
#include<string.h>

int min(int a, int b){
    return (a > b) ? b : a;
}

void DistOf(char a[], char b[], int *nowDist, int minDist){
    if(*nowDist >= minDist) return;
    if(a[0] == '\0'){
        *nowDist = strlen(b);
        return;
    }
    if(b[0] == '\0'){
        *nowDist = strlen(a);
        return;
    }   
    if(a[0] == b[0]){
        DistOf(a+1, b+1, nowDist, minDist); 
        return; //same first letter
    }
    //min of two
    int tmp = *nowDist;
    DistOf(a+1, b, nowDist, minDist);
    DistOf(a, b+1, &tmp, minDist);
    *nowDist = 1 + min(*nowDist, tmp);
    return;
}

int main(){
    char arr[104][16];
    int n = 0;
    for(; scanf("%s", arr[n]) != EOF; n++);
    int minDist = 100, mini = -1, minj = -1;
    int tmpDist;
    //因為是輸出最小ID，只要minDist<Now再更新就好
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            tmpDist = 0;
            DistOf(arr[i], arr[j], &tmpDist, minDist);
            if(tmpDist < minDist){
                minDist = tmpDist;
                mini = i; minj = j;
            }
        }
    }
    printf("%d %d %d\n", minDist, mini+1, minj+1);
}