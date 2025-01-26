#include "libstring.h"
#include <stdlib.h>

#define MAX_SIZE 1000

struct _String {
    char *str;
    size_t len;
};


size_t array_length(char *arr) {
    size_t size = 0;
    for (;arr[size]!='\0';){
        size++;
        if (size == MAX_SIZE){
            return MAX_SIZE + 1;
        }
    }
    return size;
}

String new_string(char *str) {
    String s = (String)malloc(sizeof(struct _String));
    if (s == NULL){
        return NULL;
    }
    size_t size = array_length(str);
    if (size == MAX_SIZE + 1){
        return NULL;
    }
    s->len = size;
    s->str = (char*)malloc(sizeof(char)*(size+1));
    size_t i = 0;
    for (;i < s->len;i++){
        s->str[i] = str[i];
    }
    s->str[i] = '\0';
    return s;
} 

void str_delete(String s) {
    free(s->str);
    free(s);
}

int str_length(String s) {
    return s->len;
}

char* str_get(String s) {
    return s->str;
}

void str_cat(String s,char *str){
    size_t size = array_length(str);
    char* aux = (char*)malloc(sizeof(char)*(s->len+size+1));
    for (size_t i = 0;i < s->len;i++){
        aux[i] = s->str[i];
    }  
    for (size_t i = 0;i < size;i++){
        aux[i+s->len] = str[i];
    }
    s->len += size;
    aux[s->len+1] = '\0';
    
    s->str = aux;
}

int str_contains(String s,char *str){
    size_t size = s->len;
    size_t size2 = array_length(str);
    size_t i = 0;
    size_t j = 0;
    for (;i < size;i++){
        if (s->str[i] == str[j]){
            j++;
            if (j == size2){
                return 1;
            }
        } else {
            j = 0;
        }
    }
    return 0;
}

/**************************************************************
 * @brief Pop n characters from the nth index of the string (if 0 pop last)
 * @param s String
 * @param n Index of character to pop
 * @return 0 if success, -1 if n > s->len
 *************************************************************/
int str_pop(String s, int n){
    char* aux = (char*)malloc(sizeof(char)*(s->len));
    if ((size_t)n > s->len) {
        return -1;
    }

    if (n < 0){
        for (size_t i = 0; i < s->len-1; i++)
        {
            aux[i] = s->str[i];
        }
        aux[s->len-1] = '\0'; 
    }else{
        size_t i = 0, j = 0;
        for (;i < s->len;){
            if(i == (size_t)n){
                i++;
            }else{
                aux[j] = s->str[i];
                i++;
                j++;
            }       
        }
        aux[j] = '\0';    
    }
    free(s->str);
    s->str = aux;
    s->len--;
    return 0;
}

void str_to_upper(String s){
    size_t size = s->len;
    size_t i = 0;
    for (;i < size;i++){
        if (s->str[i] >= 'a' && s->str[i] <= 'z'){
            s->str[i] -= 32;
        }
    }
}

void str_to_lower(String s){
    size_t size = s->len;
    size_t i = 0;
    for (;i < size;i++){
        if (s->str[i] >= 'A' && s->str[i] <= 'Z'){
            s->str[i] += 32;
        }
    }
}

int str_compare(String s,void *str,int type){
    size_t size = s->len;
    size_t dif = 0;
    // type = 0, compare with string, type = 1, compare with struct String
    if (type == 0) {
        char *str2 = (char*)str;
        size_t size2 = array_length(str2);
        
        size_t i = 0;
        for (;i < size && i < size2;i++){
            dif += s->str[i] - str2[i];
        }
        if (i < size){
            for (;i < size;){
                dif += s->str[i];
            }
        }else if (i < size2){
            for (;i < size2;){
                dif += str2[i];
            }
        }
    } else{
        String str2 = (String)str;
        size_t size2 = str2->len;
        size_t i = 0;
        for (;i < size && i < size2;i++){
            dif += s->str[i] - str2->str[i];
        }
        if (i < size){
            for (;i < size;){
                dif += s->str[i];
            }
        }else if (i < size2){
            for (;i < size2;){
                dif += str2->str[i];
            }
        }
    }
    return dif;
}

