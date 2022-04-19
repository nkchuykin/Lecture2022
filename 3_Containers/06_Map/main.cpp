#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;


int main() {
    map<string,int> m;
    m["hello"] = 1;
    m["bye"] = 2;

    for(auto [key, value] : m)
    {
        cout << key << " " << value << "\n";
    }
    cout << " ";
    //m["bye"] = 2;
    if (m.find("world") != m.end())
    {
        cout << "+" << "\n";
    }
    else {
        cout << "-" << "\n";
    }

    for(auto [key, value] : m)
    {
        cout << key << " " << value << "\n";
    }
    cout << " ";

    vector<int> vector1{1,2,123,3,4,5,4,3,2,5};

    map<int,int> res;
    for(int num : vector1){
        res[num] += 1;
    }
    for(auto [key, value] : res)
    {
        cout << key << " " << value << "\n";
    }



    return 0;
}
