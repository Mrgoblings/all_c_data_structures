#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"


Doubly_linked_list* doubly_linked_list_init() {
    Doubly_linked_list* node = (Doubly_linked_list*) malloc(sizeof(Doubly_linked_list));

    node->next = NULL;
    node->data = 0;

    return node;
};


unsigned int doubly_linked_list_size(Doubly_linked_list* node) {
    unsigned int size = 0;

    for (; node != NULL; node = node->next, size++);

    return size;
};


void doubly_linked_list_push(Doubly_linked_list** head, void* value) {
    //* is_empty
    if ((*head) == NULL) {

        (*head) = doubly_linked_list_init();
        (*head)->data = value;
        (*head)->next = (*head)->prev = NULL;

        return;
    }

    Doubly_linked_list* tail = (*head);
    for (;tail->next != NULL; tail = tail->next);

    tail->next = doubly_linked_list_init();
    // tail->next->data = value;

    tail->next->prev = tail;
    tail = tail->next;

    tail->data = value;
    tail->next = NULL;
};


void* doubly_linked_list_pop(Doubly_linked_list** head) {
    if (head == NULL) {
        printf("ERROR! List is empty!\n");
        return NULL;
    }

    Doubly_linked_list* removed_node = (*head);
    void* removed_value = (*head)->data;

    (*head) = (*head)->next;
    (*head)->prev = NULL;

    return removed_value;
};


int doubly_linked_list_contains(Doubly_linked_list* node, void* value) {

    for (; node != NULL; node = node->next) {
        if (node->data == value)  return 1;
    };
    
    return 0;
};


void* doubly_linked_list_at(Doubly_linked_list* node, unsigned int index) {
    for (unsigned int i = 0; node != NULL && i <= index; node = node->next, i++) {
        if(i == index) return node->data;
    }

    printf("ERROR! Index out of list!\n");
    return NULL;
};


void doubly_linked_list_clear(Doubly_linked_list* node) {
    for (Doubly_linked_list* node_next; node != NULL; node = node_next) {
        node_next = node->next;
        free(node);
    }
};


void doubly_linked_list_destroy(Doubly_linked_list* node) {
    for (Doubly_linked_list* node_next; node != NULL; node = node_next) {
        node_next = node->next;
        free(node);
    }
};


void doubly_linked_list_print(Doubly_linked_list* head) {
    for(int i = 0; i < doubly_linked_list_size(head); i++)
    	printf("doubly_list[%d] = %d\n", i, *((int*)doubly_linked_list_at(head, i)));
            //! SET UP YOUR DATA TYPE HERE ^^^
                                    //!    ||
};
