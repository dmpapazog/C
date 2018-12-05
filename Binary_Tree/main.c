#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(int argc, char const *argv[])
{
    printf("Hello\n");
    int element;
    TREE_PTR root;

    TREE_init(&root);

    TREE_insert_root(&root, 10);
            
    TREE_insert_left(root, 6);
    TREE_insert_right(root, 14);    

    TREE_insert_left(root->left, 5);
    TREE_insert_right(root->left, 7);

    TREE_insert_right(root->right, 19);

    TREE_insert_left(root->left->left, 2);

    TREE_insert_right(root->left->right, 8);

    TREE_insert_right(root->left->left->left, 3);
    
    printf("\nPREORDER: ");
    TREE_preorder(root);
    printf("\nINORDER: ");
    TREE_inorder(root);
    printf("\nPOSTORDER: ");
    TREE_postorder(root);

    TREE_delete_tree(&root);

    return 0;
}
