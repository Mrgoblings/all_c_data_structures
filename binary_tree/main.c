#include <stdio.h>
#include "binary_tree.h"

int main() {
    // Initialize a binary tree
    Binary_tree* root = binary_tree_init("Value 7", 7);


    // Push values with priorities
    binary_tree_push(root, "Value 2", 2);
    binary_tree_push(root, "Value 5", 5);
    binary_tree_push(root, "Value 3", 3);
    binary_tree_push(root, "Value 4", 4);
    binary_tree_push(root, "Value 1", 1);

    // Print the binary tree
    binary_tree_print(root);

    // Check if a value is present in the binary tree
    printf("Contains 'Value 3': %d\n", binary_tree_contains(root, "Value 3"));
    printf("Contains 'Value 6': %d\n", binary_tree_contains(root, "Value 6"));

    // Get the size of the binary tree
    printf("Binary tree size: %u\n", binary_tree_size(root));

    // Clear and destroy the binary tree
    binary_tree_clear(root);
    binary_tree_destroy(root);

    return 0;
}