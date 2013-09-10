#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "primitive.h"
#include "vector.h"

class Triangle : public Primitive {
	public:
		Triangle(Vector a1, Vector a2, Vector a3) :
			a1(a1), a2(a2), a3(a3) {}

		virtual double checkIntersection(Ray r);
		
		Vector a1, a2, a3;
};

#endif