#include <bits/stdc++.h>
#include <iostream>
#include "vector.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    Vector v, t;
    cin >> v >> t;
    Vector res = v * 2 - t / 3 + v * t;
    cout << res << endl;
    return 0;
}

