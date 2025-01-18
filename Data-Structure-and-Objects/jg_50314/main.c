#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
void print(struct node* root){
    printf("%c", root->data);
    if(root->left!=NULL){
        printf("l");
        print(root->left);
        printf("b");
    }
    if(root->right!=NULL){
        printf("r");
        print(root->right);
        printf("b");
    }
}
int main(){
    struct node *root=(struct node*)malloc(sizeof(struct node));;
    root->left=NULL;
    root->right=NULL;
    root->data='?';
    int mode;scanf("%d",&mode);
    if(mode==1){
        int n;scanf("%d",&n);
        char *code[2005],str[2005];
        for(int i=0;i<n;i++){
            code[i]=(char*)malloc(sizeof(char)*2005);
            scanf("%s %c",code[i],&str[i]);
        }
        build_tree(code,str,root,n);
        print(root);
    }
    if(mode==2){
        int n;scanf("%d",&n);
        char *code[2005],str[2005];
        for(int i=0;i<n;i++){
            code[i]=(char*)malloc(sizeof(char)*2005);
            scanf("%s %c",code[i],&str[i]);
        }
        build_tree((char**)code,str,root,n); 
        int q;scanf("%d",&q);
        for(int i=0;i<q;i++){
            char c[2005];scanf("%s",c);
            printf("%c",ask(c,root));
        }
    }
    return 0;
}
