#include <iostream>
#include <vector>

using namespace std;
typedef int number;
using number2 = int;
using VecIntIterator = vector<int>::iterator;
//НЕЛЬЗЯ
//typedef vector<T>::iterator vec_it<T>
template<typename T>
using vec_it = typename vector<T>::iterator;


int main() {
    //vector<int>::iterator ;
    number k = 3;
    number2 k2 = 3;

    std::cout << k << " " << k2 <<std::endl;
    return 0;
}
