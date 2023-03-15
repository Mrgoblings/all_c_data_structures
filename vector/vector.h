typedef struct vector_t{
    void** data;

    unsigned int size;
    unsigned int capacity;
} Vector;


Vector* vector_init();
unsigned int vector_size(Vector* vec);
void vector_push(Vector* vec, void* value);
void* vector_pop(Vector* vec);
int vector_contains(Vector* vec, void* value);
void* vector_at(Vector* vec, unsigned int index);
void vector_clear(Vector* vec);
void vector_destroy(Vector* vec);
void vector_print(Vector* vec);
