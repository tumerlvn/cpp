using std::setprecision;
using std::setw;
using std::setfill;	
using std::fixed;
using std::cin;
using std::cout;
using std::endl;

class Matrix {
    double m[3][3];
public:
    Matrix();
    Matrix(double k);
    Matrix(double a[3][3]);
    friend std::istream& operator>>(std::istream& input, Matrix& mtr);
    friend std::ostream& operator<<(std::ostream& output, const Matrix& mtr);
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Vector operator*(const Vector&);
};

Matrix::Matrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                m[i][j] = 1;
            } else {
                m[i][j] = 0;
            }
        }
    }
}

Matrix::Matrix(double k) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                m[i][j] = k;
            } else {
                m[i][j] = 0;
            }
        }
    }
}

Matrix::Matrix(double a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] = a[i][j];
        }
    }
}

std::istream& operator>>(std::istream& input, Matrix& mtr) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mtr.m[i][j];
        }
    }
    return input;
}

std::ostream& operator<<(std::ostream& output, const Matrix& mtr) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << fixed << setprecision(2) << mtr.m[i][j] << " ";
        }
        cout << endl;
    }
    return output;
}

Matrix Matrix::operator+(const Matrix& mtr) {
    Matrix res;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res.m[i][j] = this->m[i][j] + mtr.m[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator-(const Matrix& mtr) {
    Matrix res;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res.m[i][j] = this->m[i][j] - mtr.m[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator*(const Matrix& mtr) {
    Matrix res;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res.m[i][j] += this->m[i][k] * mtr.m[k][j]; 
            }
        }
    }
    return res;
}

Vector Matrix::operator*(const Vector& v) {
    Vector res;
    res.x += v.x * this->m[0][0] + v.y * this->m[0][1] + v.z * this->m[0][2]; 
    res.y += v.x * this->m[1][0] + v.y * this->m[1][1] + v.z * this->m[1][2]; 
    res.z += v.x * this->m[2][0] + v.y * this->m[2][1] + v.z * this->m[2][2]; 
    return res;
}
