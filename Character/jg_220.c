#include<stdio.h>

int main(){
    int flag = 0;
    int spaces = 0;
    int sensnt = 0;
    char c = '0';
    while(scanf("%c",&c) != EOF){
        //printf("%d ", c);//////////////////////////////////////////////////////
        if(flag){
            if((c == '\0' || c == '\n') && spaces == 0){
                sensnt++;
                spaces = 0;
                flag = 0;
                //printf("by ^z\n");//////////////////////////////////////////
            }else if (c == ' '){
                spaces++;
                if(spaces == 2){
                    sensnt++;
                    spaces = 0;
                    flag = 0;
                    //printf("by space\n");/////////////////////////////////
                }
            }else{
                spaces = 0;
                flag = 0;
            }
        }
        flag = (flag == 0 && c == '.') || (flag == 1);
    }
    printf("%d\n", sensnt);
}