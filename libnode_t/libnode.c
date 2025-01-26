#include "libnode.h"
#include <stdlib.h>

struct _node {
    void * elem;
    node next;
};

node new_node(void * elem, node next){
    node n = (node)malloc(sizeof(struct _node));
    if (n == NULL){
        return NULL;
    }
    n->elem = elem;
    n->next = next;
    return n;
}

void node_delete(node n){
    free(n);
}

void node_elem_delete(node n){
    free(n->elem);
    free(n);
}

void * node_next(node n){
    return n->next;
}

void * node_get(node n){
    return n->elem;
}

void node_set(node n, void * elem){
    n->elem = elem;
}

void node_set_next(node n, node next){
    n->next = next;
}