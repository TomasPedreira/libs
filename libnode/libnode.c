#include "libnode.h"
#include <stdlib.h>

struct _node {
    void * elem;
    node next;
};


/***********************************
 * @brief Creates a new node
 * @param elem The element to be stored in the node
 * @param next The next node
 * @return A new node
 */
node new_node(void * elem, node next){
    node n = (node)malloc(sizeof(struct _node));
    if (n == NULL){
        return NULL;
    }
    n->elem = elem;
    n->next = next;
    return n;
}

/***********************************
 * @brief Deletes a node
 * @param n The node to be deleted
 */
void node_delete(node n){
    free(n);
}

/***********************************
 * @brief Deletes the element of a node and the node
 * @param n The node to be deleted
 * @param elem_delete The function to delete the element
 */
void node_elem_delete(node n, void (*elem_delete)(void *)){
    elem_delete(n->elem);
    free(n);
}

/***********************************
 * @brief Gets the next node
 * @param n The node
 * @return The next node
 */
node node_next(node n){
    return n->next;
}

/***********************************
 * @brief Gets the element of a node
 * @param n The node
 * @return The element of the node
 */
void * node_get(node n){
    return n->elem;
}

/***********************************
 * @brief Sets the element of a node
 * @param n The node
 * @param elem The element
 */
void node_set(node n, void * elem){
    n->elem = elem;
}

/***********************************
 * @brief Sets the next node
 * @param n The node
 * @param next The next node
 */
void node_set_next(node n, node next){
    n->next = next;
}