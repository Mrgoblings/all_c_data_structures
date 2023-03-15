typedef struct doubly_linked_list_t{
    void* data;
    struct doubly_linked_list_t* next;
    struct doubly_linked_list_t* prev;
} Doubly_linked_list;


Doubly_linked_list* doubly_linked_list_init();
unsigned int doubly_linked_list_size(Doubly_linked_list* node);
void doubly_linked_list_push(Doubly_linked_list** head, void* value);
void* doubly_linked_list_pop(Doubly_linked_list** head);
int doubly_linked_list_contains(Doubly_linked_list* node, void* value);
void* doubly_linked_list_at(Doubly_linked_list* node, unsigned int index);
void doubly_linked_list_clear(Doubly_linked_list* node);
void doubly_linked_list_destroy(Doubly_linked_list* node);
void doubly_linked_list_print(Doubly_linked_list* head);
