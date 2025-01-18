#include <stdio.h>                                                                              

//#define DEBUG

// You can write your own functions here. 
 
void printBlock(unsigned long long int *block) {
    unsigned long long int tmp = *block;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            printf("%d", tmp&1);
            tmp >>= 1;
        }
        printf("\n");
    }
}
 
int moveLeft(unsigned long long int *block) { //全部/2
    unsigned long long int check = 72340172838076673;
    if(*block & check) return 0; // 撞牆invalid
    *block >>= 1; //向左移
    return 1;
}
 
int moveRight(unsigned long long int *block) {
    unsigned long long int check = 9259542123273814144;
    if(*block & check) return 0; //撞牆invalid
    *block <<= 1; //向右移
    return 1;
}
 
int moveUp(unsigned long long int *block) {
    if(*block & 255) return 0; //撞牆
    *block >>= 8; //向上移
    return 1;
}
 
int moveDown(unsigned long long int *block) {
    unsigned long long int check = 18374686479671623680;
    if(*block & check) return 0; //撞牆
    *block <<= 8; //向下移
    return 1;
}

void initialize(unsigned long long int *block, int row, int column, int size) {
    *block = 0;
    unsigned long long int tmp = 0;
    for(int i = 0; i < size; i++){
        *block <<= 8;
        *block += (1 << size) - 1;
    }

    for(int i = 0; i < row; i++){ //要移動row步
        // printf("Down ");
        moveDown(block);
    }
    for(int i = 0; i < column; i++){
        // printf("Right ");
        moveRight(block);
    }
    // printf("\n");
}

///////////////////////////////////////////////
#ifdef DEBUG
int main() {
    unsigned long long int num;
    char operation;
    int ret;
 
    scanf("%llu", &num);
 
    while (1) {
        ret = 1;
 
        scanf("%c", &operation);
 
        if (operation == 'p') {
            printBlock(&num);
            break;
        } else if (operation == 'u')
            ret = moveUp(&num);
        else if (operation == 'd')
            ret = moveDown(&num);
        else if (operation == 'l')
            ret = moveLeft(&num);
        else if (operation == 'r')
            ret = moveRight(&num);
        else if (operation == 'i') {
            int row, column, size;
            scanf("%d %d %d", &row, &column, &size);
            initialize(&num, row, column, size);
        }
 
        if (ret == 0)
            printf("Invalid move!\n");
    }
 
    return 0;
}
#endif