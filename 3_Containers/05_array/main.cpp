#include <iostream>
#include <array>
#include <list>

using namespace std;

int main() {
    const size_t size = 10;
    array<int,size> arr{};
    arr[0] = 0;
    arr[1] = 2;

    for(auto i : arr)
    {
        cout << i << " ";
    }

    cout << "list\n";
    list<int> list1 {1,2,3,4,5,6,7};
    auto l_b = list1.begin();
    advance(l_b,4);
    cout << "\n";
    cout << *l_b << "\n";
    list1.insert(l_b,7);
    list1.insert(list1.end(),127);
    for(auto num : list1)
    {
        cout << num << " ";
    }

    cout << "\n";
    cout << *next(list1.begin(),3) << "\n";


    return 0;
}
