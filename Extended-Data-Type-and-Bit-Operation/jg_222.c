#include<stdio.h>

#define ulli unsigned long long int

int inShelf(unsigned int num, ulli shelf){
    int index = 0;
    while(shelf > 0){
        if(shelf%(1<<8) == num) //在架上
            return index;
        shelf >>= 8;
        index++;
    }
    return -1;
}

int main(){
    ulli shelf = 0; //空書架
    unsigned int num;
    int inflag;
    ulli tmpshelf; unsigned int tmpnum;//用來搬書
    while (scanf("%u", &num) != EOF){
        //if(num == -1) break;/////////////////////
        
        inflag = inShelf(num, shelf);
        if(inflag == -1){ //不在架上
            shelf = (shelf << 8) + num;
        }else{ //在架上把inflag移到位置0
            tmpshelf = 0;
            for(int i = 7; i >= 0; i--){
                if(i != inflag){ //不是要的，一樣放
                    tmpshelf <<= 8;
                    tmpshelf += (shelf>>(i*8))%(1<<8); //push book
                }
            }
            shelf = (tmpshelf<<8) + num;//更新
        }
    }

    for(ulli i = ((ulli)1 << 56); i > 0; i >>= 8){
        printf("%llu ", (shelf/i)%(1<<8));
    }
    
}