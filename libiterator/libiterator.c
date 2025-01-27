#include "libiterator.h"
#include <stdlib.h>

struct _iterator {
    void ** vector;
    size_t size;
    size_t index;
};


/*******************************
 * @brief Creates a new iterator
 * @param vector The vector
 * @param size The size of the vector
 * @return An iterator
 */
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

/*******************************
 * @brief Checks if the iterator has more elements
 * @param it The iterator
 * @return 1 if there are more elements, 0 otherwise
 */
int iterator_hasnext(iterator it){
    return it->index < it->size;
}

/*******************************
 * @brief Deletes the iterator
 * @param it The iterator
 */
void iterator_delete(iterator it){
    free(it->vector);
    free(it);
}

/*******************************
 * @brief Gets the next element of the iterator
 * @param it The iterator
 * @return The next element
 */
void * iterator_next(iterator it){
    if (it->index == it->size){
        return NULL;
    }
    return it->vector[it->index++];
}

/*******************************
 * @brief Gets the previous element of the iterator
 * @param it The iterator
 * @return The previous element
 */
void * iterator_prev(iterator it){
    if (it->index == 0){
        return NULL;
    }
    return it->vector[it->index--];
}
