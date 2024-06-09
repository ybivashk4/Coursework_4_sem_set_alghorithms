#ifndef SET_DESTRUCTORS
#define SET_DESTRUCTORS
#include "set_definitions.h"
template <typename T>
Node<T>::~Node() {
    if (next) {
        Node<T>* tmp = owner->find_first_hash(Univercity_set<T>::hash(value));
        if (tmp == this) 
            owner->hash_table[Univercity_set<T>::hash(value)] = next;
        else {
            while (tmp && tmp->next != this)    tmp = tmp->next;
            if (tmp)    tmp->next = this->next;
        }
    }
}

template <typename T>
Univercity_set<T>::~Univercity_set() {
    // clear();
}

#endif