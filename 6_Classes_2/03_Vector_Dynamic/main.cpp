#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class MyVector{
    class MyVectorIterator{
        size_t cur;
        MyVector& vec;
    public:
        MyVectorIterator(MyVector& vec, size_t index) : cur(index), vec(vec) {}
        MyVectorIterator& operator++(){
            cur++;
            // MyVectorIterator* this
            return *this;
        }

        T& operator*(){
            return vec[cur];
        }

        bool operator==(const MyVectorIterator& other) const{
            return this->cur == other.cur;
        }

        size_t operator-(const MyVectorIterator& other) const{
            return this->cur - other.cur;
        }

        bool operator!=(const MyVectorIterator& other) const{
            return this->cur != other.cur;
        }
    };
    size_t size;
    T* data;
public:
    using iterator = MyVectorIterator;
    MyVector() : size(0) , data(nullptr){ }
    MyVector(const MyVector& other):size(other.size), data(new T[size]){
        for (int i = 0; i < size; ++i) {
            data[i]= other.data[i];
        }
    }
   /* MyVector(const MyVector&& other)  noexcept = default;/*:size(0),data(nullptr){
        swap(size,other.size);
        swap(data,other.data);
    }*/

    MyVector& operator=(const MyVector& other){
        if (this == &other){
            return *this;
        }
        size = other.size;
        delete[] data;
        data = new T[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }
    /*MyVector& (const MyVector& other):size(other.size), data(new T[size]){
        for (int i = 0; i < size; ++i) {
            data[i]= other.data[i];
        }
    }*/
    template<typename Iter>
    MyVector(Iter begin, Iter end){
        size = end - begin;
        data = new T[size];
       /*
        * try
        {
            data = new T[size];
            //
            data2 = new T[size];
        }
        catch (...){
            delete[] data;
            delete[] data2;
            throw;
        }
        */
        int i = 0;
        while(begin!=end){
            data[i++] = *begin;
            begin++;
        }

    }

    iterator begin(){
        //return {*this,0};
        //return iterator{*this,0};
        return iterator(*this,0);
    }

    iterator end(){
        return {*this,size};
    }

    T& operator[](size_t index){
        return data[index];
    }

    const T& operator[](size_t index) const{
        return data[index];
    }

    ~MyVector(){
        delete[] data;
    }


};

int main() {
    /*int* pInt = new int[3]{3,2,1};

    cout << *(pInt + 1) << "\n";
    cout << pInt[1] << "\n";
    cout << 1[pInt] << "\n";

    delete[] pInt;*/

    vector v{1,2,3,4,5};
    MyVector<int> tmp{v.begin(),v.end()};

    MyVector tmp2 = tmp;
    tmp2 = tmp2;

    for (const auto& el : tmp) {
        cout << el << " ";
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
