#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "queue.h"


Binary_tree* binary_tree_init() {
    Binary_tree* node = (Binary_tree*) malloc(sizeof(Binary_tree));

    node->left = NULL;
    node->right = NULL;
    node->data = NULL;

    return node;
};


unsigned int binary_tree_size(Binary_tree* node) {
    unsigned int size = 0;
    Queue* q = queue_init();

    queue_push(q, node);

    while(queue_size(q) > 0) {
        Binary_tree* current_node = queue_pop(q);

        queue_push(q, current_node->left);
        queue_push(q, current_node->right);
        
        size++;
    }

    return size;
};


void binary_tree_push(Binary_tree* q, void* value);


int binary_tree_contains(Binary_tree* q, void* value);


void* binary_tree_at(Binary_tree* q, unsigned int index);


void binary_tree_clear(Binary_tree* q);


void binary_tree_destroy(Binary_tree* q);


//* dfs
void binary_tree_print(Binary_tree* node) {
    if(node == NULL) return;

    printf("n->%d", node->data);


    printf("L\n");
    binary_tree_print(node->left);

    printf("R\n");
    binary_tree_print(node->right);
};
