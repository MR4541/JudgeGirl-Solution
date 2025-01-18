#include<stdio.h>
#include<string.h>
#include<ctype.h>

//不印
int OmitPrint(char str[130]){
    int dotflag = (str[strlen(str)-1]=='.');
    if(dotflag) str[strlen(str)-1] = '\0';
    int ret = (strcmp(str, "of")==0 || strcmp(str, "and")==0) ||
              (strcmp(str, "the")==0 || strcmp(str, "at")==0);
    str[strlen(str)] -= (str[strlen(str)] - '.')*(dotflag); //如果dotflag觸發，會把.變成\0，所以length會-=1
    return ret;
}

int main(void){
    char toPrint[130];
    char nowStr[130];
    int printCnt = 0;
    while (scanf("%s", nowStr) != EOF){
        //if(nowStr[0]=='-' && nowStr[1]=='1') break;

        if(!OmitPrint(nowStr)){
            toPrint[printCnt] = toupper(nowStr[0]);
            printCnt++;
        }
        if(nowStr[strlen(nowStr) - 1] == '.'){
            //printf("Aaaaaaaaa\n");/////////////////
            //printf("nowStr : %s\n", nowStr);/////////////////
            //一行結束：輸出toPrint
            for(int i = 0; i < printCnt; i++){
                printf("%c", toPrint[i]);
            }
            printf("\n");
            printCnt = 0;
        }
    }
    
}