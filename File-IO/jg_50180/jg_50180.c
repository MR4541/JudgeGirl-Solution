#include<stdio.h>
#include<stdint.h>
#include<string.h>

void itos(char* buf, int i){
    if(i >= 10){
        buf[0] = '0' + i/10;
        buf[1] = '0' + i%10;
        buf[2] = '\0';
    }else{
        buf[0] = '0' + i%10;
        buf[1] = '\0';
    }
    return;
}

void combine(char* buf, char* a, int b){
    strcpy(buf, a);
    char b_str[4];
    itos(b_str, b);
    strcat(buf, b_str);
    return;
}

int main(void){
    int n;
    scanf("%d", &n);
    char preA[28], preB[28], preC[28];
    scanf("%s%s%s", preA, preB, preC);
    
    int A[30][30], B[30][30];
    int64_t C[30][30] = {{0}};
    char tmpName[100];
    for(int i = 0; i < n; i++){
        combine(tmpName, preA, i+1);
        FILE* fpA = fopen(tmpName, "rb");
        fread(A[i], sizeof(int32_t), n, fpA);
        fclose(fpA);
        combine(tmpName, preB, i+1);
        FILE* fpB = fopen(tmpName, "rb");
        fread(B[i], sizeof(int32_t), n, fpB);
        fclose(fpB);
    }
    
    //do matrix multiplication
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                C[i][j] += (int64_t)A[i][k]*B[k][j];
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++)
    //         printf("%d ", A[i][j]);
    //     printf("\n");
    // }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++)
    //         printf("%d ", B[i][j]);
    //     printf("\n");
    // }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++)
    //         printf("%ld ", C[i][j]);
    //     printf("\n");
    // }

    for(int i = 0; i < n; i++){
        combine(tmpName, preC, i+1);
        FILE* fpC = fopen(tmpName, "wb");
        fwrite(C[i], sizeof(int64_t), n, fpC);
        fclose(fpC);
    }

}
