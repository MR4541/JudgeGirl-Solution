#include<stdio.h>
#include<ctype.h>

int main(void){
    char str[102] = "";
    int cnt[26] = {0};
    scanf("%s", str);
    //printf("%s\n", str);
    for(int i = 0; i < 102 && str[i] != '\0'; i++){
        cnt[toupper(str[i]) - 'A'] += (isalpha(str[i])!=0);
        //if(isalpha(str[i])) printf("str[%d] = %c\n", i, str[i]);
    }
    for(int i = 0; i < 26; i++) printf("%d\n", cnt[i]);
}