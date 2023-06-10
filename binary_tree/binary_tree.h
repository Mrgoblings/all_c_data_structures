typedef struct binary_tree_t {
    void* data;
    int priority;

    struct binary_tree_t* left;
    struct binary_tree_t* right;
} Binary_tree;


Binary_tree* binary_tree_init(void* value, int priority);
unsigned int binary_tree_size(Binary_tree* node);
void binary_tree_push(Binary_tree* node, void* value, int priority);
int binary_tree_contains(Binary_tree* node, void* value);
void binary_tree_clear(Binary_tree* node);
void binary_tree_destroy(Binary_tree* node);
void binary_tree_print(Binary_tree* node);