#include <iostream>
#include "vec.h"

using namespace std;

int main() {
    Vec2D v {3,4};
    Vec2D v2 {1, 5};
    auto s1 = v.Sum(v2);
    auto s2 = Sum(v,v2);
    auto s3 = v + v2;
    auto s4 = v.operator+(v2);

    std::cout << v << "\n" << s1 << std::endl;
    cout << "\n------------\n";
    cout << v++ << "\n";
    cout << v;
    return 0;
}
