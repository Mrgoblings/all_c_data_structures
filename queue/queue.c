#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


Queue* queue_init() {
    Queue* q = (Queue*) malloc(sizeof(Queue));

    q->head = NULL;
    q->tail = NULL;

    return q;
};


unsigned int queue_size(Queue* q) {
    Queue_node* node = q->head;
    unsigned int size = 0;

    for (; node != NULL; node = node->next, size++);

    return size;
};


void queue_push(Queue* q, void* value) {
    //* is_empty
    if (head == NULL) {
        printf("Error! No list defined.\n");
        return;
    }

    q->tail->next = (Queue_node*) malloc(sizeof(Queue_node));
    
    q->tail->next->prev = q->tail;
    q->tail = q->tail->next;

    q->tail->data = value;
    q->tail->next = NULL;

};


void* queue_pop(Queue* q) {
    Queue_node* node = q->head;

    if (node == NULL) {
        printf("ERROR! List is empty!\n");
        return NULL;
    }

    Queue_node* removed_node = node;
    void* returned_value = node->data;

    q->head = node = node->next;
    node->prev = NULL;


    free(removed_node);
    return returned_value;
};


int queue_contains(Queue* q, void* value) {
    Queue_node* node = q->head;

    for (; node != NULL; node = node->next) {
        if (node->data == value)  return 1;
    };
    
    return 0;
};


void* queue_at(Queue* q, unsigned int index) {
    Queue_node* node = q->head;

    for (unsigned int i = 0; node != NULL && i <= index; node = node->next, i++) {
        if(i == index) return node->data;
    }

    printf("ERROR! Index out of list!\n");
    return NULL;
};


void queue_clear(Queue* q) {
    Queue_node* node = q->head;
    for (Queue_node* node_next; node != NULL; node = node_next) {
        node_next = node->next;
        free(node);
    }

    q->head = NULL;
};


void queue_destroy(Queue* q) {
    Queue_node* node = q->head;
    for (Queue_node* node_next; node != NULL; node = node_next) {
        node_next = node->next;
        free(node);
    }

    free(q);
};


void queue_print(Queue* q) {
    for(int i = 0; i < queue_size(q); i++)
    	printf("queue[%d] = %d\n", i, *((int*)queue_at(q, i)));
          //! SET UP YOUR DATA TYPE HERE ^^^
                                  //!    ||
};


//* correct names
void enqueue(Queue* q, void* value){
    queue_push(q, value);
}

void* dequeue(Queue* q) {
    return queue_pop(q);
}
