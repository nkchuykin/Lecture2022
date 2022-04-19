#include <iostream>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {

    set<int> s1 {3,1,2,34,56,7,6,3};
    //multiset<int> s2 {3,1,2,34,56,7,6,3};
    for(auto num : s1){
        cout << num << " ";
    }
    cout << "\n";
    cout << boolalpha << (s1.find(23) != s1.end()) <<"\n";
    s1.insert(23);
    s1.insert(23);
    //bad
    auto r = find(s1.begin(),s1.end(),23);
    //good
    cout << (s1.find(23) != s1.end()) <<"\n";



    for(auto num : s1){
        cout << num << " ";
    }
    cout << "\n";

    unordered_set<int> s2 {2,3,5,3,1,8};

    for(auto num : s2){
        cout << num << " ";
    }
    cout << "\n";

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
