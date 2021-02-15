#include <bits/stdc++.h>
#include <iostream>

using std::setprecision;
using std::setw;
using std::setfill;	
using std::fixed;

struct Vector{
    double x, y;
    void scan();
    void print();
    double len();
    int quadrant();
    void normalize();
    double dot(const Vector &tmp);
    int cross(const Vector &tmp);
    bool isCollinear(const Vector &tmp);
    Vector sum(const Vector &tmp);
};

void Vector::scan() {
    std::cin >> x >> y;
}

void Vector::print() {
    std::cout << "(" << fixed << setprecision(2)<< x << "; " <<
    fixed << setprecision(2) << y << ")"<< std::endl;
}

double Vector::len() {
    return sqrt(x*x + y*y);
}

int Vector::quadrant() {
    if (x > 0) {
        if (y > 0) {
            return 1;
        } else if (y < 0) {
            return 4;
        }
    } else if (x < 0) {
        if (y > 0) {
            return 2;
        } else if (y < 0) {
            return 3;
        }
    }
    return 0;
}

void Vector::normalize() {
    double len = this->Vector::len();
    x = x/len;
    y = y/len;
}

double Vector::dot(const Vector &tmp) {
    return (this->x * tmp.x + this->y * tmp.y);
}

int Vector::cross(const Vector &tmp) {
    return (this->x * tmp.y - this->y * tmp.x);
}

bool Vector::isCollinear(const Vector &tmp) {
    return (this->x / tmp.x == this->y / tmp.y);
}

Vector Vector::sum(const Vector &tmp) {
    Vector res;
    res.x = this->x + tmp.x;
    res.y = this->y + tmp.y;
    return res;
}

int main() {
    Vector v;
    Vector t;
    v.scan();
    t.scan();
    v.sum(t).print();
    return 0;
}

