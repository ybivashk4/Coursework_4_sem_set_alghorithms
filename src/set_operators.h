#ifndef SET_OPERATORS
#define SET_OPERATORS
#include "set_definitions.h"

template <typename T> 
bool Univercity_set<T>::operator==(Univercity_set<T> &value) {
    if (len != value.len) return false;
    for (int i = 0; i < MAX_HASH; i++) {
        Node<T> * tmp = hash_table[i];
        while (tmp) {
            if (!value.in(tmp->value)) return false;
            tmp = tmp->next;
        }
        
    }
    return true;
}

#endif