#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MY_CC 5
#define AVERAGE_CC 6.176

int translate(char chr){
    return (chr == '-'); //'-'==1, ' '==0
}

void IfNextNum(int* n, int* cnt, uint64_t* encoded_content){
    if(*cnt == 32){
        (*n)++;
        *cnt = 0;
        encoded_content[*n] = 0;
    }
}

void MorseEncode(int* n, char str[], uint64_t* encoded_content){
    char* MorseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", 
    "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; //對照表
    *n = 0;
    int cnt = 0; //每32次換下一個數
    encoded_content[0] = 0;
    char tmpchr[10];
    for(int index = 0; str[index] != '\0'; index++){
        for(int i = 0; MorseCodes[str[index]-'A'][i] != '\0'; i++){
            IfNextNum(n, &cnt, encoded_content); //檢測換數字
            encoded_content[*n] <<= 2; 
            encoded_content[*n] += translate(MorseCodes[str[index]-'A'][i]);
            cnt++;
        }
        if(str[index+1] != '\0'){ //補空格
            IfNextNum(n, &cnt, encoded_content);
            encoded_content[*n] <<= 2;
            encoded_content[*n] += 2; //' '
            cnt++;
        }else{ //補'\0'
            IfNextNum(n, &cnt, encoded_content);
            encoded_content[*n] <<= 2;
            encoded_content[*n] += 3; //'\0'
            cnt++;
        }
    }
    //最後一數後面補齊1
    for(int i = cnt; i < 32; i++){
        encoded_content[*n] <<= 2;
        encoded_content[*n] += 3;
    }
    (*n)++;

    // for(int _ = 0; _ < *n; _++){
    //     for(int i = 63; i >= 0; i--){
    //         printf("%llu", ((encoded_content[_]>>i)&1));
    //     }
    //     printf("\n");
    // }

}

/////////////////////////////////////////////////
// #define mxn 1010
 
// int main(){
//     char str[mxn];
//     scanf("%s", str);
 
//     int n = 0;
//     uint64_t encoded_content[mxn];
//     MorseEncode(&n, str, encoded_content);
 
//     for(int i = 0; i < n; i++)
//         printf("%llu ", encoded_content[i]);
//     return 0;
// }