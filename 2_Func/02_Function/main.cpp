#include <iostream>
#include <vector>

using namespace std;

int sum_int(int a, int b);

int sum_int(int a, int b, int c){
    return sum_int(sum_int(a,b),c);
}

int sum_int(int a, int b)
{
    return a + b;
}

double sum_double(double a, double b)
{
    return a + b;
}

string sum_string(string a, string b)
{
    return a + b;
}

template<typename T>
T sum(T a, T b)
{
    return a + b;
}

template<typename T>
T VeryStrangeFunc(T a, T b)
{
    a.sfgfgert();
    b.fsdgefhs();
    return a + b;
}



void PrintVector(const vector<int>& vec)
{
    // not const int&
    for (auto val : vec)
    {
        cout << val++ << " ";
    }
    cout << "\n";
}

template<typename T>
void PrintVector(const vector<int>& vec, T Action)
{
    for (auto val : vec)
    {
        cout << Action(val) << " ";
    }
    cout << "\n";
}

int DoubleSmth(int x)
{
    return 2* x;
}


int main() {
    int num = 3;
    cout << sum_int(2,4) << "\n";
    double d1=2.0,d2 = 4.0;
    cout << sum_double(d1,d2) << "\n";
    cout << "-----" << "\n";
    cout << sum(string("1"),string("2")) << "\n";
    cout << sum(3,4) << "\n";
    cout << sum<double>(1.2,3) << "\n";
    //VeryStrangeFunc(3,4);
    //sum(vector<int>(),vector<int>());
    cout << "-----" << "\n";
    vector<int> v{1,2,3,4};
    PrintVector(v);
    PrintVector(v, DoubleSmth);
    PrintVector(v, [num](int x){
        return x*num;
    });

    return 0;
}
