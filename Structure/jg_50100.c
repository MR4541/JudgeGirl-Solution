#include<stdio.h>
#include<string.h>

typedef struct {
    char journalName[64];
    int numCitedPaper;
    int citedPaperIndex[1024];
} paper;

typedef struct {
    int paparNum;
    int citedCnt;
    char journalName[64];
} journal;

int findJournal(char* name, journal* jourOfTable, int journalCnt){
    //傳入&jourTable[0]，這樣既可以用指標傳遞journal物件，又保持jourTable不是指標
    for(int i = 0; i < journalCnt; i++, jourOfTable++){
        if(strcmp(name, jourOfTable->journalName) == 0)
            return i;
    }
    printf("find(): NOT FOUND!\n");
    return -1;
}

void compute(paper P[], int N){
    journal journalTable[1024] = {0, 0, ""}; //最慘可能一paper一雜誌
    int journalCnt = 0;
    //計算table, sort journal by name
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= journalCnt; j++){
            if(j == journalCnt){ //insert at end
                strcpy(journalTable[j].journalName, P[i].journalName);
                journalTable[j].paparNum = 1; 
                journalCnt++;
                // printf("%s Insert at end\n", journalTable[j].journalName);//////////////////////////////////////
                break;
            }else if(strcmp(P[i].journalName, journalTable[j].journalName) == 0){
                journalTable[j].paparNum ++;
                break;
            }else if(strcmp(P[i].journalName, journalTable[j].journalName) < 0){
                //把所有journal後移一位放他
                for(int k = journalCnt; k >= j+1; k--){
                    journalTable[k] = journalTable[k-1];
                }
                strcpy(journalTable[j].journalName, P[i].journalName);
                journalTable[j].paparNum = 1; 
                journalCnt++;
                // printf("%s Insert\n", journalTable[j].journalName);//////////////////////////////////////
                break;
            }
        }
    }
    ////////////////////////////////
    // for(int i = 0; i < journalCnt; i++){
    //     printf("%s %d/%d\n", journalTable[i].journalName, journalTable[i].citedCnt ,journalTable[i].paparNum);
    // }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < P[i].numCitedPaper; j++){
            // printf("%s ", journalTable[findJournal(P[P[i].citedPaperIndex[j]].journalName, journalTable, journalCnt)].journalName);
            journalTable[findJournal(P[P[i].citedPaperIndex[j]].journalName, journalTable, journalCnt)].citedCnt ++;
        }
        // printf("\n");
    }

    for(int i = 0; i < journalCnt; i++){
        printf("%s %d/%d\n", journalTable[i].journalName, journalTable[i].citedCnt ,journalTable[i].paparNum);
    }
}

/////////////////////////////////////////
// #define MAXP 100
// int main() {
//     int N;
//     paper P[MAXP] = {};
//     scanf("%d", &N);
//     for (int i = 0; i < N; i++) {
//         scanf("%s%d", P[i].journalName, &P[i].numCitedPaper);
//         for (int j = 0; j < P[i].numCitedPaper; j++)
//             scanf("%d", &P[i].citedPaperIndex[j]);
//     }
//     compute(P, N);
//     return 0;
//}