#ifndef LIBITERATOR_H
#define LIBITERATOR_H
#include <stdlib.h>


typedef struct _iterator * iterator;

iterator new_iterator(void ** vector, size_t size);
void iterator_delete(iterator it);
void * iterator_next(iterator it);
void * iterator_prev(iterator it);
int iterator_hasnext(iterator it);

#endif // LIBITERATOR_H