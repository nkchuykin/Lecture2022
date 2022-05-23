#include <iostream>
#include <vector>

using namespace std;

class A{
public:
    int x;
    A():x(0){
        cout << "A()\n";
    }
    void f(){
        cout << "x = "<< x<< "\n";
    }
    ~A(){
        cout << "~A()\n";
    }
};

//is-a
class B : public A{
public:
    int y;
    B():y(0){
        cout << "B()\n";
    }
    void g(){
        cout << "y =" << y <<"\n";
    }
    ~B(){
        cout << "~B()\n";
    }

};
//has-a
class C {
    int y;
public:
    A a;
    void g(){
        cout << "C\n";
    }

    C():y(0){
        cout << "C()\n";
    }

    ~C(){
        cout << "~C()\n";
    }
};


void F(A& x){
    x.f();
    x.x = 4;
    x.f();
}

int main() {
    A a;
    B b;
    //b.f();
    //C c;
    b.f();
    F(b);
    b.f();

    /*std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(b) << std::endl;
    std::cout << sizeof(c) << std::endl;*/
    return 0;
}
