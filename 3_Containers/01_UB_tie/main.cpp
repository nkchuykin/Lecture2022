#include <iostream>
#include <utility>
#include <tuple>
#include <vector>

using namespace std;

tuple<int,int> func(){
    int a = 3;
    int b = 4;
    //return tie(a,b);
    return make_tuple(a,b);
}


int main() {
    // 3;
    auto var = func();
    cout << get<0>(var) << " " << get<1>(var) << "\n";

    int x = 3;
    int y = 5;
    int k = 2;
    //lvalue rvalue
    (k < 2 ? x : y) = 7;

    vector<int> v1 {1,2,3};
    v1[2] = 2;

    return 0;
}
