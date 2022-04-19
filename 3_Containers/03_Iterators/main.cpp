#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,6};
    v.reserve(7);
    auto b = v.begin();
    // RandomAccessIterator
    vector<int>::iterator e = v.end();
    std::cout << *b << std::endl;
    auto i1 = next(b,5);
    //advance(b,4);
    b += 4;
    std::cout << *b << std::endl;
    std::cout << *i1 << std::endl;

    *b = 123;

    //auto end = ;
    v.push_back(3);
    auto x = v.begin()+1;
    v.erase(x);
    cout << *x << "\n";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;



    return 0;
}
