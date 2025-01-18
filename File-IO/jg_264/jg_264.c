#include <stdio.h>

int main(){
    char filename[204];
    int n;
    int appear[65536] = {0}; //32767 + 32768 bias
    scanf("%s", filename);
    FILE* fp = fopen(filename, "rb");

    fread(&n, sizeof(int), 1, fp);
    // printf("%d\n", n);

    short num; //16-bit signed number
    for(int i = 0; i < n; i++){
        fread(&num, sizeof(short), 1, fp);
        appear[num + 32768]++;
    }

    int max_app = -1, max_i = -99999;
    for(int i = 0; i < 65536; i++){
        if(appear[i] >= max_app){
            max_app = appear[i];
            max_i = i - 32768;
        }
    }

    printf("%d\n%d\n", max_i, max_app);
}