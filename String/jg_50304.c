#include<stdio.h>
#include<string.h>
#include<stdint.h>

int find(char* str, char* table[]){
    int index = 0;
    while(table[index] != NULL){
        if(strcmp(table[index], str) == 0)
            return index;
        index++;
    }
    return -2; //'?' = 'A' - 2
}

void MorseDecode(int n, const uint64_t encoded_content[] ,char ans[]){
    char* MorseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
            "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
            ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", NULL};
    int bits; //存近兩位結果
    char tmp[30] = ""; //存. - space
    int anslen = 0, tmplen = 0;
    for(int i = 0; i < n; i++){
        for(int cnt = 31; cnt >= 0; cnt--){
            bits = (encoded_content[i] & (3ull << (cnt*2))) >> (cnt*2);
            // printf("%d ", bits);
            if(bits == 3){
                ans[anslen] = 'A' + find(tmp, MorseCodes);
                ans[++anslen] = '\0';
                tmp[0] = '\0';
                tmplen = 0;
                return; //decode結束
            }else if(bits == 2){ //space
                ans[anslen] = 'A' + find(tmp, MorseCodes);
                ans[++anslen] = '\0';
                tmp[0] = '\0';
                tmplen = 0;
            }else{
                tmp[tmplen] = (bits==0)? '.' : '-';
                tmp[++tmplen] = '\0';
            }
        }
    }
    return;
}

// //////////////////////////////////////////////////
// int main() {
//     int n;
//     scanf("%d", &n);
 
//     uint64_t encoded_content[1010];
//     for (int i = 0; i < n; i++)
//         scanf("%llu", &encoded_content[i]);
 
//     char ans[1010];
//     MorseDecode(n, encoded_content, ans);
 
//     printf("%s\n", ans);
//     return 0;
// }