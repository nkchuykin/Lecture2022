#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include "test_runner.h"
#include "profiler.h"

using namespace std;
using namespace std::chrono;

vector<int> CopyEven(const vector<int>& vec)
{
    vector<int> res;
    for (size_t i = 0; i < vec.size(); ++i) {
        //if (vec[i] == 8)
        //    continue;
        if (vec[i] % 2 == 0)
        {
            res.push_back(vec[i]);
        }
    }
    return res;
}

void TestSimple(){
    AssertEqual(CopyEven({}),vector<int>{});
    AssertEqual(CopyEven({1,2,3,4,5}),vector<int>{2,4});
    AssertEqual(CopyEven({1,2,3,4,5,6}),vector<int>{2,4,6}, "Even at end");
}


void TestStress(){
    for (int i = 0; i < 100; ++i) {
        vector<int> vec(1000);
        for (int j = 0; j < 1000; ++j) {
            vec[j] = rand() % 2000 - 1000;
        }
        vector<int> res;
        copy_if(vec.begin(),vec.end(), back_inserter(res),
                [] (int x){
                    return x%2 == 0;
                });
        ASSERT_EQUAL(CopyEven(vec), res);
    }
}


int main() {
    vector<int> vec {1,2,3,4,5};
    vector<set<int>> matr {{1, 2, 3}, {4,5,6},{7,8,8}};
    //Assert(2+2==5,"2+2==5");

    cout << CopyEven(vec) << endl;
    cout << matr << endl;

    TestRunner tr;
    RUN_TEST(tr,TestSimple);
    RUN_TEST(tr,TestStress);


    vector<int> vec_t(1e7);

    {
        LOG_DURATION("Stable + Quick sort");
        stable_sort(vec_t.begin(), vec_t.end());
        LOG_DURATION("Quick sort");
        sort(vec_t.begin(), vec_t.end());
    }
    return 0;
}
