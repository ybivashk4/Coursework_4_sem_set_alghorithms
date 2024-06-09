#ifndef SET_OPERATION
#define SET_OPERATION
#include "set_definitions.h"
#include "set_destructors.h"

template <typename T>
void Univercity_set<T>::add(T value) {
    int index = Univercity_set<T>::hash(value);
    Node<T>* tmp = hash_table[index];
    while (tmp) {
        if (tmp->value == value) {
            return;
        }
        tmp = tmp->next;
    }
    tmp = hash_table[index];
    if (!hash_table[index])
        hash_table[index] = new Node<T>(value, this);
    else {
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = new Node<T>(value, this);
    }
    len++;
}

template <typename T>
void Univercity_set<T>::del(T value) {
    int index = Univercity_set<T>::hash(value);
    if (hash_table[index]) {
        Node<T>* tmp = hash_table[index];
        Node<T>* prev = nullptr;
        while (tmp && !(tmp->value == value)) {
            prev = tmp;
            tmp = tmp->next;
        }
        if (tmp) {
            if (prev) {
                prev->next = tmp->next;
            } else {
                hash_table[index] = tmp->next;
            }
            delete tmp;
            len--;
        }
    }
}



template <>
void Univercity_set<double>::del(double value) {
    int index = Univercity_set<double>::hash(value);
    if (hash_table[index]) {
        Node<double>* tmp = hash_table[index];
        Node<double>* prev = nullptr;
        while (tmp && fabs(tmp->value - value) >= 1e-6 ) {
            prev = tmp;
            tmp = tmp->next;
        }
        if (tmp) {
            if (prev) {
                prev->next = tmp->next;
            } else {
                hash_table[index] = tmp->next;
            }
            delete tmp;
            len--;
        }
    }
}

template <typename T>
void Univercity_set<T>::clear() {
    for (int i=0;i<MAX_HASH;i++) {
        if (hash_table[i]) {
            delete hash_table[i];
            hash_table[i] = nullptr;
        }
    }
    len = 0;
}

template <typename T>
bool Univercity_set<T>::in(T value) {
    std::size_t index = Univercity_set<T>::hash(value);
    if (!hash_table[index]) return false;
    Node<T> * tmp = hash_table[index];
    while (tmp) {
        if (tmp->value == value) return true;
        tmp = tmp->next;
    }
    return false;
}

template <typename T>
Univercity_set<T> Univercity_set<T>::union_set(Univercity_set<T> another) {
    Univercity_set<T> res = another;
    for (int i = 0; i < MAX_HASH; i++) {
        Node<T> * tmp = hash_table[i];
        while (tmp) {
            res.add(tmp->value);
            tmp = tmp->next;
        }
    }
    return res;
}

template <typename T>
Univercity_set<T> Univercity_set<T>::intersection_set(Univercity_set<T> another) {
    Univercity_set<T> res;
    
    for (int i = 0; i < MAX_HASH; i++) {
        Node<T> * tmp = hash_table[i];
        while (tmp) {
            if (another.in(tmp->value)) res.add(tmp->value);
            tmp = tmp->next;
        }
    }
    return res;
}

template <typename T>
Univercity_set<T> Univercity_set<T>::difference_set(Univercity_set<T> another) {
    Univercity_set<T> res;
    for (int i = 0; i < MAX_HASH; i++) {
        Node<T> * tmp = hash_table[i];
        while (tmp) {
            if (!another.in(tmp->value))    res.add(tmp->value);
            tmp = tmp->next;
        }
    }
    return res;
}

#endif