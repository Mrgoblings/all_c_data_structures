#include <stdio.h>
#include "binary_tree.h"

int main() {
    int input[] = {3, 10, 15, 20, 25};

    Doubly_linked_list* list = NULL;
 
    for(int i = 0; i < 5; i ++)
    	doubly_linked_list_push(&list, input + i);
   
    printf("Size is %d\n", doubly_linked_list_size(list));
    doubly_linked_list_print(list);
    
    printf("pop = %d\n", *((int*)doubly_linked_list_pop(&list)));
    doubly_linked_list_print(list);
   
    doubly_linked_list_destroy(list);
    list = NULL;
 
    return 0;
}