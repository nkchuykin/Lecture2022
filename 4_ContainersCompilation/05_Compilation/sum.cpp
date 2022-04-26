//
// Created by nkchuykin on 25.04.2022.
//
#include "sum.h"

int sum(int a, int b)
{
    return a + b;
}

int sum (int a, int b, int c)
{
    return sum(sum(a,b),c);
}