//
// Created by nkchuykin on 25.04.2022.
//

#include "output.h"

using namespace std;
std::istream& operator>> (std::istream& in,  std::vector<int>& v){
    v.clear();
    int n;
    in >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        in >> v[i];
    }
    return in;
}

