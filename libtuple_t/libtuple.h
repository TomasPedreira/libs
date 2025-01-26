#ifndef LIBTUPLE_H
#define LIBTUPLE_H



typedef struct _tuple * tuple;


tuple new_tuple(void * a, void * b);
void tuple_delete(tuple t);
void tuple_elem_delete(tuple t);
void * tuple_get_a(tuple t);
void * tuple_get_b(tuple t);
void tuple_set_a(tuple t, void * a);
void tuple_set_b(tuple t, void * b);


#endif // LIBTUPLE_H