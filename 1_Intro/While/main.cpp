#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    int res = 0;
    while (num != 0)
    {
        if (num % 3 == 0)
            ++res;
        cin >> num;
    }
    cout << res;

    return 0;
}
