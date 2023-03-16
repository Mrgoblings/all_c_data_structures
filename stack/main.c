#include <stdio.h>
#include "stack.h"

int main() {
    int input[] = {3, 10, 15, 20, 25};

    Stack* s = stack_init();
 
    for(int i = 0; i < 5; i ++)
        stack_push(s, input + i);
   
    printf("Size is %d\n", stack_size(s));
    stack_print(s);
    
    printf("pop = %d\n", *((int*)stack_pop(s)));
    stack_print(s);
    
    stack_destroy(s);
    s = NULL;
 
    return 0;
}