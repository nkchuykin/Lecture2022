#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a {2,1,3,4,2};
    sort(a.begin(),a.end()+2);
    for (auto num : a)
        cout << num << " ";
    sort(a.rbegin(),a.rend());
    for (auto num : a)
        cout << num << " ";
    return 0;
}
