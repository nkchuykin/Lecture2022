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

        bool operator!=(const MyVectorIterator& other) const{
            return this->cur != other.cur;
        }
    };
    vector<T> data;
public:
    using iterator = MyVectorIterator;
    MyVector() = default;
    template<typename Iter>
    MyVector(Iter begin, Iter end) : data(begin,end) {}

    iterator begin(){
        //return {*this,0};
        //return iterator{*this,0};
        return iterator(*this,0);
    }

    iterator end(){
        return {*this,data.size()};
    }

    T& operator[](size_t index){
        return data[index];
    }

    const T& operator[](size_t index) const{
        return data[index];
    }


};

int main() {
    vector v{1,2,3,4,5};
    MyVector<int> tmp{v.begin(),v.end()};

    for (const auto& el : tmp) {
        cout << el << " ";
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
