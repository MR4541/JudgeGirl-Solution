#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define MY_CC 1 
#define AVERAGE_CC 5

struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *mid;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;
 
bool isIsomorphic(TreeNode* root1, TreeNode* root2){
    if(root1 == NULL || root2 == NULL)
        return (root1 == NULL && root2 == NULL); //兩個都null為真、只有一個null為假
    TreeNode *a1 = root1->left, *b1 = root1->mid, *c1 = root1->right;
    TreeNode *a2 = root2->left, *b2 = root2->mid, *c2 = root2->right;
    return ((isIsomorphic(a1, a2)&&isIsomorphic(b1, b2)&&isIsomorphic(c1, c2)) ||
            (isIsomorphic(a1, a2)&&isIsomorphic(b1, c2)&&isIsomorphic(c1, b2)) ||
            (isIsomorphic(a1, b2)&&isIsomorphic(b1, a2)&&isIsomorphic(c1, c2)) ||
            (isIsomorphic(a1, b2)&&isIsomorphic(b1, c2)&&isIsomorphic(c1, a2)) ||
            (isIsomorphic(a1, c2)&&isIsomorphic(b1, a2)&&isIsomorphic(c1, b2)) ||
            (isIsomorphic(a1, c2)&&isIsomorphic(b1, b2)&&isIsomorphic(c1, a2)));
}

// ///////////////////////////////////////////////////////////////
// TreeNode *buildTree(TreeNode **roots) {
//     int val;
//     scanf("%d", &val);
//     if(val == 0) return NULL;
 
//     TreeNode *now = *roots;
 
//     (*roots)++;
 
//     now->left = buildTree(roots);
//     now->mid = buildTree(roots);
//     now->right = buildTree(roots);
 
//     return now;
// }
 
 
// int main() {
//     int T, size;
//     scanf("%d", &T);
//     while (T--) {
//         scanf("%d", &size);
//         TreeNode* root1 = (TreeNode*)calloc(size, sizeof(TreeNode));
//         TreeNode* root2 = (TreeNode*)calloc(size, sizeof(TreeNode));
 
//         TreeNode *nptr1 = root1, *nptr2 = root2;
 
//         root1 = buildTree(&nptr1);
//         root2 = buildTree(&nptr2);
 
//         isIsomorphic(root1, root2) == true ? printf("True\n") : printf("False\n");
 
//         free(root1);
//         free(root2);
//     }
//     return 0;
// }