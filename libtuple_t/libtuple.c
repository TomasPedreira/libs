#include "libtuple.h"
#include <stdlib.h>


struct _tuple {
    void * a;
    void * b;
};


tuple new_tuple(void * a, void * b){
    tuple t = (tuple)malloc(sizeof(struct _tuple));
    if (t == NULL){
        return NULL;
    }
    t->a = a;
    t->b = b;
    return t;
}

void tuple_delete(tuple t){
    free(t);
}

void tuple_elem_delete(tuple t){
    free(t->a);
    free(t->b);
    free(t);
}

void * tuple_get_a(tuple t){
    return t->a;
}

void * tuple_get_b(tuple t){
    return t->b;
}

void tuple_set_a(tuple t, void * a){
    t->a = a;
}

void tuple_set_b(tuple t, void * b){
    t->b = b;
}