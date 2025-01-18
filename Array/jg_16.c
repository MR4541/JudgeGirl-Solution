#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int tmp, odd[1000], even[1000], oddCnt = 0, evenCnt = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        if(tmp%2){
            odd[oddCnt] = tmp;
            oddCnt++;
        }else{
            even[evenCnt] = tmp;
            evenCnt++;
        }
    }
    for(int i = 0; i < oddCnt-1; i++) printf("%d ", odd[i]);
    printf("%d\n", odd[oddCnt-1]);
    for(int i = 0; i < evenCnt-1; i++) printf("%d ", even[i]);
    printf("%d\n", even[evenCnt-1]);
}