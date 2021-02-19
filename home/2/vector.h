//#include <bits/stdc++.h>
//#include <iostream>

using std::setprecision;
using std::setw;
using std::setfill;	
using std::fixed;

class Vector{
    double x, y, z;
public:
    Vector();
    friend std::istream &operator>>(std::istream &input, Vector &v) {
        input >> v.x >> v.y >> v.z;
        return input;
    }
    friend std::ostream &operator<<(std::ostream &output, Vector &v) {
        output << "(" << fixed << setprecision(2) << v.x << "; " <<
        v.y << "; " << v.z << ")";
        return output;
    }
    Vector operator+(const Vector&);
    Vector operator-(const Vector&);
    Vector operator*(double);
    Vector operator/(double);
    Vector operator*(const Vector&);
    double operator[](char);
    friend Vector Matrix::operator*(const Vector&);

};

Vector::Vector() {
    x = y = z = 0;
}

Vector Vector::operator+(const Vector& v) {
    Vector result;
    result.x = this->x + v.x;
    result.y = this->y + v.y;
    result.z = this->z + v.z;
    return result;
}

Vector Vector::operator-(const Vector& v) {
    Vector result;
    result.x = this->x - v.x;
    result.y = this->y - v.y;
    result.z = this->z - v.z;
    return result;
}

Vector Vector::operator*(double k) {
    Vector result;
    result.x = this->x * k;
    result.y = this->y * k;
    result.z = this->z * k;
    return result;
}

Vector Vector::operator/(double k) {
    Vector result;
    if (k == 0) {
        std::cout << "Error: division by zero" << std::endl;
    } else {
        result.x = this->x / k;
        result.y = this->y / k;
        result.z = this->z / k;
    }
    return result;
}

Vector Vector::operator*(const Vector& v) {
    Vector result;
    result.x = this->y * v.z - v.y * this->z;
    result.y = -(this->x * v.z - v.x * this->z);
    result.z = this->x * v.y - v.x * this->y;
    return result;
}

double Vector::operator[](char ch) {
    switch (ch) {
        case 'x':
            return this->x;
            break;
        case 'y':
            return this->y;
            break;           
        case 'z':
            return this->z;
            break;
        default:
            std::cout << "Error: incorrect index" << std::endl;
    }
    return 0;
}
