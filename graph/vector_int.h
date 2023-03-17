typedef struct vector_int_t{
    int* data;

    unsigned int size;
    unsigned int capacity;
} Vector_int;


Vector_int* vector_int_init();
unsigned int vector_int_size(Vector_int* vec);
void vector_int_push(Vector_int* vec, int value);
int vector_int_pop(Vector_int* vec);
int vector_int_contains(Vector_int* vec, int value);
int vector_int_at(Vector_int* vec, unsigned int index);
void vector_int_clear(Vector_int* vec);
void vector_int_destroy(Vector_int* vec);
void vector_int_print(Vector_int* vec);
