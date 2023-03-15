typedef struct linked_list_t{
    void* data;
    struct linked_list_t* next;
} Linked_list;


Linked_list* linked_list_init();
unsigned int linked_list_size(Linked_list* node);
void linked_list_push(Linked_list** head, void* value);
void* linked_list_pop(Linked_list** head);
int linked_list_contains(Linked_list* node, void* value);
void* linked_list_at(Linked_list* node, unsigned int index);
void linked_list_clear(Linked_list* node);
void linked_list_destroy(Linked_list* node);
void linked_list_print(Linked_list* head);
