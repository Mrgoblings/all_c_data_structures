typedef struct queue_node_t{
    void* data;
    struct queue_node_t* next;
    struct queue_node_t* prev;
} Queue_node;

typedef struct queue_t{
    Queue_node* head;
    Queue_node* tail;
} Queue;


Queue* queue_init();
unsigned int queue_size(Queue* q);
void queue_push(Queue* q, void* value);
void* queue_pop(Queue* q);
int queue_contains(Queue* q, void* value);
void* queue_at(Queue* q, unsigned int index);
void queue_clear(Queue* q);
void queue_destroy(Queue* q);
void queue_print(Queue* q);

//* correct names
void enqueue(Queue* q, void* value);
void* dequeue(Queue* q);