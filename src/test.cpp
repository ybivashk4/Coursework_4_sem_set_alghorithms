#include <iostream>
#include <string>
#include "set.h"
#include "test.h"

static void init_set(Univercity_set<int> * int_set, Univercity_set<double> * double_set, 
                     Univercity_set<std::string> * string_set, Univercity_set<Coordinates> * coordinates_set);
static void out_set(Univercity_set<int> * int_set, Univercity_set<double> * double_set, 
                     Univercity_set<std::string> * string_set, Univercity_set<Coordinates> * coordinates_set);
static void del_one_elem_set(Univercity_set<int> * int_set, Univercity_set<double> * double_set, 
                     Univercity_set<std::string> * string_set, Univercity_set<Coordinates> * coordinates_set);
int main() {
    Univercity_set<int> int_set;
    Univercity_set<double> double_set;
    Univercity_set<std::string> string_set;
    Univercity_set<Coordinates> coordinates_set;
    out_set(&int_set, &double_set, &string_set, &coordinates_set);

    init_set(&int_set, &double_set, &string_set, &coordinates_set);
    std::cout << "\n\nbefore delete" << std::endl;
    out_set(&int_set, &double_set, &string_set, &coordinates_set);

    std::cout << "\n\nafter delete" << std::endl;
    del_one_elem_set(&int_set, &double_set, &string_set, &coordinates_set);
    out_set(&int_set, &double_set, &string_set, &coordinates_set);

    return 0;
}

static void init_set(Univercity_set<int> * int_set, Univercity_set<double> * double_set, 
                     Univercity_set<std::string> * string_set, Univercity_set<Coordinates> * coordinates_set) {
    int_set->add(1);
    int_set->add(2);
    int_set->add(3);

    double_set->add(1.1);
    double_set->add(2.1);
    double_set->add(3.1);
    
    string_set->add("asd");
    string_set->add("dsa");
    string_set->add("zxc");

    coordinates_set->add(Coordinates(1, 2, 3));
    coordinates_set->add(Coordinates(9, 7, 5));
    coordinates_set->add(Coordinates(2, 3, 4));
    coordinates_set->add(Coordinates(2000000000, 3456464, 475));
}

static void out_set(Univercity_set<int> * int_set, Univercity_set<double> * double_set, 
                     Univercity_set<std::string> * string_set, Univercity_set<Coordinates> * coordinates_set) {
    int_set->out();
    double_set->out();
    string_set->out();
    coordinates_set->out();
}

static void del_one_elem_set(Univercity_set<int> * int_set, Univercity_set<double> * double_set, 
                     Univercity_set<std::string> * string_set, Univercity_set<Coordinates> * coordinates_set) {
    coordinates_set->del(Coordinates(2000000000, 3456464, 475));
    double_set->del(2.1);
    string_set->del("asd");
    int_set->del(1);
}