#include<stdio.h>
#include<string.h>

#define MY_CC 12
#define AVERAGE_CC 14.2

int StrToInt(char str[]){
    int ret = 0;
    for(int i = 0; i < strlen(str); i++){
        ret *= 10;
        ret += str[i] - '0';
    }
    return ret;
}

int main(void){
    char input[5002];
    char output[5002] = "";
    char tmp[50002]= ""; //存乘除法當前進度
    int n;
    int muldiv; //乘/除用tmp
    int divcnt;
    scanf("%d", &n);
    if(n == 0){
        printf("\n");
        return 0;
    }
    char opr;//+-*/
    int nowpm = 1; //現在是+ 1 - 0
    scanf("%s", tmp); //first word
    n--;

    int tmpstrlen; //因為strlen O(n),每次用不先存起來很容易tle
    int outputstrlen;
    while (n--){
        scanf(" %c%s", &opr, input);
        //printf("%c %s\n", opr, input);/////////////////
        
        //結算前面tmp
        if(opr=='+' || opr=='-'){
            //a - b +/-
            tmpstrlen = strlen(tmp);
            outputstrlen = strlen(output);
            if( nowpm == 0 &&(tmpstrlen <= outputstrlen&&
                strcmp(output+outputstrlen-tmpstrlen, tmp) == 0)){
                    strcpy(output+outputstrlen-tmpstrlen, "");
            }else if(nowpm == 1){ //a + b +/-
                strcat(output, tmp);
            }
            strcpy(tmp, input); //reset tmp
            nowpm = (opr == '+');
        }

        if(opr=='*'){
            muldiv = StrToInt(input);
            tmpstrlen = strlen(tmp);
            for(int i = muldiv*tmpstrlen; i >= 0; i--){ //把\0順便搬過去
                tmp[i] = tmp[i/muldiv];
            }
        }

        if(opr=='/'){
            muldiv = StrToInt(input);
            divcnt = 0;
            tmpstrlen = strlen(tmp);
            for(int i = 0; i < tmpstrlen; i+=muldiv){
                tmp[i/muldiv] = tmp[i];
                divcnt++;
            }
            tmp[divcnt] = '\0';//\0手動補
        }

        //printf("string:_%s_ and tmp:_%s_\n", output, tmp);////////////////////////////////////////////////////////
    }

    //結算前面tmp: -
    tmpstrlen = strlen(tmp);
    outputstrlen = strlen(output);
    if( nowpm == 0 &&(tmpstrlen <= outputstrlen&&
        strcmp(output+outputstrlen-tmpstrlen, tmp) == 0)){
            strcpy(output+outputstrlen-tmpstrlen, "");
    }else if(nowpm == 1){ //a + b +/-
        strcat(output, tmp);
    }
    //printf("string:_%s_ and tmp:_%s_\n", output, tmp);////////////////////////////////////////////////////////

    printf("%s\n", output);
}