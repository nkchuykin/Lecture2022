#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "343563356";
    auto s1 = s.substr(3,4);
    string_view sv = s;
    sv = sv.substr(3,2);
    cout << sv << "\n";
    string_view s3;
    {
        string s2 = "3424";
        s3 = s2;
    }// s2 deleted
    s3 = s3.substr(1,2);
    cout << s3;


    return 0;
}
