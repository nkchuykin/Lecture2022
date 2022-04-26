#include <algorithm>
#include <list>
#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    list<int> lst {7,3,2,1,4,6};

    lst.sort();

    forward_list<int> lst1;//{lst.begin(),lst.end()};

    for (auto i : lst){
        lst1.push_front(i);
    }
    cout << "\n";

    for (auto i : lst1){
        cout << i << " ";
    }

    cout << "\n";

    return 0;
}
