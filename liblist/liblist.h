#ifndef LIBLIST_H
#define LIBLIST_H
#include <libnode.h>
#include <libiterator.h>


typedef struct _list * list;


list new_list();
void list_delete(list l);
void list_elem_delete(list l, void (*elem_delete)(void *));
void list_remove_head (list l, void (*elem_delete)(void *));
void list_remove_tail (list l, void (*elem_delete)(void *));
void list_remove_midle (list l, size_t pos, void (*elem_delete)(void *));
void list_remove_pos (list l, size_t pos, void (*elem_delete)(void *));
void list_push(list l, void * elem);
node list_get_pos(list t, size_t pos);



void list_insert (list l, void * elem, int pos);
iterator list_iter(list l);





#endif // LIBLIST_H