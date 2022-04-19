#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> vec;

    vec.push_back(string(100,'a'));
    vec.emplace_back(100,'a');

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
