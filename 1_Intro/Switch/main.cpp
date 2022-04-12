#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    switch(n){
        case 1:
            cout << "one" <<"\n";
            break;
        case 2:
            cout << "two" <<"\n";
            break;
        case 3:
            cout << "three" << endl;
            break;
        default:
            cout << "many";
            break;
    }


    return 0;
}
