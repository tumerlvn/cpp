#include <bits/stdc++.h>
#include <iostream>
#include "vector.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    Vector v;
    double k;
    cin >> v >> k;
    Vector mul = v * k;
    Vector div = v / k;
    cout << mul << endl << div << endl;
    return 0;
}

