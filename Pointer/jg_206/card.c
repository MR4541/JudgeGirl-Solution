#include<stdio.h>

void shuffle(int *deck[]){
    int cnt = 0;
    for(cnt; deck[cnt] != NULL; cnt++);
    int half = cnt/2+cnt%2;
    //printf("%d %d\n", cnt, half);
    int *deck1[10000];
    for(int i = 0; i < cnt; i++){
        if(i < half)
            deck1[2*i] = deck[i];
        else
            deck1[2*(i-half)+1] = deck[i];
    }
    for(int i = 0; i < cnt; i++) deck[i] = deck1[i];
}

void print(int *deck[]){
    for(int i = 0; deck[i] != NULL; i++)
        printf("%d ", *deck[i]);
}

///////////////////////////
// int main()
// {
//   int card[10000];
//   int *deck[10000];
//   int index = 0;
 
//   while (scanf("%d", &(card[index])) != EOF) {
//     deck[index] = &(card[index]);
//     index++;
//   }
//   deck[index] = NULL;
//   shuffle(deck);
//   print(deck); 
//   return 0;
// }