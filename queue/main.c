#include <stdio.h>
#include "queue.h"

int main() {
    int input[] = {3, 10, 15, 20, 25};

    Queue* q = queue_init();
 
    for(int i = 0; i < 5; i ++)
        queue_push(q, input + i);
   
    printf("Size is %d\n", queue_size(q));
    queue_print(q);
    
    printf("pop = %d\n", *((int*)queue_pop(q)));
    queue_print(q);
    
    queue_destroy(q);
    q = NULL;
 
    return 0;
}