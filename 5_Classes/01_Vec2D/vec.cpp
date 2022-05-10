//
// Created by nchuykin on 10.05.2022.
//

#include "vec.h"
#include <stdexcept>
#include <cmath>

Vec2D Sum2(const Vec2D &first, const Vec2D &second) {
    return {first.X + second.X, first.Y + second.Y};
}

int Vec2D::GetX() const {
    return X;
}

int Vec2D::GetY() const {
    return Y;
}

void Vec2D::SetX(int val) {
    if (val < -1000 || val > 1000)
        throw std::invalid_argument("value should be between -1000 and 1000");
    X = val;
}

void Vec2D::SetY(int val) {
    if (val < -1000 || val > 1000)
        throw std::invalid_argument("value should be between -1000 and 1000");
    Y = val;
}

Vec2D Vec2D::Sum(const Vec2D &other) const {
    return {X + other.X, Y + other.Y};
}

std::ostream &operator<<(std::ostream &out, const Vec2D &vec) {
    out << vec.X << " " << vec.Y << " " << vec.GetLength();
    return out;
}

Vec2D Sum(const Vec2D &first, const Vec2D &second) {
    return {first.GetX() + second.GetX(), first.GetY() + second.GetY()};
}

double Vec2D::GetLength() const {
    return sqrt(X*X +Y*Y);
}

Vec2D Vec2D::operator+(const Vec2D &other) const {
    return {X + other.X, Y + other.Y};
}

Vec2D::Vec2D() : X(0), Y(0) {}

Vec2D::Vec2D(int x, int y) : X(x), Y(y) {}

Vec2D Vec2D::operator++() {
    X++;
    Y++;
    return {X,Y};
}

Vec2D Vec2D::operator++(int) {
    Vec2D res{X,Y};
    X++;
    Y++;
    return res;
}
