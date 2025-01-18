#include<stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    double mat[16][16];
    double y[16];
    for(int index = 0; index < n*n; index++)
        scanf("%lf", &mat[index/n][index%n]);
    for(int i = 0; i < n; i++)
        scanf("%lf", &y[i]);
    double x[16] = {0.0};
    double tmp;
    for(int i = n-1; i >= 0; i--){
        tmp = y[i];
        for(int j = i+1; j < n; j++)
            tmp -= mat[i][j]*x[j];
        x[i] = tmp / mat[i][i];
    }
    for(int i = 0; i < n; i++)
        printf("%f\n", x[i]);
}