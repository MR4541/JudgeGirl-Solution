#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void* a, const void* b){
    return strcmp((char*)a, (char*)b);
}

int main(void){
    char strings[64][36];
    int n = 0;
    while(fgets(strings[n], 36, stdin) != NULL) n++;
    int lastStrLen = strlen(strings[n-1]);
    if(strings[n-1][lastStrLen-1] != '\n'){
        strings[n-1][lastStrLen] = '\n';
        strings[n-1][lastStrLen+1] = '\0';
    }

    qsort(strings, n, sizeof(char)*36, compare);
    for(int i = 0; i < n; i++){
        fputs(strings[i], stdout);
    }
}