#include <stdio.h>
#include <stdlib.h>
#include "vector_int.h"


//* private functions --------------------
void resize_int(Vector_int* vec, unsigned int new_capacity) {
    vec->capacity = new_capacity;
    vec->data = (int*) realloc(vec->data, new_capacity * sizeof(int));
}
//* --------------------------------------

Vector_int* vector_int_init() {
    Vector_int* vec = (Vector_int*) malloc(sizeof(Vector_int));

    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;

    return vec;
};


unsigned int vector_int_size(Vector_int* vec) {
    return vec->size;
};


void vector_int_push(Vector_int* vec, int value) {
    if(vec->size >= vec->capacity) {
        if(vec->capacity == 0) resize_int(vec, 2);
        else resize_int(vec, vec->capacity * 2);
    }
    
    vec->data[vec->size++] = value;
};


int vector_int_pop(Vector_int* vec) {
    if(vec->size == 0) {
        printf("ERROR! No elements to pop!");
        return -1;
    }

    int returned_value = vec->data[0];

    for(int i = 0; i < vec->size - 1; vec->data[i] = vec->data[i + 1], i++);

    (vec->size)--;

    return returned_value;
};


int vector_int_contains(Vector_int* vec, int value) {
    for(int i = 0; i < vec->size; i++) {
        if(vec->data[i] == value) return 1;
    }

    return 0;
};


int vector_int_at(Vector_int* vec, unsigned int index) {
    if(index > vec->size) {
        printf("ERROR! Index out of reach!");
        return -1;
    }

    return vec->data[index];
};


void vector_int_clear(Vector_int* vec) {
    free(vec->data);
    vec->size = 0;
    vec->capacity = 0;
};


void vector_int_destroy(Vector_int* vec) {
    free(vec->data);
    vec->size = 0;
    vec->capacity = 0;

    free(vec);
};


void vector_int_print(Vector_int* vec) {
    for(int i = 0; i < vec->size; i++)
    	printf("Vector_int[%d] = %d\n", i, vector_int_at(vec, i));
};