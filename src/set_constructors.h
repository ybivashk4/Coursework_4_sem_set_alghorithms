#ifndef SET_CONSTRUCTORS
#define SET_CONSTRUCTORS

#include "set_definitions.h"
template <typename T>
Univercity_set<T>::Univercity_set() {
    for (int i = 0; i < MAX_HASH; i++) {
        hash_table[i] = nullptr;
    }
    len = 0;
}

template <typename T>
Univercity_set<T>::Univercity_set(Univercity_set & cpy) {
    len = 0;
    for (int i=0;i<MAX_HASH;i++) hash_table[i] = nullptr;
    for (int i = 0; i < MAX_HASH; i++) {
        Node<T> * tmp = cpy.hash_table[i];
        
        while (tmp) {
            add(tmp->value);
            tmp = tmp->next;
        }
    }
}

#endif