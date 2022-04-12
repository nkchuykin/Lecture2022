#include <iostream>

using namespace std;

int main() {
    int64_t x6;
    uint16_t x2;
    char x;
    unsigned short a1 = 2;
    int y = 3;
    long y2 = 4l;
    long long y3;
    cout << sizeof(x)  << "\n"
        << sizeof(a1) << "\n"
        << sizeof(y) << "\n"
        << sizeof(y2) << "\n"
        << sizeof(y3) << "\n";


    int num = 3.5;

    cout << num;

    return 0;
}
