#ifndef PRIMITIVE_H
#define PRIMITIVE_H

// TODO define some constants for types
#include "material.h"
#include "ray.h"

class Primitive {
	public:
		virtual double checkIntersection(Ray r) = 0;
		Material material;
};

#endif