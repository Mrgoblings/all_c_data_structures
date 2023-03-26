#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


Linked_list* linked_list_init() {
    Linked_list* node = (Linked_list*) malloc(sizeof(Linked_list));

    node->next = NULL;
    node->data = 0;

    return node;
};


unsigned int linked_list_size(Linked_list* node) {
    unsigned int size = 0;

    for (; node != NULL; node = node->next, size++);

    return size;
};


void linked_list_push(Linked_list** head, void* value) {
    //* is_empty
    if (head == NULL) {
        printf("Error! No list defined.\n");
        return;
    }

    Linked_list* tail = (*head);
    for (;tail->next != NULL; tail = tail->next);

    tail->next = linked_list_init();
    tail->next->data = value;
};


void* linked_list_pop(Linked_list** head) {
    if (head == NULL) {
        printf("ERROR! List is empty!\n");
        return NULL;
    }

    Linked_list* removed_node = (*head);
    void* removed_value = (*head)->data;

    (*head) = (*head)->next;

    return removed_value;
};


int linked_list_contains(Linked_list* node, void* value) {

    for (; node != NULL; node = node->next) {
        if (node->data == value)  return 1;
    };
    
    return 0;
};


void* linked_list_at(Linked_list* node, unsigned int index) {
    for (unsigned int i = 0; node != NULL && i <= index; node = node->next, i++) {
        if(i == index) return node->data;
    }

    printf("ERROR! Index out of list!\n");
    return NULL;
};


void linked_list_clear(Linked_list* node) {
    for (Linked_list* node_next; node != NULL; node = node_next) {
        node_next = node->next;
        free(node);
    }
};


void linked_list_destroy(Linked_list* node) {
    for (Linked_list* node_next; node != NULL; node = node_next) {
        node_next = node->next;
        free(node);
    }
};


void linked_list_print(Linked_list* head) {
    for(int i = 0; i < linked_list_size(head); i++)
    	printf("list[%d] = %d\n", i, *((int*)linked_list_at(head, i)));
         //! SET UP YOUR DATA TYPE HERE ^^^
                                 //!    ||
};
