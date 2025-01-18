#include<stdio.h>
#include<string.h>

void PrintSpace(int n){
    for(int i = 0; i < n; i++)
        printf(" ");
}

int main(){
    int m;
    scanf("%d", &m);
    char word[130][260]; //一行最多單字數：256/(1字+1空白)=128
    int senlen = 0, wordcnt = 0; //句子長度, 該行已有單字數
    int vac, morevac; //（最少）要印多少空格, 前幾個空格要多印
    while (scanf("%s", word[wordcnt]) != EOF){
        if(senlen + wordcnt + strlen(word[wordcnt]) <= m){ //加上新值後最擠排版(1空格)可塞下
            senlen += strlen(word[wordcnt]);
            wordcnt++;
        }else{ //輸出舊行、換新行
            if(wordcnt == 1){ //特殊情況
                printf("%s", word[0]);
                PrintSpace(m-senlen);
                printf("\n");
                strcpy(word[0], word[1]); //因為歸零，輸入應該是word[0]
                senlen = strlen(word[0]);
                wordcnt = 1;
                continue;
            }
            vac = (m - senlen) / (wordcnt - 1); //所有字之間至少要輸入多少空格
            morevac = (m - senlen) % (wordcnt - 1);
            for(int i = 0; i < wordcnt; i++){
                printf("%s", word[i]);
                if(i < morevac){
                    PrintSpace(vac+1);
                }else if(i < wordcnt-1){ //i=wordcnt-1只要印字不要空白
                    PrintSpace(vac);
                }
            }
            printf("\n");
            strcpy(word[0], word[wordcnt]); //因為歸零，輸入應該是word[0]
            senlen = strlen(word[0]);
            wordcnt = 1;
        }
    }
    //處理最後一行
    if(wordcnt == 1){ //特殊情況
        printf("%s", word[0]);
        PrintSpace(m-senlen);
        printf("\n");
        strcpy(word[0], word[1]); //因為歸零，輸入應該是word[0]
        senlen = strlen(word[0]);
        wordcnt = 1;
        return 0;
    }
    vac = (m - senlen) / (wordcnt - 1); //所有字之間至少要輸入多少空格
    morevac = (m - senlen) % (wordcnt - 1);
    for(int i = 0; i < wordcnt; i++){
        printf("%s", word[i]);
        if(i < morevac){
            PrintSpace(vac+1);
        }else if(i < wordcnt-1){
            PrintSpace(vac);
        }
    }
    printf("\n");
}