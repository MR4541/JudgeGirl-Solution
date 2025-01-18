#include<stdio.h>

#define MY_CC 22 Ugly-Code
#define AVERAGE_CC 16.3 -> 27.5扣分

//#define DEBUG

#define MAXN 106 //106本地會爆
#define MAX(a, b) ((a) - ((a) - (b)) * ((a) < (b)))

int Hash(int k, int S){
    return (77*k+2222) % S;
    //return k%S;
}

void TableAdd(int table[MAXN*MAXN][10], int cnt[MAXN*MAXN], int num, int S){
    if(num == 0) return; //空值
    int tmphash = Hash(num, S);
    table[tmphash][cnt[tmphash]] = num;
    cnt[tmphash] += 1;
    return;
}

//刪掉num
void TableDelete(int table[MAXN*MAXN][10], int cnt[MAXN*MAXN], int num, int S){
    int tmphash = Hash(num, S);
    //刪掉第一個num
    for(int i = 0; i < cnt[tmphash]; i++){
        if(table[tmphash][i] == num){
            for(int j = i+1; j < cnt[tmphash]; j++){ //後面往前一格
                table[tmphash][j-1] = table[tmphash][j];
            }
            cnt[tmphash]-=1;
            break;
        }
    }
    //刪掉第二個num
    for(int i = 0; i < cnt[tmphash]; i++){
        if(table[tmphash][i] == num){
            for(int j = i+1; j < cnt[tmphash]; j++){ //後面往前一格
                table[tmphash][j-1] = table[tmphash][j];
            }
            cnt[tmphash]-=1;
            break;
        }
    }
}

void PopTower(int tower[MAXN][MAXN][MAXN], int i, int j){
    int tmplayer = 0;
    while (tower[tmplayer][i][j] != 0){
        //printf("loop ");////////////////////////////
        tower[tmplayer][i][j] = tower[tmplayer+1][i][j];
        tmplayer++;
    }
}

int main(void){
    int N,S,C; 
    scanf("%d%d%d", &N, &S, &C);
    int tower[MAXN][MAXN][MAXN] = {{{0}}}; //每個k都是>=1，0表示為空
    int table[MAXN*MAXN][10] = {{0}};
    int cnt[MAXN*MAXN] = {0}; //紀錄每table有多少數字
    int tmphash;
    //輸入：讓每ij值優先填到layer=0,1,2...，每次pop都把後面值往前一格
    for(int layer = 0; layer < N; layer++){ //第layer層有layer^2個數字
        for(int i = 0; i <= layer; i++){
            for(int j = 0; j <= layer; j++){
                scanf("%d", &tower[layer-MAX(i, j)][i][j]);
                if(layer-MAX(i, j) == 0){ //表示tower i/j在最上面，加到table
                    TableAdd(table, cnt, tower[layer-MAX(i, j)][i][j],S);
                }
            }
        }
    }

#ifdef DEBUG
    for(int layer = 0; layer < N; layer++){ //第layer層有layer^2個數字
        for(int i = 0; i < N-layer; i++){
            for(int j = 0; j < N-layer; j++){
                printf("%8d ", tower[layer][i][j]);
            }printf("\n");
        }
    }
    printf("Hash Cnt:");
    for(int hashi = 0; hashi < S; hashi++)
        printf("%d ", cnt[hashi]);
    printf("\n");
#endif

    //第一次找出重複數字+爆搜找出兩數字位置 > pop, add new to table
    int same_num = 0;
    for(int hashi = 0; hashi < S; hashi++){ //找重複數字
        for(int u = 0; u < cnt[hashi]; u++){ //如果u,v超過table[hashi]大小就可以直接停止
            for(int v = u+1; v < cnt[hashi]; v++){
                same_num -= (same_num - table[hashi][u])*(table[hashi][u]==table[hashi][v]); //如果相等
                //printf("hash u %d v %d\n", table[hashi][u], table[hashi][v]);//////////////////////////////////////////
            }
        }
        if(same_num != 0) break; //已經找到了
    }
    //找位置+pop
    int pos1=-1, pos2=-1; //posi = pos/N, posj = pos%N
    int tmplayer, i, j;
    for(int index = 0; index < N*N; index++){
        i = index/N; j = index%N;
        if(tower[0][i][j] == same_num){
            pos2 += (1+index)*(pos1 != -1); //pos1已經有值
            pos1 += (1+index)*(pos1 == -1);
            //pop+push
            TableDelete(table, cnt, same_num, S);
            PopTower(tower, i, j);
        }
    }
    printf("%d ", same_num);
    TableAdd(table, cnt, tower[0][pos1/N][pos1%N], S); //把新點加入
    TableAdd(table, cnt, tower[0][pos2/N][pos2%N], S);

#ifdef DEBUG
    for(int layer = 0; layer < N; layer++){ //第layer層有layer^2個數字
        for(int i = 0; i < N-layer; i++){
            for(int j = 0; j < N-layer; j++){
                printf("%8d ", tower[layer][i][j]);
            }printf("\n");
        }
    }
    printf("Hash Cnt:");
    for(int hashi = 0; hashi < S; hashi++)
        printf("%d ", cnt[hashi]);
    printf("\n");
    printf("pos1 %d pos2 %d\n", pos1, pos2);
#endif

    //後面：新兩個數字其中一個必是新重複 > 找tower[0][i][j] > 找到就pop, add new｜直到有一輪沒找到結束
    int num1, num2, PairFlag=1; //是否有找到pair 
    while (PairFlag){
        PairFlag = 0; //後面如果都沒觸發就沒了
        num1 = tower[0][pos1/N][pos1%N]; //新值
        num2 = tower[0][pos2/N][pos2%N]; //新值
        //printf("num1 %d num2 %d\n", num1, num2);/////////////////////////////////////////////////////////
        for(int index = 0; index < N*N; index++){ //嘗試消掉一組
            i = index/N; j = index%N;
            //printf("tower[%d][%d] = %d\n", i, j, tower[0][i][j]); /////////////////////////////////////////////
            //找pos有無重複
            if((num1 != 0 && tower[0][i][j] == num1) && (i!=pos1/N || j!=pos1%N)){ //num1是重複
                TableDelete(table, cnt, num1, S);
                PopTower(tower, i, j);
                PopTower(tower, pos1/N, pos1%N);
                pos2 = index; //pos1 = pos1;
                PairFlag = 1;
                printf("%d ", num1);
                break;
            }
            if((num2 != 0 && tower[0][i][j] == num2) && (i!=pos2/N || j!=pos2%N)){ //num2是重複
                TableDelete(table, cnt, num2, S);
                PopTower(tower, i, j);
                PopTower(tower, pos2/N, pos2%N);
                pos1 = index; //pos2 = pos2;
                PairFlag = 1;
                printf("%d ", num2);
                break;
            }
        }


#ifdef DEBUG
    for(int layer = 0; layer < N; layer++){ //第layer層有layer^2個數字
        for(int i = 0; i < N-layer; i++){
            for(int j = 0; j < N-layer; j++){
                printf("%8d ", tower[layer][i][j]);
            }printf("\n");
        }
    }
    printf("Hash Cnt:");
    for(int hashi = 0; hashi < S; hashi++)
        printf("%d ", cnt[hashi]);
    printf("\n");
    printf("pos1 %d pos2 %d\n", pos1, pos2);
#endif
    }
    printf("\n");
}
