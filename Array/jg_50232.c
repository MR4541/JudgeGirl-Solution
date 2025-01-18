#include<stdio.h>

#define MY_CC 6
#define AVERAGE_CC 7.32

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int in[n][n];
    int filt[k][k];
    for(int index = 0; index < n*n; index++)
        scanf("%d", &in[index/n][index%n]);
    for(int index = 0; index < k*k; index++)
        scanf("%d", &filt[index/k][index%k]);
    int sum;
    for(int index = 0; index < (n-k+1)*(n-k+1); index++){
        sum = 0;
        for(int i = 0; i < k; i++)
            for(int j = 0; j < k; j++)
                sum += in[i+index/(n-k+1)][j+index%(n-k+1)]*filt[i][j];
        printf("%d", sum);
        if(index%(n-k+1) == n-k) printf("\n");
        else printf(" ");
    }
}