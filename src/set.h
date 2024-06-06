#ifndef UNIVERCITY_SET_H
#define UNIVERCITY_SET_H
#define MAX_HASH 1000
#define HASH_MASK_FOR_INT 1023
template <typename T> class Univercity_set;
template <typename T> class Node;


template <typename T> class Node {
    private:
        Univercity_set<T> *owner;
    public:
        T value;
        Node<T> * next;
        Node(T value, Univercity_set<T> * owner) {this->value = value;next=NULL; this->owner=owner;};
        ~Node();
};

template <typename T> class Univercity_set {
    private:
        Node<T> hash_table [MAX_HASH];
        int len;
        static std::size_t hash(T value);
        Node<T> *find_first_hash(std::size_t hash);
    public:
        void add (T value);
        void del(T value);
        bool empty() {return len == 0;};
        Univercity_set();
        Univercity_set(T * values);
        ~Univercity_set();
};

#endif