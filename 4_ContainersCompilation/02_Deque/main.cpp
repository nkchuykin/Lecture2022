#include <iostream>
#include <deque>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

template <typename InputIt, typename OutputIt>
InputIt CopyPart(InputIt begin, InputIt end, OutputIt out)
{
    for (auto it = begin; it != end; it++) {
        *out = *it;
    }
    return end;
}

int main() {
    deque<int> d;
    d.push_front(3);
    d.push_front(4);
    d.push_back(5);
    d.push_front(1);
    d.push_front(3);

    d.insert(d.begin()+2,6);

    for (auto num : d)
    {
        cout << num <<  " ";
    }
    cout << "\n";

    list<int> l {-2,-3,-4};
    vector<int> v;

    CopyPart(d.begin(),d.end(),
             inserter(v,v.begin()));
    CopyPart(d.begin(),d.end(),
             inserter(l,next(l.begin())));

    for (auto num : l)
    {
        cout << num <<  " ";
    }
    cout << "\n";
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
