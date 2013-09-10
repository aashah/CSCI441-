#include <assert.h>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>

#include "primitive.h"
#include "raytrace.h"
#include "scene.h"
#include "sphere.h"
#include "triangle.h"

using namespace std;

Primitive* readPrimitive(ifstream& ifs, char primitive_type);

Scene* readInput(string inputFile) {
	ifstream ifs(inputFile.c_str());
	assert(ifs);

	int resolution_x, resolution_y;
	Vector viewpoint;

	Vector lowerLeft, horizontalVector, verticalVector;
	Vector lightSource;
	double lightIntensity, ambientLightIntensity;
	int number_of_primitives;

	ifs >> resolution_x >> resolution_y;
	ifs >> viewpoint.x >> viewpoint.y >> viewpoint.z;
	ifs >> lowerLeft.x >> lowerLeft.y >> lowerLeft.z;
	ifs >> horizontalVector.x >> horizontalVector.y >> horizontalVector.z;
	ifs >> verticalVector.x >> verticalVector.y >> verticalVector.z;
	ifs >> lightSource.x >> lightSource.y >> lightSource.z;
	ifs >> lightIntensity;
	ifs >> ambientLightIntensity;
	ifs >> number_of_primitives;

	Scene *scene = new Scene(resolution_x, resolution_y,
		viewpoint, lowerLeft, horizontalVector, verticalVector, lightSource,
		lightIntensity, ambientLightIntensity, number_of_primitives);

	for (int i = 0; i < number_of_primitives; ++i) {
		char primitive_type;
		ifs >> primitive_type;
		primitive_type = tolower(primitive_type);

		Primitive* prim = readPrimitive(ifs, primitive_type);

		if (prim != NULL) {
			cout << "Adding a primitive " << prim << endl;
			scene->addPrimitive(prim);
		} else {
			// TODO Error reading primitive from file
		}
	}

	assert(number_of_primitives == scene->numPrimitives());

	return scene;
}

Primitive* readPrimitive(ifstream& ifs, char primitive_type) {
	Primitive* returnPrimitive = NULL;
	Material primitiveMaterial;

	switch (primitive_type) {
		case 's': {
			Vector center;
		    double radius;
		    double k_diffuse[3];
		    double k_ambient[3];
		    double k_specular;
		    double n_specular;

		    ifs >> center.x >> center.y >> center.z;
		    ifs >> radius;
		    ifs >> primitiveMaterial.k_diffusion.r  >> primitiveMaterial.k_diffusion.g >> primitiveMaterial.k_diffusion.b;
			ifs >> primitiveMaterial.k_ambient.r >> primitiveMaterial.k_ambient.g >> primitiveMaterial.k_ambient.b;
		    ifs >> primitiveMaterial.k_specular >> primitiveMaterial.n_specular;

		    cout << "Read a sphere\n";
		    returnPrimitive = new Sphere(center, radius);
			break;
		}
		case 't': {
			Vector a1;
		    Vector a2;
		    Vector a3;
		    double k_diffuse[3];
		    double k_ambient[3];
		    double k_specular;
		    double n_specular;
		    
		    ifs >> a1.x >> a1.y >> a1.z;
		    ifs >> a2.x >> a2.y >> a2.z;
		    ifs >> a3.x >> a3.y >> a3.z;
		    ifs >> k_diffuse[0] >> k_diffuse[1] >> k_diffuse[2];
		    ifs >> k_ambient[0] >> k_ambient[1] >> k_ambient[2];
		    ifs >> k_specular >> n_specular;

		    returnPrimitive = new Triangle(a1, a2, a3);
		    cout << "Read a triangle\n";
			break;
		}
		default: {
			cout << "Invalid primitive type specified" << endl;
			assert(0);
		}
	}

	if (returnPrimitive) {
		returnPrimitive->material = primitiveMaterial;
	}

	return returnPrimitive;
}
