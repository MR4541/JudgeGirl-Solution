#include<stdio.h>
#include<ctype.h>
#include<string.h>

int isvowel(char c){
    char C = toupper(c);
    return (C=='A'||(C=='E'||(C=='I'||(C=='O'||C=='U'))));
}

int main(void){
    char str[102];
    gets(str); //讀入直到換行/EOF，再把結果丟給char*參數（定義在stdio.h中）
    int digcnt = 0, vowcnt = 0, concnt = 0;
    for(int i = 0; i < strlen(str); i++){
        digcnt += (isdigit(str[i])!=0);
        vowcnt += isalpha(str[i]) && isvowel(str[i]);
        concnt += isalpha(str[i]) && !isvowel(str[i]);
    }
    printf("%d %d %d %d\n", digcnt, vowcnt+concnt, vowcnt, concnt);
}