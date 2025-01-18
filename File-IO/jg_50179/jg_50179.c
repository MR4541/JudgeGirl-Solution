#include<stdio.h>

typedef unsigned char uc;

void combine(char* buf, char* str1, int i){
    sprintf(buf, "%s%d", str1, i);
    return;
}


int main(void){
    char infile[52], outfile_prefix[52];
    int N;
    scanf("%s%d%s", infile, &N, outfile_prefix);
    int size[12] = {0}; //size of every outfile, 1-base
    /*
        吃到255：決定下次要開ab誰
        不是255：繼續寫現在檔案
    */
    uc num;
    FILE* fin = fopen(infile, "rb");
    char outfile[100];
    combine(outfile, outfile_prefix, 1);
    int out_now = 1;
    FILE* fout = fopen(outfile, "ab");
    while(fread(&num, sizeof(uc), 1, fin)){
        if(num == 255){
            fclose(fout);
            int minSize = size[1];
            out_now = 1;
            for(int i = 2; i <= N; i++){
                if(size[i] < minSize){
                    out_now = i;
                    minSize = size[i];
                }
            }
            combine(outfile, outfile_prefix, out_now);
            fout = fopen(outfile, "ab");
        }else{
            fwrite(&num, sizeof(uc), 1, fout);
            size[out_now]++;
        }
    } 
}