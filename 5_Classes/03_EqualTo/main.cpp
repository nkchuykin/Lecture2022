#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool IsTwo(int x){
    return x == 2;
}

class EqualTo{
    int x;
public:
    // явно
    explicit EqualTo(int val){
        x = val;
    }

    bool operator()(int other){
        return other == x;
    }
};

int main() {
    vector v {1,2,2,3,4,5,4,3,2,2};
    EqualTo eq(2);
    std::cout << count_if(v.begin(),v.end(), [](int x){return x == 2;}) << std::endl;
    std::cout << count_if(v.begin(),v.end(), IsTwo) << std::endl;
    std::cout << count_if(v.begin(),v.end(), eq) << std::endl;
    return 0;
}
