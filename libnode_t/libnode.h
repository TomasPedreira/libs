#ifndef LIBNODE_H
#define LIBNODE_H


typedef struct _node * node;

node new_node(void * elem, node next);

void node_delete(node n);
void node_elem_delete(node n);

void * node_next(node n);

void * node_get(node n);

void node_set(node n, void * elem);
void node_set_next(node n, node next);

#endif // LIBNODE_H