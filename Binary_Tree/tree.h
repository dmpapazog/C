#ifndef TREE_H
#define TREE_H

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int element;    // typos dedomenwn apo8hkeushs

struct node {
    element data;       // timh toy kombou
    struct node *left;  // deikths sto aristero 8ygatriko komvo
    struct node *right; // deikths sto de3i 8ygatriko komvo
};

typedef struct node TREE_NODE;  // Sinwnumo tou kombou dentrou
typedef struct node *TREE_PTR;  // Sinwnumo deikth se kombo tou dentrou

void TREE_init(TREE_PTR *root);
int TREE_empty(TREE_PTR root);
element TREE_data(TREE_PTR node);
int TREE_insert_root(TREE_PTR *root, element x);
int TREE_insert_left(TREE_PTR node, element x);
int TREE_insert_right(TREE_PTR node, element x);
int TREE_delete_root(TREE_PTR *root, element *x);
int TREE_delete_left(TREE_PTR parent, element *x);
int TREE_delete_right(TREE_PTR parent, element *x);
void TREE_delete_tree(TREE_PTR *node);

void TREE_preorder(TREE_PTR node);
void TREE_inorder(TREE_PTR node);
void TREE_postorder(TREE_PTR node);
void TREE_print_node(TREE_PTR node);



#endif