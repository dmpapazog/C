#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void TREE_init(TREE_PTR *root) {
    *root = NULL;
}

int TREE_empty(TREE_PTR node) {
    return node == NULL;
}

element TREE_data(TREE_PTR node) {
    return node->data;
}

int TREE_insert_root(TREE_PTR *root, element x) {
    if (!TREE_empty(*root))
        return FALSE;
    
    TREE_PTR newNode;
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
    if (!TREE_empty(node->left))
        return FALSE;
    
    TREE_PTR newNode;
    newNode = (TREE_PTR)malloc(sizeof(TREE_NODE));
    if (!newNode) {
        printf("Adunemia deumeshs mnhmhs");
        return FALSE;
    }

    newNode->data  = x;
    newNode->left  = NULL;
    newNode->right = NULL;

    node->left = newNode;
    return TRUE;
}

int TREE_insert_right(TREE_PTR node, element x) {
    if (!TREE_empty(node->right))
        return FALSE;
    
    TREE_PTR newNode;
    newNode = (TREE_PTR)malloc(sizeof(TREE_NODE));
    if (!newNode) {
        printf("Adunemia deumeshs mnhmhs");
        return FALSE;
    }

    newNode->data  = x;
    newNode->left  = NULL;
    newNode->right = NULL;

    node->right = newNode;
    return TRUE;
}

int TREE_delete_root(TREE_PTR *root, element *x) {
    if (!TREE_empty((*root)->left) || !TREE_empty((*root)->right))
        return FALSE;

    *x = (*root)->data;
    free(*root);
    *root = NULL;

    return TRUE;
}

int TREE_delete_left(TREE_PTR parent, element *x) {
    if (TREE_empty(parent->left))
        return FALSE;
    
    TREE_PTR current = NULL;
    current = parent->left;
    if (!TREE_empty(current->left) || !TREE_empty(current->right))
        return FALSE;
    
    *x = current->data;
    free(current);
    parent->left = NULL;
    return TRUE;
}

int TREE_delete_right(TREE_PTR parent, element *x) {
    if (TREE_empty(parent->right))
        return FALSE;
    
    TREE_PTR current = NULL;
    current = parent->right;
    if (!TREE_empty(current->left) || !TREE_empty(current->right))
        return FALSE;
    
    *x = current->data;
    free(current);
    parent->right = NULL;
    return TRUE;
}

void TREE_preorder(TREE_PTR node) {
    if (!TREE_empty(node)) {
        TREE_print_node(node);
        TREE_preorder(node->left);
        TREE_preorder(node->right);
    }
}

void TREE_inorder(TREE_PTR node) {
    if (!TREE_empty(node)) {
        TREE_inorder(node->left);
        TREE_print_node(node);
        TREE_inorder(node->right);
    }
}

void TREE_postorder(TREE_PTR node) {
    if (!TREE_empty(node)) {
        TREE_postorder(node->left);
        TREE_postorder(node->right);
        TREE_print_node(node);
    }
}

void TREE_print_node(TREE_PTR node) {
    printf("%2d ", node->data);
}

void TREE_delete_tree(TREE_PTR *node) {
    if (TREE_empty((*node)->left) && TREE_empty((*node)->right)) {
        free(*node);
        *node = NULL;
    }
    else {
        if (!TREE_empty((*node)->left)) 
            TREE_delete_tree(&(*node)->left);
        
        if (!TREE_empty((*node)->right))
            TREE_delete_tree(&(*node)->right);
    }
}