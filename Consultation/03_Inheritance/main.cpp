#include <iostream>

using namespace std;

struct A{
    size_t a = 2;
};

class B : public virtual A { // based-on
    size_t b = 4;
};

struct C : public virtual A  { // private, protected, public // is-a
    size_t c = 8;
};

struct D: B, C {
    size_t d = 8;
};
int main() {
    B b;
    A a;
    C c;
    D d;
    A x = d;
    size_t* ptr = reinterpret_cast<size_t*>(new D());

    cout <<hex<< (*ptr) << dec<< endl;
    cout << *(ptr + 1) << endl;
    cout << *(ptr + 2) << endl;
    cout << *(ptr + 3) << endl;

    return 0;
}
