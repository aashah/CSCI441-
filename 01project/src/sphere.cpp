#include "sphere.h"

#include <cmath>
#include <iostream>

#include "util.h"

double Sphere::checkIntersection(Ray r) {
    // this->center, this->radius
    // r.origin, r.direction
    Vector co = r.origin - this->center;

    double a = pow(r.direction.magnitude(), 2.);
    double b = 2 * dot(co, r.direction);
    double c = pow(co.magnitude(), 2.) - pow(this->radius, 2.);

    double discriminant = pow(b, 2.) - (4 * a * c);

    double soln = -1;
    if (fabs(discriminant) <= TOLERANCE) {
        // 1 real solution
        
        double firstSoln = (-1 * b)/(2 * a);

        if (firstSoln >= 0) {
            soln = firstSoln;
        }

    } else if (discriminant > 0) {
        // 2 real solutions
        
        double firstSoln = (-1 * b + discriminant)/(2 * a);
        double secondSoln = (-1 * b - discriminant)/(2 * a);

        if (firstSoln >= 0) {
            soln = firstSoln;
        }
        if (secondSoln >= 0 && secondSoln < firstSoln) {
            soln = secondSoln;
        }
    }

    return soln;
}