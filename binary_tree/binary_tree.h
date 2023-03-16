typedef struct binary_tree_t {
    void* data;
    int priority;

    struct binary_tree_t* left;
    struct binary_tree_t* right;
} Binary_tree;



Binary_tree* binary_tree_init();
unsigned int binary_tree_size(Binary_tree* q);
void binary_tree_push(Binary_tree* q, void* value, int priority);
void* binary_tree_pop(Binary_tree* q);
int binary_tree_contains(Binary_tree* q, void* value);
void binary_tree_clear(Binary_tree* q);
void binary_tree_destroy(Binary_tree* q);
void binary_tree_print(Binary_tree* q);