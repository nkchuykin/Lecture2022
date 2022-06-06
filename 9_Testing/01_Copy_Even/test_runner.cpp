//
// Created by nkchuykin on 06.06.2022.
//

#include "test_runner.h"

using namespace std;

void Assert(bool b, const std::string &hint) {
    AssertEqual(b,true, hint);
}