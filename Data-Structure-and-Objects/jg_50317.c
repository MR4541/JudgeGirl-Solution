#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
 
typedef struct element{
  char key[25];
  int value;
}Element;
 
struct map{
    int end; //n
    struct element elements[8005];
};
typedef struct map Map;
 
 
int compare(const void* a, const void* b){
    return strcmp((char*)a, (char*)b);
}
 
void insert(Map *m, char key[], int value){
    Element search_key;
    search_key.value = value; strcpy(search_key.key, key);
    Element* found = bsearch(&search_key, m->elements, m->end, sizeof(Element), compare);
    if(found == NULL){ //new
        m->elements[m->end] = search_key;
        m->end++;
        qsort(m->elements, m->end, sizeof(Element), compare); //只有新的時候會用到sort
    }else{
        m->elements[found - m->elements].value = value;
    }
}
 
int delete(Map *m, char key[]){
    Element search_key;
    search_key.value = -1; strcpy(search_key.key, key);
    Element* found = bsearch(&search_key, m->elements, m->end, sizeof(Element), compare);
    if(found == NULL){
        return 0;
    }else{
        for(int i = found - m->elements; i < m->end - 1; i++)
            m->elements[i] = m->elements[i+1];
        m->end--;
        return 1;
    }
}
 
int query(Map *m, char key[]){
    Element search_key;
    search_key.value = -1; strcpy(search_key.key, key);
    Element* found = bsearch(&search_key, m->elements, m->end, sizeof(Element), compare);
    if(found == NULL){
        return -1;
    }else{
        return m->elements[found - m->elements].value;
    }
}
 
 
///////////////////////////////////////////////////////////////////////
// int main(){
//     Map m;
//     m.end = 0;
//     int i,n,op,value;
//     char key[25];
 
//     scanf("%d", &n);
//     for(i=0; i<n; i++){
//         scanf("%d", &op);
//         if(op == 1){
//             scanf("%s %d", key, &value);
//             insert(&m, key, value);
//         }
//         else if(op == 2){
//             scanf("%s", key);
//             printf("%d\n",delete(&m, key));
//         }
//         // else{
//         //     scanf("%s", key);
//         //     printf("%d\n",query(&m, key));
//         // }
 
//         printf("{");
//         for(int i = 0; i < m.end; i++){
//             printf("\"%s\" : %d, ", m.elements[i].key, m.elements[i].value);
//         }
//         printf("}\n");
//     }
 
//     return 0;
// }