#include<stdio.h>

#define MAX(a, b) ((a) - ((a)-(b)) * ((a) < (b)))
#define MIN(a, b) ((a) - ((a)-(b)) * ((a) > (b)))

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int sum[m];
    int max[m];
    int min[m];
    for(int i = 0; i < m; i++){ //初始化
        sum[i] = 0;
        max[i] = -1;
        min[i] = 100000;
    }
    int num;
    while (n--){
        scanf("%d", &num);
        sum[num%m] += num;
        max[num%m] = MAX(max[num%m], num);
        min[num%m] = MIN(min[num%m], num);
    }
    for(int i = 0; i < m; i++){
        printf("%d %d %d\n", sum[i], max[i], min[i]);
    }
    
}