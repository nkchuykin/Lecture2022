#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;
 class C{
    int number;
    inline static int counter = 1;
public:
     int x;
    C(){
        number = counter++;
        cout << "Object " << number <<" created" << "\n";
    }

    C(const C& c) {
        number = counter++;
        cout << "Object " << number <<" copy of "<<c.number << "\n";
    }

    //  lvalue
    // rvalue 4
    C(C&& c) {
        number = counter++;
        cout << "Object " << number <<" moved from "<< c.number << "\n";
    }
    ~C(){
        cout << "Object " << number <<" destroyed" << "\n";
    }
};

void addStrToVector(vector<string>& v, string str){
    cout <<"func\n";
    cout << str<< "\n";
    v.push_back(move(str));
    cout << str<< "\n";
    cout <<"end func\n";
}

//int C::counter = 0;

int main() {


    //C c,c2;
    //C();
    //C c3 = C(C(C(C(c2)))); // copy elision

    //const auto& ref_to_temp = C();

    //vector<C> v2(3);
    //v2.emplace_back(C());

    //vector<string> v = {"abc"};
    //addStrToVector(v,"def");
    //cout << v[1] <<"\n";
    C *cPtr = new C();
    (*cPtr).x; // Var 1
     cPtr->x;  // Var 2

    int* arr = new int[100];
    arr[0] = 2;
    arr[1] = 5;


    cout << *(1 + arr) <<"\n";
    cout << arr[1] << "\n";
    cout << 1[arr] << "\n";

    delete[] arr;

    delete cPtr;

    return 0;
}
