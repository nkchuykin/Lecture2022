#include <iostream>
#include <vector>

using namespace std;

class A{
    vector<int> v{1,2,3};
    inline static int x = 6;

    const int& f() const {
        return v[0];
    }
};


//int A::x = 6;


inline int sqr(int x){
    return x*x;
}

int main() {
    std::cout << sqr(3) << std::endl;

    for(int i = 1; i <= 4; i++){
        std::cout << i;
    }

    std::cout << 1;
    std::cout << 2;
    std::cout << 3;
    std::cout << 4;

   // std::cout << 3*3 << std::endl;
    return 0;
}
