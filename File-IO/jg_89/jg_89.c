#include<stdio.h>

#define MAXN 65536

int main(){
    FILE* fin = fopen("test", "rb");
    FILE* fout = fopen("test.enc", "wb");
    int key, size_n; //size_n存每次吃到幾個byte
    char buffer[MAXN];

    scanf("%d", &key);
    while((size_n = fread(buffer, 1, MAXN, fin)) != 0){ //從fin每次最多讀MAXN個1byte資料並存到size_n，回傳已讀取的項目數
        for(int i = 0; i < size_n; i++){
            buffer[i] ^= key;
        }
        fwrite(buffer, sizeof(char), size_n, fout);
    }
    fclose(fout);
    fclose(fin);
}