
// * THIS FILE DOES NOT COMPILE/RUN

#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "priority_queue.h"
#include "queue.h"

typedef struct node_t {
    void* data;

    Vector* edges;
    Vector_int* weights;

    int best_weight;
    int is_visited; //* flag
} Node;


Vector* dijkstra(Node* start, Node* end) {
    Priority_queue* q = queue_init();
    Vector* path = vector_init();

    priority_queue_push(q, start, start->best_weight);

    while(priority_queue_size(q) > 0) {
        Node* current_node = (Node*)priority_queue_pop(q);
        if(current_node->is_visited == 1) continue;
        current_node->is_visited = 1;

        if(current_node == end) break;

        for(int i = 0; i < current_node->edges->size; i++) {
            if(((Node*)current_node->edges->data[i])->best_weight == 0 ||
            ((Node*)current_node->edges->data[i])->best_weight < current_node->best_weight + current_node->weights->data[i]) 
                ((Node*)current_node->edges->data[i])->best_weight = current_node->best_weight + current_node->weights->data[i];

            priority_queue_push(q, current_node->edges->data[i], ((Node*)current_node->edges->data[i])->best_weight);
        }
    }
}

void bfs(Node* node) {
    Queue* q = queue_init();

    queue_push(q, node);

    while(queue_size(q) > 0) {
        Node* current_node = queue_pop(q);
        if(current_node->is_visited == 1) continue;
        current_node->is_visited = 1;

        for(int i = 0; i < node->edges->size; i++) {
            queue_push(q, current_node->edges->data[i]);
        }
    }
}

void dfs(Node* node) {
    if(node == NULL || node->is_visited == 1) return;

    node->is_visited = 1;

    for(int i = 0; i < node->edges->size; i++) {
        dfs(node->edges->data[i]);
    }

    node->is_visited = 0;
}

Node* init_graph(void* value) {
  Node* new_node = (Node* *)malloc(sizeof(Node*));

  new_node->data = value;
  
  new_node->edges = init_vector();
  new_node->weights = init_vector_int();

  new_node->best_weight = 0;
  new_node->is_visited = 0;

  return new_node;
}

void connect(Node* first, Node* second, int weight) {
  vector_push(first->edges, second);
  vector_push(second->edges, first);

  int *dynamic_weight = (int *)malloc(sizeof(int));
  (*dynamic_weight) = weight;

  vector_push(first->weights, dynamic_weight);
  vector_push(second->weights, dynamic_weight);
}



int main(void) {
  int matrix[7][7] = {
    {0, 2, 0, 0, 0, 7, 0},
    {2, 0, 5, 0, 0, 3, 4},
    {0, 5, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 8, 6, 1},
    {0, 0, 1, 8, 0, 2, 5},
    {7, 3, 0, 6, 2, 0, 0},
    {0, 4, 1, 1, 5, 0, 0}
  };

  Vector* graph_array = init_vector();

  for (int i = 0; i < 7; i++) {
    Node** new_node = init_graph(i);

    vector_push(graph_array, new_node);
  }

  for (int y = 0; y < 7; y++) {
    for (int x = y + 1; x < 7; x++) {
      if (matrix[x][y] != 0) {
        connect(graph_array->data[y], graph_array->data[x], matrix[x][y]);
      }
    }
  }

  find_path_dijkstra(graph_array->data[0], graph_array->data[6]);

  return 0;
}

