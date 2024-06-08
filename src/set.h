#ifndef UNIVERCITY_SET_H
#define UNIVERCITY_SET_H
#define MAX_HASH 1000
#define HASH_MASK_FOR_INT 1023
#include <string>
#include <cmath>

template <typename T> class Univercity_set;
template <typename T> class Node;

template <typename T>
class Node {
private:
    Univercity_set<T> *owner;
public:
    T value;
    Node<T> *next;
    Node(T value, Univercity_set<T> * owner) { this->value = value; next = NULL; this->owner = owner; };
    ~Node();
};

/*
if you use custom structure or class in Univercity_set must be 
1) method size_t hash();
2) operator ==
*/
template <typename T>
class Univercity_set {
    friend class Node<T>;
private:
    Node<T>* hash_table[MAX_HASH];
protected:
    static std::size_t hash(T value);
    Node<T>* find_first_hash(std::size_t hash);
public:
    int len;
    void add(T value);
    void del(T value);
    bool empty() { return len == 0; };
    void out_value(T value);
    void out();
    Univercity_set();
    Univercity_set(T* values);
    ~Univercity_set();
};


// * * * * * * * * * * * * * * * * *
// hash methods
template <typename T>
std::size_t Univercity_set<T>::hash(T value) {
    return value.hash() % (MAX_HASH);
}

template <>
std::size_t Univercity_set<int>::hash(int value) {
    return (value ^ HASH_MASK_FOR_INT) % (MAX_HASH);
}

template <>
std::size_t Univercity_set<double>::hash(double value) {
    return ((unsigned int)value ^ HASH_MASK_FOR_INT) % (MAX_HASH);
}

template <>
std::size_t Univercity_set<std::string>::hash(std::string value) {
    return (sizeof(value) + (value[0] + value[value.length() - 1]) / 2 % (MAX_HASH));
}
// * * * * * * * * * * * * * * * * *


// * * * * * * * * * * * * * * * * *

// out methods
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
    for (auto & a : hash_table) {
        if (a)  out_value(a->value);
    }
}

template <>
void Univercity_set<int>::out() {
    for (auto & a : hash_table) {
        if (a) {
            out_value(a->value);
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

template <>
void Univercity_set<double>::out() {
    for (auto & a : hash_table) {
        if (a) {
            out_value(a->value);
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

template <>
void Univercity_set<std::string>::out() {
    for (auto & a : hash_table) {
        if (a) {
            out_value(a->value);
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

// * * * * * * * * * * * * * * * * *


template <typename T>
Univercity_set<T>::Univercity_set() {
    for (int i = 0; i < MAX_HASH; ++i) {
        hash_table[i] = nullptr;
    }
    len = 0;
}

template <typename T>
Univercity_set<T>::Univercity_set(T* values) {
    for (auto& a : values)
        add(a);
}

template <typename T>
Univercity_set<T>::~Univercity_set() {
    for (int i = 0; i < MAX_HASH; ++i) {
        delete hash_table[i];
    }
}

template <typename T>
void Univercity_set<T>::add(T value) {
    int index = Univercity_set<T>::hash(value);
    if (!hash_table[index])
        hash_table[index] = new Node<T>(value, this);
    else {
        Node<T>* tmp = hash_table[index];
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
Node<T>* Univercity_set<T>::find_first_hash(std::size_t hash) {
    if (hash < 0 || hash >= MAX_HASH)
        return nullptr;
    return hash_table[hash];
}

template <typename T>
Node<T>::~Node() {
    if (next) {
        Node<T>* tmp = owner->find_first_hash(Univercity_set<T>::hash(value));
        while (tmp && tmp->next != this)
            tmp = tmp->next;
        if (tmp) {
            tmp->next = this->next;
        }
    }
}

#endif