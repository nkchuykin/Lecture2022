#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string res = "1 2     3 4 5546 45343 4353";
    istringstream sstream(res);
    int sum = 0;
    int num;
    while (sstream >> num)
    {
        sum +=num;
    }
    std::cout << sum << "\n";

    stringstream out;
    out << 1 << "2" << " " << boolalpha << true << " " << 2+7 << "\n";
    cout << out.str();

    int x;
    out >> x;
    cout << x;

    return 0;
}
