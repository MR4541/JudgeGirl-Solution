#include<stdio.h>
//#define DEBUG

/*
    有兩個n+2*n+2陣列prev, curr(使用index = 1-n)
    初始值給prev(0 or 1)
    每step
    curr = 0（死亡） or prev+1（紀錄活著的時間）
    最後把prev = curr;

    一開始再開一個陣列aliveTime紀錄每個格子有活的時間（不用連續）
    最後再比
*/

int prevAlive(int n, int prev[n+2][n+2], int i, int j){ //陣列名傳入的就是位址，所以不用弄指標
    int adjAlive = (prev[i-1][j-1]>0) + (prev[i-1][j]>0) + (prev[i-1][j+1]>0);
    adjAlive += (prev[i][j-1]>0) + (prev[i][j+1]>0);
    adjAlive += (prev[i+1][j-1]>0) + (prev[i+1][j]>0) + (prev[i+1][j+1]>0);
    return adjAlive;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int prev[n+2][n+2], curr[n+2][n+2]; //index 0, n+1作為外牆，值=0    
    int aliveTime[n+2][n+2];//格子活著的時間

    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < n+2; j++){
            aliveTime[i][j] = 0;
            if((j==0 || j==n+1) || (i==0 || i==n+1)){
                prev[i][j] = 0; //這是
                curr[i][j] = 0; //邊界
                continue;
            }
            scanf("%d", &prev[i][j]);
            if(prev[i][j] != 0) aliveTime[i][j]++; //step0也算
        }
    }

#ifdef DEBUG
    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < n+2; j++)
            printf("%d ", prev[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < n+2; j++)
            printf("%d ", curr[i][j]);
        printf("\n");
    }
#endif

    int tmpAdj; //紀錄鄰居數量
    while (k--){
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < n+1; j++){
                tmpAdj = prevAlive(n, prev, i, j);
                //printf("(%d %d) adj alive : %d\n", i, j, tmpAdj);/////////////
                if(prev[i][j]==0 && tmpAdj==3){ //復活
                    curr[i][j] = 1;
                    aliveTime[i][j]++;
                }else if(prev[i][j]>0 && (tmpAdj==2 || tmpAdj==3)){ //繼續存活
                    curr[i][j] = prev[i][j] + 1;
                    aliveTime[i][j]++;
                }else{ //死亡
                    curr[i][j] = 0;
                }
            }
        }

        //prev = curr
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < n+1; j++){
                prev[i][j] = curr[i][j];
            }
        }
    }   

#ifdef DEBUG
    printf("\n");
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            printf("%d", aliveTime[i][j]);
            if(j != n) printf(" ");
        }
        printf("\n");
    }
    printf("\n");
#endif

    //判斷活最多step的
    int maxStep, maxI, maxJ;

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            printf("%d", (prev[i][j]>0)); //這樣只會輸出0, 1
            if(j != n) printf(" ");

            if(aliveTime[i][j]>maxStep || (aliveTime[i][j]==maxStep && i>maxI) || (aliveTime[i][j]==maxStep && (i==maxI && j>maxJ))){
                maxStep = aliveTime[i][j];
                maxI = i;
                maxJ = j;
            }
        }
        printf("\n");
    }
    printf("%d %d\n", maxI, maxJ);
     
}