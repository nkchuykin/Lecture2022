#include <iostream>

using namespace std;

#define FIVE 5

#ifdef FIVE
int x = 5;
#else
int x = 4;
#endif

#define sum(a,b)  (a + b)

#define PRINT_SUM(a,b)  { \
    std::cout << #a << " + " << #b << " = "  << a+b<<"\n"; \
    std::cerr <<  __FILE__ << " " << __LINE__  <<"\n";     \
    }\

int main() {
    std::cout << FIVE << std::endl;
    std::cout << sum(FIVE,FIVE) * 2 << std::endl;
    int x = 3, y = 4;
    PRINT_SUM(3,4);
    PRINT_SUM(5,x);
    PRINT_SUM(y,x);
    for (int i = 0; i < 5; i++)
        PRINT_SUM(FIVE,i)
    // sum(x,y) x + y = ...
    // sum(a,b) a + b = ...
    return 0;
}
