#include "set.h"
#include "gen.h"
#include <unordered_set>
void test_time(int arr_size, int step);
int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    /*
    rand gen
    int arr_sizes[6] = {10000000, 30000000, 50000000, 70000000, 90000000, 100000000};
    std::cout << "my\tstl\n";
    for (auto &a : arr_sizes) {
        test_time(a, 0.93);
    }
    */
    // up_gen 
    // int arr_sizes[6] = {1000000, 3000000, 5000000, 7000000, 9000000, 10000000};
    // std::cout << "Генерация происходит с маленьким шагом\n";
    // std::cout << "my\tstl\n";
    // for (auto &a : arr_sizes) {
    //     test_time(a, 0.93);
    // }
    // std::cout << "Генерация происходит с большим шагом\n";
    // std::cout << "my\tstl\n";
    // for (auto &a : arr_sizes) {
    //     test_time(a, 10);
    // }

    // kvazi_gen 
    // int arr_sizes[6] = {1000000, 3000000, 5000000, 7000000, 9000000, 10000000};
    // std::cout << "my\tstl\n";
    // for (auto &a : arr_sizes) {
    //     test_time(a, 0.93);
    // }
    return 0;
}

void test_time(int arr_size, int step) {
    Univercity_set<double> double_set;
    double_array test_double(arr_size);
    // test_double.gen_up(1, 1e10, step);
    // test_double.kvazi_gen(1, 1e10);
    /* rand gen
        test_double.gen_rand(1, 1e10);
    */
    double * arr = test_double.get_arr();
    clock_t start_time = clock();
    for (int i=0; i<arr_size;i++) {
        double_set.add(arr[i]);
    }
    std::cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << " ";
    unordered_set<double> double_stl_set;
    start_time = clock();
    for (int i=0; i<arr_size;i++) {
        double_stl_set.insert(arr[i]);
    }
    std::cout << (double)(clock()-start_time) / CLOCKS_PER_SEC << std::endl;
}