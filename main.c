#include "libstring_t/libstring.h"
#include <stdio.h>

int main() {
    String s = new_string("Hello");
    str_pop(s, 1);
    printf("%s\n", str_get(s));
    str_cat(s, " World!");
    printf("%s\n", str_get(s));  
    printf("%d\n", str_length(s));
    str_delete(s);
    return 0;
}