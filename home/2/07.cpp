#include <bits/stdc++.h>
#include <iostream>
#include "matrix.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    Matrix *ptr = NULL;
    int constr;
    cin >> constr;
    if (constr == 0) {
        Matrix tmp;     
        ptr = &tmp;
    } else if (constr == 1) {
        double k;
        cin >> k;
        Matrix tmp(k);
        ptr = &tmp;
    } else if (constr == 9) {
        double m[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> m[i][j];
            }
        }
        Matrix tmp(m);
        ptr = &tmp;
    }
    cout << *ptr;
    return 0;
}

