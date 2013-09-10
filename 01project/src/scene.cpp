#include "scene.h"

#include <cstddef>
#include <iostream>

Scene::Scene(int xarg, int yarg, Vector viewpoint, Vector llv, Vector hv,
                Vector vv, Vector lSrc, double lIntensity, double ambLIntensity,
                int nPrimitives) {
    // member variable initialization from arguments
    this->xResolution = xarg;
    this->yResolution = yarg;

    this->lowerLeft = llv;
    this->horizontalVector = hv;
    this->verticalVector = vv;
    this->lightSource = lSrc;
    this->lightIntensity = lIntensity;
    this->ambientLightIntensity = ambLIntensity;

    // other variables
    this->primCount = 0;
    primitives = new Primitive*[nPrimitives];
    for (int i = 0; i < nPrimitives; ++i) {
        primitives[i] = NULL;
    }
}

Scene::~Scene() {
    std::cout << "Deleting primitives\n";
	for (int i = 0; i < this->primCount; ++i) {
		delete this->primitives[i];
	}

    delete[] this->primitives;
    this->primCount = 0;
}

void Scene::addPrimitive(Primitive *prim) {
	this->primitives[this->primCount] = prim;
    std::cout << this->primitives[0] << std::endl;
    this->primCount++;
}

Primitive* Scene::getPrimitiveAtIndex(int idx) const {
    if (idx < 0 || idx > this->primCount) {
        std::cout << "Returning null\n";
        return NULL;
    }

    return this->primitives[idx];
}

int Scene::numPrimitives() const {
	return this->primCount;
}