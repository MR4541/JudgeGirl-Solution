# include<stdio.h>
# include<stdlib.h>
# include<assert.h>

# define MY_CC 5
# define AVERAGE_CC 4.5

struct treenode {
    int value;
    struct treenode *left; //used as next
    struct treenode *right;
};
 
struct list {
    struct treenode *head;
    struct treenode *tail;
};
 
typedef struct treenode TreeNode;
typedef struct list List;
 
List treeToListFunc(TreeNode * root){
    if(root == NULL){
        List list = {NULL, NULL};
        return list;
    }
    List rightSubList = treeToListFunc(root->right);
    List leftSubList = treeToListFunc(root->left);
    List list; //for return
    list.head = root;
    root->right = NULL;
    if(rightSubList.head == NULL && leftSubList.head == NULL){
        list.head->left = NULL;
        list.tail = list.head;
    }else if(rightSubList.head == NULL){
        list.head->left = leftSubList.head;
        list.tail = leftSubList.tail;
        list.tail->left = NULL;
    }else if(leftSubList.head == NULL){
        list.head->left = rightSubList.head;
        list.tail = rightSubList.tail;
        list.tail->left = NULL;
    }else if(root->value & 1){//左右子樹都存在且root奇 root->right->left
        list.head->left = rightSubList.head;
        rightSubList.tail->left = leftSubList.head;
        list.tail = leftSubList.tail;
        list.tail->left = NULL;
    }else{ //root偶
        list.head->left = leftSubList.head;
        leftSubList.tail->left = rightSubList.head;
        list.tail = rightSubList.tail;
        list.tail->left = NULL;
    }
    return list;
}


///////////////////////////////////////////////////////////////////
// TreeNode *buildTree(int **values, TreeNode **roots) {
//     int val;
//     scanf("%d", &val);
//     if(val == 0) return NULL;
//     **values = val;
//     TreeNode *now = *roots;
//     (*values)++; (*roots)++;
//     now -> value = val;
//     now -> left  = buildTree(values, roots);
//     now -> right = buildTree(values, roots);
//     return now;
// }
 
// int main(void) {
//     int size;
//     scanf("%d\n", &size);
//     TreeNode * root = (TreeNode*)calloc(size, sizeof(TreeNode));
 
//     int valueRecord[size];
//     int *vptr = valueRecord;
//     TreeNode *nptr = root;
 
//     root = buildTree(&vptr, &nptr);
 
//     List ans = treeToListFunc(root);
 
//     TreeNode * node = ans.head;
//     TreeNode * firstAddr = &root[0];
//     TreeNode * lastAddr = &root[size];
//     for(; node != NULL; node = node -> left) {
//         if (node -> right != NULL) {
//             printf("Right node should be null\n");
//             break;
//         }
//         if (firstAddr > node || lastAddr <= node) {
//             printf("Memory address out of bound\n");
//             break;
//         }
//         int counter = node - firstAddr;
//         if (node -> value != valueRecord[counter]) {
//             printf("You can't modify the value in the given treeNode\n");
//             break;
//         }
//         printf("%d ", node -> value);
//     }
 
//      free(root);
//     return 0;
// }