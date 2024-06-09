#ifndef SET_HASH
#define SET_HASH
#include "set_definitions.h"
template <typename T>
std::size_t Univercity_set<T>::hash(T value) {
    return value.hash() % (MAX_HASH);
}

template <>
std::size_t Univercity_set<int>::hash(int value) {
    return (std::size_t)(value ^ HASH_MASK_FOR_INT) % (MAX_HASH);
}

template <>
std::size_t Univercity_set<double>::hash(double value) {
    return ((unsigned int)value ^ HASH_MASK_FOR_INT) % (MAX_HASH);
}

template <>
std::size_t Univercity_set<std::string>::hash(std::string value) {
    return ((sizeof(value) + (value[0] + value[value.length() - 1]) / 2) % (MAX_HASH));
}
template <typename T>
Node<T>* Univercity_set<T>::find_first_hash(std::size_t hash) {
    return hash_table[hash];
}
#endif