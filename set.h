#ifndef UNIVERCITY_SET_H
#define UNIVERCITY_SET_H
#define MAX_HASH 1000
#define HASH_MASK_FOR_INT 1023


template <typename T> class Univercity_set{
    private:
        template <typename T> class Node {
            public:
                T value;
                Node<T> * next;
                Node(T value) {this->value = value;next=NULL;};
                ~Node(){this->value = 0;next=NULL;};
        }
        Node [MAX_HASH] hash_table;
        int len;
        static std::size_t hash(double value);
        static std::size_t hash(int value);
        static std::size_t hash(std::string value);
        static std::size_t hash(T value);
    public:
        void add (T value);
        void del(T value);
        bool empty() return len == 0;
        Univercity_set();
        Univercity_set(T * values);
        ~Univercity_set();
        
        // add hashtable
};
#endif