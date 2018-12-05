#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(int argc, char const *argv[])
{
    printf("Hello\n");
    int element;
    TREE_PTR root;

    TREE_init(&root);
    printf("initialized.\n");

    TREE_insert_root(&root, 10);
    printf("What the fuck is happening???\n");
        
    TREE_insert_left(root, 6);
    printf("What the fuck is happening 2nd time???\n");
    TREE_insert_right(root, 14);    
    printf("What the fuck is happening 3nd time???\n");

    TREE_insert_left(root->left, 5);
    printf("What the fuck is happening 4nd time???\n");
    TREE_insert_right(root->left, 7);
    printf("What the fuck is happening 5nd time???\n");       
    TREE_insert_right(root->right, 19);
    printf("What the fuck is happening 6nd time???\n");        
    TREE_insert_left(root->left->left, 2);
    printf("What the fuck is happening 7nd time???\n");
    TREE_insert_right(root->left->right, 8);
    printf("What the fuck is happening 8nd time???\n");
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
