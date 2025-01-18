#include<stdio.h>

#define MY_CC 3
#define AVERAGE_CC 6.3

#define MIN(a, b) ((a) - ((a) - (b)) * ((a) > (b)))

int main(){
    int k;
    scanf("%d", &k);
    int vol[2*k]; //0~k-1 capacity k~2k-1 now
    for(int i = 0; i < 2*k; i++)
        scanf("%d", &vol[i]);
    int i, j, tmp, normalflag;
    while (scanf("%d%d", &i, &j) != EOF){
        vol[k+j] -= (vol[k+j]-vol[j])*(i == k);//fill j

        vol[k+i] -= (vol[k+i])*(j == k);//clear i

        normalflag = (i!=k && j!=k);
        tmp = vol[k + i] + vol[k + j]; //先把水都倒出來
        vol[k+j] -= (vol[k+j]-MIN(tmp, vol[j]))*(normalflag); //倒滿為止
        vol[k+i] -= (vol[k+i]+vol[k+j]-tmp)*(normalflag); //剩下的倒回去
    }
    for(int i = 0; i < k; i++){
        printf("%d ", vol[k + i]);
    }
    printf("\n");
    
}