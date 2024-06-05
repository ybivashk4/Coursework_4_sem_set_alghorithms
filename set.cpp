#include <iostream>
#include "set.h"

template <>
std::size_t Univercity_set<int>::hash(int value) {
    return (value ^ HASH_MASK_FOR_INT)  % (MAX_HASH+1);
}

template <>
std::size_t Univercity_set<double>::hash(double value) {
    return ((unsigned int)value ^ HASH_MASK_FOR_INT)  % (MAX_HASH+1);
}

template <>
std::size_t Univercity_set<std::string>::hash(std::string value) {
    return (sizeof(value) + (value[0] + value[value.length() - 1]) / 2  % (MAX_HASH+1));
}

template <typename T>
std::size_t Univercity_set<T>::hash(T value) {
    return value.hash() % (MAX_HASH+1);
}

template <typename T>
Univercity_set<T>::Univercity_set() {
    hash_table = 0;
    len = 0;
}

template <typename T>
Univercity_set<T>::Univercity_set(T * values){
    for (auto &a : values) 
        add(a);
}

template <typename T>
Univercity_set<T>::~Univercity_set() {
    for (int i=0;i<1000;i++)
        delete[] hash_table[i];
}

template <typename T>
void Univercity_set<T>::add(T value) {
    int index = Univercity_set<T>::hash(value);
    if (!hash_table[index])
        hash_table[index] = new Node(value);
    else {
        Node * tmp = hash_table[index];
        while (tmp) {
            tmp = tmp->next;
        }
        tmp = new Node(value);
    }
}

template <typename T>
void Univercity_set<T>::del(T value) {
    int index = Univercity_set<T>::hash(value);
    if (!hash_table[index])
        hash_table[index] = new Node(value);
    else {
        Node * tmp = hash_table[index];
        while (tmp) {
            tmp = tmp->next;
        }
        tmp = new Node(value);
    }
}
