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
    // out empty set
    out_set(&int_set, &double_set, &string_set, &coordinates_set);

    // simple delete
    init_set(&int_set, &double_set, &string_set, &coordinates_set);
    std::cout << "\n\nbefore delete" << std::endl;
    out_set(&int_set, &double_set, &string_set, &coordinates_set);

    std::cout << "\n\nafter delete" << std::endl;
    del_one_elem_set(&int_set, &double_set, &string_set, &coordinates_set);
    out_set(&int_set, &double_set, &string_set, &coordinates_set);
    

    // add same elem
    
    std::cout << int_set.len << std::endl;
    ASSERT(int_set.len == 2, 1);
    int_set.add(2);
    int_set.add(2);
    int_set.add(3);
    int_set.add(2);
    ASSERT(int_set.len == 2, 1);

    // add with same hash
    int_set.add(1002);
    int_set.add(2002);
    int_set.add(3002);
    int_set.add(4002);
    int_set.add(5002);
    ASSERT(int_set.len == 7, 2);

    // del same hash
    int_set.del(3002); // middle
    int_set.del(5002); // start
    int_set.del(2002); // end
    ASSERT(int_set.len == 4, 3);

    // del unreal elements
    int_set.del(3002); // middle
    int_set.del(5002); // start
    int_set.del(2002); // end
    ASSERT(int_set.len == 4, 4);

    // del all elements
    int_set.del(3);
    int_set.del(2);
    int_set.del(1002);
    int_set.del(4002);
    ASSERT(int_set.empty(), 5);

    int_set.add(3);
    int_set.add(2);
    int_set.add(1002);
    int_set.add(4002);
    int_set.clear();
    ASSERT(int_set.len == 0, 6);

    // copy test
    Univercity_set<int> test_int_set = int_set;
    ASSERT(test_int_set.len == 0, 7);
    int_set.add(3);
    int_set.add(2);
    int_set.add(1002);
    int_set.add(4002);
    test_int_set = int_set;
    ASSERT(test_int_set.len == 4, 8);

    
    ASSERT(int_set.in(1002) && int_set.in(4002) && int_set.in(2) && int_set.in(3), 9);
    ASSERT(int_set == test_int_set, 10);
    int_set.add(1);
    int_set.add(1001);
    int_set.add(9);
    test_int_set.add(666);
    int arr_int[4] = {3, 2, 1002, 4002};
    Univercity_set<int> assert_int;
    for (auto &  a: arr_int) assert_int.add(a);
    ASSERT(int_set.intersection_set(test_int_set) == assert_int, 11);

    assert_int.clear();
    int arr_int_1[3] = {9, 1, 1001};
    for (auto &  a: arr_int_1) assert_int.add(a);
    ASSERT(int_set.difference_set(test_int_set) == assert_int, 12);

    int arr_int_2[8] = {9, 3, 2, 1002, 1, 1001, 4002, 666};
    assert_int.clear();
    for (auto &  a: arr_int_2) assert_int.add(a);

    ASSERT(int_set.union_set(test_int_set) == assert_int, 13);

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

