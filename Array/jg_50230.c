#include<stdio.h>

#define MY_CC 4
#define AVERAGE_CC 5.6

#define MAX_S 100000 //本機跑100000會爛，測試開10000

int Hash(int k, int S){
    return (77*k + 2222) % S;
}

int main(){
    int S, C;
    scanf("%d%d", &S, &C);
    int table[MAX_S][10]; 
    int cnt[MAX_S] = {0}; //紀錄table[i]有現在有多少值
    int num, index, inTable;
    while (scanf("%d", &num) != EOF){
        index = Hash(num, S);
        inTable = 0;
        for(int j = 0; j < cnt[index]; j++){
            if(table[index][j] == num){ //delete and print
                printf("%d %d\n", num, index);
                for(int dj = j+1; dj < cnt[index]; dj++){ //把被刪掉值後所有值位置往前一位
                    table[index][dj-1] = table[index][dj];
                }
                inTable = 1;
                cnt[index]--;
                break;
            }
        }
        
        //push queue
        table[index][cnt[index]] -= (table[index][cnt[index]] - num)*(!inTable);
        cnt[index] += (!inTable); 
    }
    
}