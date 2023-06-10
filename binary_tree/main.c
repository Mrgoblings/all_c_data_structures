#include <stdio.h>
#include "binary_tree.h"

int main() {
    int input[] = {3, 10, 15, 20, 25};

    Binary_tree* tree = NULL;
 
    for(int i = 0; i < 5; i ++)
    	binary_tree_push(&tree, input + i, input[i]);
   
    printf("Size is %d\n", binary_tree_size(tree));
    binary_tree_print(tree);
    
    printf("pop = %d\n", *((int*)binary_tree_pop(&tree)));
    binary_tree_print(tree);
   
    binary_tree_destroy(tree);
    tree = NULL;
  
    return 0;
}