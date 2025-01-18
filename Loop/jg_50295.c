#include<stdio.h>
#include<stdlib.h>

#define MY_CC 8
#define AVERAGE_CC 13.9
//#define DEBUG

int MaxToMin(const void * a, const void * b){ //a<b會觸發swap：由大排到小
    return (*(int*) a < *(int*) b);
}
int MinToMax(const void * a, const void * b){ //a>b會觸發swap：由小排到大
    return (*(int*) a > *(int*) b);
}

int main(){
    int m, C; //物品數、桶子容量
    scanf("%d%d", &m, &C);
    int bin[3][1000] = {{0}}; //三種方法的bin，每桶各裝了多少東西
    int bestFitCnt = 1; //三種方法各用了幾個桶子
    int firstFitCnt = 1;
    int worstFitCnt = 1;
    int size; //物品重量
    while (m--){
        scanf("%d", &size);
        //best-fit: 每次放完直接扔qsort，由大排到小
        for(int i = 0; i < bestFitCnt; i++){
            if(C - bin[0][i] >= size){
                bin[0][i] += size; //加到桶子
                break;
            }
            if(i==bestFitCnt-1 && C - bin[0][i] < size){ //現有的桶子都裝不下了
                bestFitCnt++;
                bin[0][i+1] = size; //開新桶子
                break;
            }
        }
        qsort(bin[0], bestFitCnt, sizeof(int), MaxToMin);//重新排序桶子

        //first-fit
        for(int i = 0; i < firstFitCnt; i++){
            if(C - bin[1][i] >= size){
                bin[1][i] += size; //加到桶子
                break;
            }
            if(i==firstFitCnt-1 && C - bin[1][i] < size){ //現有的桶子都裝不下了
                firstFitCnt++;
                bin[1][i+1] = size;//開新桶子 
                break;
            }
        }

        //worst-fit: 一樣做完排序，但值由小到大，只要bin_2_0（空間最大）不合就直接開new
        if(C - bin[2][0] >= size){
            bin[2][0] += size;
        }else{
            worstFitCnt++;
            bin[2][worstFitCnt-1] = size; //新一桶
        }
        qsort(bin[2], worstFitCnt, sizeof(int), MinToMax); //升冪排序
        
#ifdef DEBUG
        printf("best fit:");
        for(int i = 0; i < bestFitCnt; i++)
            printf(" %d", bin[0][i]);
        printf("\n");
        printf("first fit:");
        for(int i = 0; i < firstFitCnt; i++)
            printf(" %d", bin[1][i]);
        printf("\n");
        printf("worst fit:");
        for(int i = 0; i < worstFitCnt; i++)
            printf(" %d", bin[2][i]);
        printf("\n");
#endif
    }
    printf("%d %d %d\n", bestFitCnt, firstFitCnt, worstFitCnt);
}