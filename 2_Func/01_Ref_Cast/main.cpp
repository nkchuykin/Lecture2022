#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 3;
    int n2 = 7;
    string s = "abc";
    vector<int> v = {1, 2, 3};

    int& n_ref = n, n_ref2 = n;
    // изменение n, а не изменение связанной переменной n_ref = n2;
    //CE int& s_ref;
    n++;
    cout << n_ref << " " << n_ref2 << "\n";

    int* p_int = &n;

    cout << *p_int << "\n";
    (*p_int) = 17;
    cout << n << " " << n_ref << "\n";

    cout << "-----" << "\n";

    int a,b,c;

    cout << "&a = " << &a <<"\n";
    cout << "&b = " << &b <<"\n";
    cout << "&c = " << &c <<"\n";

    cout << "-----" << "\n";

    cout << "&n_ref = " << &n_ref << "\n";
    cout << "&n = " << &n << "\n";

    cout << "-----" << "\n";

    const int& cn_ref = n_ref;

    //CE cn_ref += 1;

    // int to double
    int val = 3;
    double x = double(val);
    // C-style cast
    double bad = (double)val;
    // Good!
    double g = static_cast<double>(val);

    //dynamic_cast - inheritance

    //const_cast
    int& r2_n = const_cast<int&>(cn_ref);
    r2_n = 2;

    // reinterpet_cast
    uint64_t n_23 = reinterpret_cast<uint64_t>(p_int);
    cout << *p_int << " " << n_23 << "\n";






    return 0;
}
