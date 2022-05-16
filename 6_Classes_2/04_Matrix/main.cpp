#include <iostream>
#include <vector>

using namespace std;

template<typename T, size_t N>
class Matrix{
    // как хранить?
    // vector<int>
    // vector<vector<int>>
    // deque<deque<int>>
    // array<array<int,N>,N>
    // map<pair<size_t,size_t>,int>
    vector<vector<T>> data;
public:
    size_t size = N;
    using Row = vector<T>;
    Matrix():data(vector<Row>(N,Row(N,T()))) {}

    const Row& operator[](size_t i) const{
        return data[i];
    }

    Row& operator[](size_t i){
        return data[i];
    }

    Matrix& operator+=(const Matrix& other){
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Matrix& a)
    {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                out << a.data[i][j] << " ";
            }
            out << "\n";
        }
        return out;
    }

};

template<class Matr>
Matr operator+(const Matr& a, const Matr& b){
    Matr tmp;
    for (int i = 0; i < a.size; ++i) {
        for (int j = 0; j < a.size; ++j) {
            tmp[i][j] = a[i][j] + b[i][j];
        }
    }
    return tmp;
}


int main() {
    Matrix<int,5> matrix;
    Matrix<int,5> matrix2;
    matrix[0][2] = 3;
    matrix2[0][1] = 5;
    std::cout << (matrix - matrix2) << std::endl;
    return 0;
}
