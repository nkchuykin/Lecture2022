#include <iostream>
#include <vector>
#include <memory>

using namespace std;

/*
class A{
public:
    int x;
};
class B : public virtual A{};
class C : public virtual A{};
class D : public B, public C{
    void f(){
        A::x = 3;
    }
}; */

class Base{
    int x;
public:
    virtual void f() = 0;
};

void Base::f(){
    cout << "Base\n";
}


class Derived : public Base{
    int y;
public:
    void f() /*override*/ {
        Base::f();
        cout << "Derived" << "\n";
    }
};

int main() {
    //Base b;
    Derived d;
    //b.f();
    d.f();

    vector<unique_ptr<Base>> vec;
    vec.push_back(make_unique<Derived>());
    vec.push_back(make_unique<Derived>());
    cout << "=====\n";
    for (auto& b : vec){
        b->f();
    }

    Base& b2 = static_cast<Base&>(d);
   // Derived d2 = dynamic_cast<Derived&>(b);  exception
   // d2.f();
    return 0;
}
