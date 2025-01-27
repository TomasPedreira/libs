#include <libiterator.h>
#include <libstring.h>
#include <libtuple.h>
#include <libnode.h>
#include <liblist.h>
#include <stdio.h>

int main() {
    list l = new_list();
    for (int i = 0; i < 20; i++){
        // printf("%d\n", i);
        list_push(l, (void*)i);
    }
    list_insert(l, (void*)100, 14);
    for (int i = 0; i < 20; i++){
        node n = list_get_pos(l, i);
        printf("%d\n", (int)node_get(n));
    }
    iterator it = list_iter(l);
    while (iterator_hasnext(it)){
        printf("%d\n", (int)iterator_next(it));
    }
    iterator_delete(it);
    list_delete(l);
    return 0;
}