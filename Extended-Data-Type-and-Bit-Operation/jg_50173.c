#include<stdio.h>
#include<stdint.h>

void printMatrix(uint64_t *matrix){
    uint64_t tmp = *matrix;
    printf("%llu\n", *matrix);
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            printf("%d", tmp & 1);
            tmp >>= 1;
        }
        printf("\n");
    }
}

void rotateMatrix(uint64_t *matrix){
    uint64_t newmat = 0;
    uint64_t from;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            from = (uint64_t)1 << (i*8+j);
            newmat |= (uint64_t)((*matrix&from)!=0) << (8*j+(7-i));
        }
    }
    *matrix = newmat;
}

void transposeMatrix(uint64_t *matrix){
    uint64_t newmat = 0;
    uint64_t from;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            from = (uint64_t)1 << (i*8+j);
            newmat |= (uint64_t)((*matrix&from)!=0) << (8*j+i);
        }
    }
    *matrix = newmat;
}

////////////////////////////////////////////////////////////
// int main() {
//    uint64_t num;
//    char operation;
//    scanf("%llu", &num);
//    while (1) {
//        scanf("%c", &operation);
//        if (operation == 'p') {
//            printMatrix(&num);
//            break;
//        } else if (operation == 'r'){
//            rotateMatrix(&num);
//        }else if (operation == 't'){
//            transposeMatrix(&num);
//        }
//    }
//    return 0;
// }