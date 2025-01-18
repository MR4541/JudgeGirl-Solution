#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 101
#define MAXI 12
#define MAXLEN 65

//找食物名稱對應編號
int FindFood(char ingred[MAXN][MAXI][MAXLEN], char food[MAXLEN], int n){
    for(int i = 0; i < n; i++){
        if(strcmp(food, ingred[i][0]) == 0)
            return i;
    }
}

int CompareFunc(const void * a, const void * b){
    return strcmp(a, b); //如果a字典序大就會是正值(swap)
}

int main(void){
    char ingred[MAXN][MAXI][MAXLEN];//食材([i][0]是食物名)
    int n, k[MAXN];//每項用到幾個食材
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", ingred[i][0]);//食物名
        scanf("%d", &k[i]); //食材數量
        for(int j = 1; j <= k[i]; j++){
            scanf("%s", ingred[i][j]);//食材名
        }
        //把食材名按照字典序排
        qsort(ingred[i]+1, k[i], sizeof(char)*MAXLEN, CompareFunc);
    }

    int m;
    scanf("%d", &m);
    char food1[MAXLEN], food2[MAXLEN]; //食物名字
    int i1, i2;//兩項食物的index
    int p1, p2;//現在指到兩邊的哪一項食材
    int sameflag, cmpflag, spaceflag;
    //字典序小的往前、如果一樣就print然後一起往前
    while (m--){
        sameflag = 0;
        scanf("%s%s", food1, food2);
        i1 = FindFood(ingred, food1, n);
        i2 = FindFood(ingred, food2, n);
        p1 = 1; p2 = 1;
        spaceflag = 0;//是先印空白（第一次不印）
        while (p1 <= k[i1] && p2 <= k[i2]){//食材還沒比完
            cmpflag = strcasecmp(ingred[i1][p1], ingred[i2][p2]);
            //printf("comparing %s and %s\n", ingred[i1][p1], ingred[i2][p2]);//////////////
            //食材相同
            if(cmpflag == 0){
                if(spaceflag) printf(" ");
                printf("%s", ingred[i1][p1]);
                p1++; p2++;
                sameflag = 1;
                spaceflag = 1;
                //printf("1:[%d][%d] 2:[%d][%d]\n", i1, p1, i2, p2);////////////
            }else{
                p1 += (cmpflag < 0);
                p2 += (cmpflag > 0);
            }
        }
        if(sameflag == 0){//都沒重複的
            printf("nothing");
        }
        printf("\n");
    }
    //but egg flo sug
    //bac but egg ham
}