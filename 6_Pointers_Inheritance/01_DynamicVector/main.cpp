#include <iostream>
#include <utility>
#include <memory>
#include <vector>

using namespace std;

// Plain Old Data int double, pointers (int*)

// classes string, vector

class MyVector{
    size_t size;
public:
    int* ptr;
    explicit MyVector(size_t size) : size(size), ptr(new int[size]){
        for (int i = 0; i < size; ++i) {
            ptr[i] = 0;
        }
    }

    MyVector(const MyVector& other) = delete; /*: size(other.size), ptr(new int[size]) {
        for (int i = 0; i < size; ++i) {
            ptr[i] = other.ptr[i];
        }
    }*/

    MyVector(MyVector&& other) noexcept :size(0),ptr(nullptr){
        swap(ptr, other.ptr);
        swap(size, other.size);
    }

    void M() {}

    ~MyVector(){
        delete[] ptr;
    }

};


MyVector F(){
    MyVector v{5};
    v.M();
    return std::move(v);
}


int main() {


    //MyVector v2 = MyVector(v1); //
    MyVector v = F();
    //MyVector v2(v1); //
    //MyVector v2{v1}; //
    //MyVector v2 = v1; //

    // istream a = cin;
    //v2.ptr[2] = 3;
    //v2.M();
    cout << v.ptr[2] << " OK \n";


    //int* ptr = new int(5);
    unique_ptr<int> uPtr(new int(5));
    unique_ptr<vector<int>> uVPtr = make_unique<vector<int>>(3,7); // size , default_value
    //RAII
    cout << *(uPtr) << " \n";
    cout << uVPtr->operator[](2) << " \n";
    cout << (*uVPtr).operator[](2) << " \n";
    cout << (*uVPtr)[2] << " \n";


    shared_ptr<int> sPtr(new int(5));
    shared_ptr<int> sPtr2(sPtr);
    shared_ptr<int> sPtr4(new int(7));
    cout << "================" << "\n";
    cout << (&sPtr==&sPtr2) << "\n";
    cout << *sPtr2 << "\n";
    *sPtr = 2;
    cout << *sPtr2 << "\n";
    cout << *sPtr << "\n";


    int x;
    int* stckPtr = &x;

    return 0;
}
