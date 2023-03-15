#include <stdio.h>
#include "vector.h"


int main() {
    int input[] = {3, 10, 15, 20, 25};

    Vector* vec = vector_init();
 
    for(int i = 0; i < 5; i ++)
    	vector_push(vec, input + i);
   
    printf("Size is %d\n", vector_size(vec));

    vector_print(vec);
    
    printf("pop = %d\n", *((int*)vector_pop(vec)));

    vector_print(vec);

    vector_destroy(vec);
    vec = NULL;
 
    return 0;
}