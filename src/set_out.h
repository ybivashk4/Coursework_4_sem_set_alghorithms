#ifndef SET_OUT
#define SET_OUT
#include "set_definitions.h"
#include <iostream>

template <typename T>
void Univercity_set<T>::out_value(T value) {
    Node<T> * tmp = hash_table[Univercity_set<T>::hash(value)];
    while (tmp == nullptr && !(tmp->value == value)) 
        tmp=tmp->next;
    if (tmp)
        tmp->value.out();
    else 
        std::cout << "(null)";
}
template <>
void Univercity_set<int>::out_value(int value) {
    std::cout << value;
}

template <>
void Univercity_set<double>::out_value(double value) {
    std::cout << value;
}

template <>
void Univercity_set<std::string>::out_value(std::string value) {
    std::cout << value;
}

template <typename T>
void Univercity_set<T>::out() {
    for (int i = 0; i < MAX_HASH; i++) {
        if (hash_table[i]) {
            Node<T> * tmp = hash_table[i];
            while (tmp) {
                out_value(tmp->value);
                std::cout << " ";
                tmp = tmp->next;
            }
        }
    }
}

template <>
void Univercity_set<int>::out() {
    for (int i = 0; i < MAX_HASH; i++) {
        Node<int> * tmp = hash_table[i];
        while (tmp) {
            out_value(tmp->value);
            std::cout << " ";
            tmp = tmp->next;
        }
    }
    std::cout << std::endl;
}

template <>
void Univercity_set<double>::out() {
    for (int i = 0; i < MAX_HASH; i++) {
        if (hash_table[i]) {
            Node<double> * tmp = hash_table[i];
            while (tmp) {
                out_value(tmp->value);
                std::cout << " ";
                tmp = tmp->next;
            }
        }
    }
    std::cout << std::endl;
}

template <>
void Univercity_set<std::string>::out() {
    for (int i = 0; i < MAX_HASH; i++) {
        if (hash_table[i]) {
            Node<std::string> * tmp = hash_table[i];
            while (tmp) {
                out_value(tmp->value);
                std::cout << " ";
                tmp = tmp->next;
            }
        }
    }
    std::cout << std::endl;
}


#endif