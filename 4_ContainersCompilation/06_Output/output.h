//
// Created by nkchuykin on 25.04.2022.
//

#ifndef INC_06_OUTPUT_OUTPUT_H
#define INC_06_OUTPUT_OUTPUT_H
#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os,
                         const std::vector<T>& vec){
    os << "[";
    for (auto num : vec)
    {
        os << num << ", ";
    }
    os << "]";
    return os;
}

std::istream& operator>> (std::istream& in,  std::vector<int>& v);



#endif //INC_06_OUTPUT_OUTPUT_H
