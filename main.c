#include <libiterator.h>
#include <libstring.h>
#include <libtuple.h>
#include <libnode.h>
#include <liblist.h>
#include <stdio.h>

int main() {
    list l = new_list();

    printf("size of void* %zu\n", sizeof(void*));
    printf("size of integer %zu\n", sizeof(int));
    for (int i = 0; i < 20; i++){
        list_push(l, (void*)i);
    }
    list_insert(l, (void*)100, 14);
    for (int i = 0; i < 20; i++){
        node n = list_get_pos(l, i);
        printf("%d\n", (int)node_get(n));
    }
    list_remove_pos(l, 13, NULL);
    iterator it = list_iter(l);
    while (iterator_hasnext(it)){
        printf("%d\n", (int)iterator_next(it));
    }
    iterator_delete(it);
    list_elem_delete(l, NULL);
    printf("Finished m8\n");
    return 0;
}