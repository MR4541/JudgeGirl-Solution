#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
 
typedef struct element{
    char key[25];
    int value; //cnt of appear
}Element;
 
struct map{
    int end; //n
    struct element elements[8005];
};
typedef struct map Map;
 
int compare(const void* a, const void* b){
    return strcmp((char*)a, (char*)b);
}
 
void insert(Map *m, char key[]){
    Element search_key;
    search_key.value = 1; strcpy(search_key.key, key);
    Element* found = bsearch(&search_key, m->elements, m->end, sizeof(Element), compare);
    if(found == NULL){ //new
        m->elements[m->end] = search_key;
        m->end++;
        qsort(m->elements, m->end, sizeof(Element), compare);
    }else{
        m->elements[found - m->elements].value++;
    }
}
 
// int delete(Map *m, char key[]){
//     Element search_key;
//     search_key.value = -1; strcpy(search_key.key, key);
//     Element* found = bsearch(&search_key, m->elements, m->end, sizeof(Element), compare);
//     if(found == NULL){
//         return 0;
//     }else{
//         for(int i = found - m->elements; i < m->end - 1; i++)
//             m->elements[i] = m->elements[i+1];
//         m->end--;
//         return 1;
//     }
// }
 
int query(Map *m, char key[]){
    Element search_key;
    search_key.value = -1; strcpy(search_key.key, key);
    Element* found = bsearch(&search_key, m->elements, m->end, sizeof(Element), compare);
    if(found == NULL){
        return 0; //not found
    }else{
        if((--m->elements[found - m->elements].value) == 0){ //delete it 
            for(int i = found - m->elements; i < m->end - 1; i++)
                m->elements[i] = m->elements[i+1];
            m->end--;
        }
        return 1;
    }
}
 
int main(void){
    char infile[32], outfile[32];
    scanf("%s%s", infile, outfile);
    Map m;
    m.end = 0;
    FILE* fin = fopen(infile, "r");
    int n;
    fscanf(fin, "%d", &n);
 
    // int *strID = (int*)malloc(sizeof(int)*1000000); //把str編成id
    // int IDtoEleID = (int*)malloc(sizeof(int)*1000000); //把str的id對照到element[i]
 
    char key[32];
    while(fscanf(fin, "%s", key) != EOF){
        insert(&m, key);
    }
    fclose(fin);
 
    // printf("{");
    // for(int i = 0; i < m.end; i++){
    //     printf("\"%s\" : %d, ", m.elements[i].key, m.elements[i].value);
    // }
    // printf("}\n");
 
    //O(n) delete
    int offset = 0;
    for(int i = 0; i < m.end; i++){
        m.elements[i - offset] = m.elements[i];
        if((m.elements[i].value&1) == 0)
            offset++;
    }
    m.end -= offset;
 
    printf("{");
    for(int i = 0; i < m.end; i++){
        printf("\"%s\" : %d, ", m.elements[i].key, m.elements[i].value);
    }
    printf("}\n");
 
 
    fin = fopen(infile, "r"); fscanf(fin, "%d", &n); int line = 1;
    FILE* fout = fopen(outfile, "w");
    while(fscanf(fin, "%s", key) != EOF){
        if(query(&m, key) && line%7) //in the set: is odd appear
            fprintf(fout, "%s\n", key);
        line++;
    }
    fclose(fin); fclose(fout);
 
    printf("{");
    for(int i = 0; i < m.end; i++){
        printf("\"%s\" : %d, ", m.elements[i].key, m.elements[i].value);
    }
    printf("}\n");
 
 
}