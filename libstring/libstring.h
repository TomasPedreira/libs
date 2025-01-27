#ifndef LIBSTRING_H
#define LIBSTRING_H

#include <stdlib.h>

typedef struct _String * String;

String new_string(char *str);
void str_delete(String s);
int str_length(String s);
char* str_get(String s);
void str_cat(String s,char *str);
void str_to_upper(String s);
void str_to_lower(String s);
int str_compare(String s,void *str,int type);
int str_pop(String s, int n);






#endif // LIBSTRING_H