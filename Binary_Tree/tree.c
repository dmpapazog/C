#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void TREE_init(TREE_PTR *root) {
    *root = NULL;
}

int TREE_empty(TREE_PTR root) {
    return root == NULL;
}

element TREE_data(TREE_PTR node) {
    return node->data;
}

int TREE_insert_root(TREE_PTR *root, element x) {
    TREE_PTR newNode;
    if (*root != NULL)
        return FALSE;
    
    newNode = (TREE_PTR)malloc(sizeof(TREE_NODE));
    if (!newNode) {
        printf("Adunemia deumeshs mnhmhs");
        return FALSE;
    }

    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    *root = newNode;
    return TRUE;
}

int TREE_insert_left(TREE_PTR node, element x) {
    TREE_PTR newNode;
    if (node->left != NULL)
        return FALSE;
    
    newNode = (TREE_PTR)malloc(sizeof(TREE_NODE));
    if (!newNode) {
        printf("Adunemia deumeshs mnhmhs");
        return FALSE;
    }

    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;

    node->left = newNode;
    return TRUE;
}

int TREE_insert_right(TREE_PTR node, element x) {
    TREE_PTR newNode;
    if (node->right != NULL)
        return FALSE;
    
    newNode = (TREE_PTR)malloc(sizeof(TREE_NODE));
    if (!newNode) {
        printf("Adunemia deumeshs mnhmhs");
        return FALSE;
    }

    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;

    node->right = newNode;
    return TRUE;
}

int TREE_delete_root(TREE_PTR *root, element *x) {
    if ((*root)->left != NULL || (*root)->right != NULL)
        return FALSE;

    *x = (*root)->data;
    free(*root);
    *root = NULL;

    return TRUE;
}

int TREE_delete_left(TREE_PTR parent, element *x) {
    TREE_PTR current = NULL;
    if (parent->left == NULL)
        return FALSE;
    
    current = parent->left;
    if (current->left != NULL || current->right != NULL)
        return FALSE;
    
    *x = current->data;
    free(current);
    parent->left = NULL;
    return TRUE;
}

int TREE_delete_right(TREE_PTR parent, element *x) {
    TREE_PTR current = NULL;
    if (parent->right == NULL)
        return FALSE;
    
    current = parent->right;
    if (current->left != NULL || current->right != NULL)
        return FALSE;
    
    *x = current->data;
    free(current);
    parent->right = NULL;
    return TRUE;
}

void TREE_preorder(TREE_PTR node) {
    if (node != NULL) {
        TREE_print_node(node);
        TREE_preorder(node->left);
        TREE_preorder(node->right);
    }
}

void TREE_inorder(TREE_PTR node) {
    if (node != NULL) {
        TREE_inorder(node->left);
        TREE_print_node(node);
        TREE_inorder(node->right);
    }
}

void TREE_postorder(TREE_PTR node) {
    if (node != NULL) {
        TREE_postorder(node->left);
        TREE_postorder(node->right);
        TREE_print_node(node);
    }
}

void TREE_print_node(TREE_PTR node) {
    printf("%2d ", node->data);
}

void TREE_delete_tree(TREE_PTR *node) {
    if ((*node)->left == NULL && (*node)->right == NULL) {
        free(*node);
        *node = NULL;
    }
    else {
        TREE_delete_tree(&(*node)->left);
        TREE_delete_tree(&(*node)->right);
    }
}