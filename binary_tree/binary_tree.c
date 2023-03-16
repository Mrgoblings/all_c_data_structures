#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "queue.h"


Binary_tree* binary_tree_init() {
    Binary_tree* node = (Binary_tree*) malloc(sizeof(Binary_tree));

    node->left = NULL;
    node->right = NULL;
    node->data = NULL;

    node->priority = 0;

    return node;
};


unsigned int binary_tree_size(Binary_tree* node) {
    unsigned int size = 0;
    Queue* q = queue_init();

    queue_push(q, node);

    while(queue_size(q) > 0) {
        Binary_tree* current_node = queue_pop(q);

        if(current_node->left != NULL)
            queue_push(q, current_node->left);

        if(current_node->right != NULL)
            queue_push(q, current_node->right);
        
        size++;
    }

    return size;
};


void binary_tree_push(Binary_tree* node, void* value, int priority) {
    if(node == NULL) return;

    if(node->priority > priority) {
        if(node->left != NULL) binary_tree_push(node->left, value, priority);
        else {
            node->left = binary_tree_init();
            node->left->priority = priority;
            node->left->data = value;
        }
    } else {
        if(node->right != NULL) binary_tree_push(node->right, value, priority);
        else {
            node->left = binary_tree_init();
            node->left->priority = priority;
            node->left->data = value;
        }
    }
};


int binary_tree_contains(Binary_tree* node, void* value) {
    Queue* q = queue_init();

    queue_push(q, node);

    while(queue_size(q) > 0) {
        Binary_tree* current_node = queue_pop(q);

        if(current_node->data == value) return 1;

        if(current_node->left != NULL)
            queue_push(q, current_node->left);

        if(current_node->right != NULL)
            queue_push(q, current_node->right);
    }

    return 0;
};


void binary_tree_clear(Binary_tree* node) {
    if(node == NULL) return;

    binary_tree_clear(node->left);
    binary_tree_clear(node->right);

    free(node);

    return;
};


void binary_tree_destroy(Binary_tree* node) {
    if(node == NULL) return;

    binary_tree_destroy(node->left);
    binary_tree_destroy(node->right);

    free(node);
    return;
};


//* dfs
void binary_tree_print(Binary_tree* node) {
    if(node == NULL) return;

    printf("n->%d", node->data);


    printf("L\n");
    binary_tree_print(node->left);

    printf("R\n");
    binary_tree_print(node->right);
};
