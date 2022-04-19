#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("../input.txt");

    if (!fin.is_open())
    {
        return 1;
    }

    vector<int> vec;
    int num;
    while(fin >> num)
    {
        vec.push_back(num);
    }
    int s = 0;
    for(auto el : vec)
    {
        s += el;
    }
    ofstream fout("../output.txt");
    auto first_even = find_if(vec.begin(),vec.end(),
                              [](int x){
        return x%2 == 0;
    });
    fout << "first even is " << *first_even << "\n";

    size_t count_of_even = count_if(vec.begin(),vec.end(),
                              [](int x){
                                  return x%2 == 0;
                              });
    fout << "Count of even " << count_of_even;
    return 0;
}
