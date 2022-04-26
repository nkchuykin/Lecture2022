#include <iostream>
#include <vector>
#include "output.h"

using namespace std;

int main() {
    vector<int> v {3,4,5,6};
    std::cin >> v;
    std::cerr << v << std::endl;
    return 0;
}
