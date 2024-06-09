#ifndef TEST_STRUCT 
#define TEST_STRUCT
#include <iostream>
struct Coordinates {
    int x, y, z;
    Coordinates() : x(0), y(0), z(0){};
    Coordinates(int x_, int y_, int z_) : x(x_), y(y_), z(z_){};
    std::size_t hash() {return (x * y * z);};
    void out() {
        std::cout << x << " " << y << " " << z << std::endl;
    }
    bool operator == (const Coordinates & cmp) {
        return (x == cmp.x && y == cmp.y && z == cmp.z);
    }
};



#define ASSERT_HINT(val, hint, ntest) \
  if (val == false) std::cout << "Error in "__FILE__   << " file, "<<__LINE__ \
  << " line, " << __FUNCTION__ << " func, "<< hint; \
  else std::cout << "TEST " << ntest << " success!" << std::endl;

#define ASSERT(val, ntest) ASSERT_HINT(val, NULL, ntest)



#endif