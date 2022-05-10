//
// Created by nchuykin on 10.05.2022.
//

#ifndef INC_01_VEC2D_VEC_H
#define INC_01_VEC2D_VEC_H

#include <iostream>


class Vec2D{
    int X, Y;
public:
    // default constructor
    // Vec2D() = default;

    Vec2D();
    Vec2D(int x, int y);

    int GetX() const;
    int GetY() const;
    void SetX(int val);
    void SetY(int val);

    Vec2D Sum(const Vec2D& other) const;

    friend Vec2D Sum2(const Vec2D& first, const Vec2D& second);

    Vec2D operator+(const Vec2D& other) const;
    Vec2D operator++();
    Vec2D operator++(int);

    double GetLength() const;

    friend std::ostream& operator<<(std::ostream& out, const Vec2D& vec);


};

Vec2D Sum(const Vec2D& first, const Vec2D& second);
Vec2D Sum2(const Vec2D& first, const Vec2D& second);



#endif //INC_01_VEC2D_VEC_H
