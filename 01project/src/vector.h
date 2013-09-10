#ifndef VECTOR_H
#define VECTOR_H

class Vector {
	public:
		Vector() :
			x(0), y(0), z(0) {}
		
		Vector(double xarg, double yarg, double zarg) :
			x(xarg), y(yarg), z(zarg) {}

		Vector(const Vector &v1) :
			x(v1.x), y(v1.y), z(v1.z) {}

        double magnitude() const;

        Vector operator+(const Vector &v) const;
        Vector operator+(const double val) const;

        Vector operator-(const Vector &v) const;
        Vector operator-(const double val) const;

        Vector operator*(const Vector &v) const;
        Vector operator*(const double val) const;

        Vector operator/(const Vector &v) const;
        Vector operator/(const double val) const;

		double x, y, z;
};

// Vector vector_add(Vector v1, double val);
// Vector vector_add(Vector v1, Vector v2);
// Vector vector_sub(Vector v1, Vector v2);
// Vector vector_mult(Vector v1, double val);
double dot(Vector v1, Vector v2);

#endif