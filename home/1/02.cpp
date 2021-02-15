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

int main() {
    Vector v;
    v.scan();
    std::cout << fixed << setprecision(2) <<v.len() << std::endl;
    return 0;
}

