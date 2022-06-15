#include <iostream>
#include "other.h"

int x = 42;

int y = 35;
int f(){
    static int z=0;
    return ++z;
}



int main() {
    const int y =0;
    //int x2 = 3 / y;
    std::cout << f() << std::endl;
    std::cout << f() << std::endl;
    std::cout << f() << std::endl;
    std::cout << f() << std::endl;
    std::cout << f() << std::endl;
    return 0;
}
