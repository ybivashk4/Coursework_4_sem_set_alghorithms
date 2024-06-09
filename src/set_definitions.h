#ifndef SET_DEF
#define SET_DEF
#define MAX_HASH 100000
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
3) method <anything> out();
*/
template <typename T>
class Univercity_set {
    friend class Node<T>;
private:
    Node<T>* hash_table[MAX_HASH];
    void out_value(T value);
protected:
    static std::size_t hash(T value);
    Node<T>* find_first_hash(std::size_t hash);
    
public:
    int len;
    void add(T value);
    void del(T value);
    bool empty() { return len == 0; };
    void out();
    void clear();
    bool in (T value); // is element in set
    
    Univercity_set union_set(Univercity_set another);
    Univercity_set intersection_set(Univercity_set another);
    Univercity_set difference_set(Univercity_set another);
    


    bool operator==(Univercity_set &value);


    Univercity_set();
    Univercity_set(Univercity_set & cpy); // Univercity_set dest(src);
    ~Univercity_set();
};
#endif