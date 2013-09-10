#ifndef SPHERE_H
#define SPHERE_H

#include "primitive.h"
#include "ray.h"
#include "vector.h"

class Sphere : public Primitive {
	public:

		Sphere(Vector carg, double rarg) :
			center(carg), radius(rarg) {}

		virtual double checkIntersection(Ray r);
		
		Vector center;
    	double radius;
};

#endif