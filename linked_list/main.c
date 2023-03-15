#include <stdio.h>
#include "linked_list.h"

int main() {
    int input[] = {3, 10, 15, 20, 25};

    Linked_list* list = NULL;
 
    for(int i = 0; i < 5; i ++)
    	linked_list_push(&list, input + i);
   
    printf("Size is %d\n", linked_list_size(list));
    linked_list_print(list);
    
    printf("pop = %d\n", *((int*)linked_list_pop(&list)));
    linked_list_print(list);
   
    linked_list_destroy(list);
    list = NULL;
 
    return 0;
}