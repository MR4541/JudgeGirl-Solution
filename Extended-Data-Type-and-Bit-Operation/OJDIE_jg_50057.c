#include<stdio.h>

#define MAXN 10002

#define OJ MLE但沒有testdata可以確認正確性

int main(void){
    int n;
    scanf("%d", &n);
    unsigned int arr[MAXN];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int cnt = 0, prev = (arr[0] & (1<<31)) != 0;
    int bit;
    for(int _ = 0; _ < n; _++){
        for(unsigned int i = 1<<31; i > 0; i>>=1){
            bit = (arr[_]&i)!=0;
            if(bit == prev){
                printf("%d", bit);
            }else{
                printf("\n");
                for(int space = 0; space < cnt%40; space++){
                    printf(" ");
                }
                printf("%d", bit);
                prev = bit;
            }
            cnt++;  
        }
    }
    printf("\n");
}