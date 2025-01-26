#include "libiterator.h"
#include <stdlib.h>

struct _iterator {
    void ** vector;
    size_t size;
    size_t index;
};

iterator new_iterator(void ** vector, size_t size){
    iterator it = (iterator)malloc(sizeof(struct _iterator));
    if (it == NULL){
        return NULL;
    }
    it->vector = vector;
    it->size = size;
    it->index = 0;
    return it;
}
int iterator_hasnext(iterator it){
    return it->index < it->size;
}
void iterator_delete(iterator it){
    free(it->vector);
    free(it);
}
void * iterator_next(iterator it){
    if (it->index == it->size){
        return NULL;
    }
    return it->vector[it->index++];
}
void * iterator_prev(iterator it){
    if (it->index == 0){
        return NULL;
    }
    return it->vector[it->index--];
}
