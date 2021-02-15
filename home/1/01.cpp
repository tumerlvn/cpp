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
};

void Vector::scan() {
    std::cin >> x >> y;
}

void Vector::print() {
    std::cout << "(" << fixed << setprecision(2)<< x << "; " <<
    fixed << setprecision (2) << y << ")"<< std::endl;
}

int main() {
    Vector v;
    v.scan();
    v.print();
    return 0;
}

