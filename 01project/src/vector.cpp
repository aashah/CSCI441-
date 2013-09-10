#include "vector.h"

Vector Vector::operator+(const Vector &v) const {
    Vector result;
    result.x = this->x + v.x;
    result.y = this->y + v.y;
    result.z = this->z + v.z;
    return result;
}

Vector Vector::operator+(const double val) const {
    return (*this) + Vector(val, val, val);
}

Vector Vector::operator-(const Vector &v) const {
    Vector result;
    result.x = this->x - v.x;
    result.y = this->y - v.y;
    result.z = this->z - v.z;
    return result;
}

Vector Vector::operator-(const double val) const {
    return (*this) - Vector(val, val, val);
}

Vector Vector::operator*(const Vector &v) const {
    Vector result;
    result.x = this->x * v.x;
    result.y = this->y * v.y;
    result.z = this->z * v.z;
    return result;
}

Vector Vector::operator*(const double val) const {
    return (*this) * Vector(val, val, val);
}

Vector Vector::operator/(const Vector &v) const {
    Vector result;
    result.x = this->x / v.x;
    result.y = this->y / v.y;
    result.z = this->z / v.z;
    return result;
}

Vector Vector::operator/(const double val) const {
    return (*this) / Vector(val, val, val);
}

Vector vector_add(Vector v1, double val) {
    Vector result;
    result.x = v1.x + val;
    result.y = v1.y + val;
    result.z = v1.z + val;
    return result;
}
Vector vector_add(Vector v1, Vector v2) {
	Vector result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

Vector vector_sub(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

Vector vector_mult(Vector v1, double val) {

}

double dot(Vector v1, Vector v2) {
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

double Vector::magnitude() const {
    return ((this->x * this->x) +
            (this->y * this->y) +
            (this->z * this->z));
}