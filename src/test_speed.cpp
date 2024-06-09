#include "set.h"
#include "gen.h"
#include <unordered_set>
#define ARRAY_SIZE 1e7
int main(int argc, char *argv[]) {
    Univercity_set<double> double_set;
    double_array test_double(ARRAY_SIZE);
    test_double.gen_up(1, 1e10, 0.93);
    double * arr = test_double.get_arr();
    clock_t start_time = clock();
    for (int i=0; i<ARRAY_SIZE;i++) {
        double_set.add(arr[i]);
    }
    std::cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << std::endl;
    unordered_set<double> double_stl_set;
    start_time = clock();
    for (int i=0; i<ARRAY_SIZE;i++) {
        double_stl_set.insert(arr[i]);
    }
    std::cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << std::endl;

    return 0;
}