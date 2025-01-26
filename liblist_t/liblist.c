#include <stdio.h>
#include "liblist.h"
#include <libnode.h>
#include <libiterator.h>

struct _list{
    node head;
    node tail;
    size_t len;
};

/******************************************
 * @brief Creates a new list
 * @return A new list
 * @return NULL if the list could not be created
 */
list new_list(){
    list l = (list)malloc(sizeof(struct _list));
    if (l == NULL){
        return NULL;
    }
    l->head = NULL;
    l->tail = NULL;
    l->len = 0;
    return l;
}

/******************************************
 * @brief Deletes a list
 * @param l The list to be deleted
 */
void list_delete(list l){
    free(l);
}

/******************************************
 * @brief Deletes the elements of a list
 * @param l The list
 */
void list_elem_delete(list l, void (*elem_delete)(void *)){
    node n = l->head;
    while (n != NULL){
        node next = node_next(n);
        node_elem_delete(n, elem_delete);
        n = next;
    }
    l->head = NULL;
    l->tail = NULL;
    l->len = 0;
    free(l);
}

/******************************************
 * @brief Inserts a node in the head of the list
 * @param l The list
 * @param elem The element to be inserted
 */
void list_insert_head (list l, void * elem){
    node n = new_node(elem, l->head);
    if (n == NULL){
        return;
    }
    if (l->len == 0){
        l->tail = n;
    }
    l->len++;
}

/******************************************
 * @brief Inserts a node in the tail of the list
 * @param l The list
 * @param elem The element to be inserted
 */
void list_insert_tail (list l, void * elem){
    node n = new_node(elem, NULL);
    if (n == NULL){
        return;
    }
    if (l->tail != NULL){
        node_set_next(l->tail, n);
    }
    l->tail = n;
    l->len++;
}

/******************************************
 * @brief Inserts a node in the posth position of the list
 * @param l The list
 * @param elem The element to be inserted
 * @param pos The position
 */
void list_insert_pos (list l, void * elem, size_t pos){
    node n = l->head;
    for (size_t i = 1; i < pos-1; i++){
        n = node_next(n);
    }
    node new_n = new_node(elem, node_next(n));
    if (new_node == NULL){
        return;
    }
    node_set_next(n, new_n);
    l->len++;
}



/******************************************
 * @brief Inserts a node in the list
 * @param l The list
 * @param elem The element to be inserted
 */
void list_insert (list l, void * elem, size_t pos){
    if (pos == 0){
        list_insert_head(l, elem);
    } else if (pos == -1){
        list_insert_tail(l, elem);
    } else {
        list_insert_midle(l,elem,pos);
    }
}


/******************************************
 * @brief Creates an iterator for the list
 * @param l The list
 * @return An iterator
 */
iterator list_iter(list l){
    size_t len = l->len;
    void ** vector;
    vector = (void**)malloc(sizeof(void*) * l->len);
    if (vector == NULL)
        return NULL;
    node aux = l->head;
    for(size_t i=0; i < len; i++){
        vector[i] = node_get(aux);
        aux = node_next(aux);
    } 
    return new_iterator(vector, len);
}