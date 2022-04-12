#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Date{
    int year;
    int month;
    int day;

    auto operator<=>(const Date& other) const = default;
};

ostream& operator<<(ostream& of, const Date& dt)
{
    of << dt.year << " " << dt.month << " " << dt.day << "\n";
    return of;
}

int main() {
    Date d1{2022,04,11};
    Date d2{2022,04,23};
    Date d3{2021,04,23};
    Date d4{2020,04,23};
    Date d5{2028,8,17};
    vector<Date> v = {d1, d2,d3,d4,d5};
    sort(begin(v),end(v));

    for (auto d : v) {
        cout << d;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
