#include <iostream>
#include <utility>
#include <tuple>

using namespace std;




int main() {
    pair<int,int> p{3,4};
    pair<int,int> p2 = p;
    p2.second = 2;
    cout << p.first << " " << p.second << "\n";
    cout << p2.first << " " << p2.second << "\n";

    tuple<int,int,int> t1{2021, 4, 7};
    cout<< get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << "\n";
    tuple<int,int,int> t2{2021, 4, 5};
    cout << (t1 < t2) << "\n";

    cout << "------" << "\n";


    int a = 1, b = 2, c = 3;
    auto t3 = tie(a,b,c);
    get<0>(t3) = 4;
    b = 4;
    cout << a << " " << get<1>(t3) << "\n";

    return 0;
}
