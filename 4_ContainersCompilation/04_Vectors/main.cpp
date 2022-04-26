#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> v {1,-2,3,-4,5,-6,7,-8,9,10};

    auto new_end = remove_if(v.begin(),v.end(),[](int x){
        return x % 2 == 0;
    });

    //sort(v.begin(),new_end);
    cout << v.capacity() <<"\n";
    v.erase(new_end,v.end());
    cout << v.capacity() <<"\n";
    for (auto num : v)
    {
        cout << num << " ";
    }
    cout << "\n------\n";

    vector<int> v2 {1,2,3,3,3,3,3,5,6,7};

    auto x1 = binary_search(v2.begin(),v2.end(),3);
    auto x2 = lower_bound(v2.begin(),v2.end(),3);
    auto x3 = upper_bound(v2.begin(),v2.end(),3);
    cout << x2 - v2.begin() << "\n";
    cout << x3 - v2.begin() << "\n";
    //Unsafety x2 & x3 may be v2.end()
    cout << *x2 << "\n";
    cout << *x3 << "\n";
    return 0;
}
