#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct {
    int balance;
    char name[128];
    int gender;
} Account;

int compare(const void* a, const void* b){
    Account* aa = (Account*)a;
    Account* ab = (Account*)b;
    return strcmp(aa->name, ab->name);
}

int main(void){
    char infile[1000], outfile[1000];
    scanf("%s%s", infile, outfile);
    Account acs[1024];
    int n = 0;
    Account tmp;
    FILE* fin = fopen(infile, "rb");
    while(fread(&tmp, sizeof(Account), 1, fin)){
        if(tmp.balance >= 0 && (tmp.gender == 0 || tmp.gender == 1)){ //check valid
            int lenName = strlen(tmp.name);
            int valid = 1;
            for(int i = 0; i < lenName; i++){
                if(!isalpha(tmp.name[i]) && tmp.name[i] != ' '){
                    valid = 0;
                    break;
                }
            }
            if(valid){
                acs[n] = tmp;
                n++;
            }
        }
    }
    fclose(fin);

    qsort(acs, n, sizeof(Account),compare);

    FILE* fout = fopen(outfile, "wb");
    fwrite(acs, sizeof(Account), n, fout);
    fclose(fout);
}