#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


//* private functions --------------------
void resize(Vector* vec, unsigned int new_capacity) {
    vec->capacity = new_capacity;
    vec->data = (void**) realloc(vec->data, new_capacity * sizeof(void*));
}
//* --------------------------------------

Vector* vector_init() {
    Vector* vec = (Vector*) malloc(sizeof(Vector));

    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;

    return vec;
};


unsigned int vector_size(Vector* vec) {
    return vec->size;
};


void vector_push(Vector* vec, void* value) {
    if(vec->size >= vec->capacity) {
        if(vec->capacity == 0) resize(vec, 2);
        else resize(vec, vec->capacity * 2);
    }
    
    vec->data[vec->size++] = value;
};


void* vector_pop(Vector* vec) {
    if(vec->size == 0) {
        printf("ERROR! No elements to pop!");
        return NULL;
    }

    void* returned_value = vec->data[0];

    for(int i = 0; i < vec->size - 1; vec->data[i] = vec->data[i + 1], i++);

    (vec->size)--;

    return returned_value;
};


int vector_contains(Vector* vec, void* value) {
    for(int i = 0; i < vec->size; i++) {
        if(vec->data[i] == value) return 1;
    }

    return 0;
};


void* vector_at(Vector* vec, unsigned int index) {
    if(index > vec->size) {
        printf("ERROR! Index out of reach!");
        return NULL;
    }

    return vec->data[index];
};


void vector_clear(Vector* vec) {
    free(vec->data);
    vec->size = 0;
    vec->capacity = 0;
};


void vector_destroy(Vector* vec) {
    free(vec->data);
    vec->size = 0;
    vec->capacity = 0;

    free(vec);
};


void vector_print(Vector* vec) {
    for(int i = 0; i < vec->size; i++)
    	printf("vector[%d] = %d\n", i, *((int*)vector_at(vec, i)));
           //! SET UP YOUR DATA TYPE HERE ^^^
                                   //!    ||
};


