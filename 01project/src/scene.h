#ifndef SCENE_D
#define SCENE_D

#include <vector>
#include "primitive.h"

class Scene {
	public:
		Scene(int xarg, int yarg, Vector viewpoint, Vector llv, Vector hv,
				Vector vv, Vector lSrc, double lIntensity, double ambLIntensity,
				int nPrimitives);

		~Scene();

		void addPrimitive(Primitive *prim);
		Primitive* getPrimitiveAtIndex(int idx) const;
		
		int numPrimitives() const;

		// Scene properties
		int xResolution;
		int yResolution;
		Vector viewpoint;
		Vector lowerLeft;
		Vector horizontalVector;
		Vector verticalVector;
		Vector lightSource;

		double lightIntensity;
		double ambientLightIntensity;

	private:
		// We keep this private to ensure proper allocation/deallocation
		// Primitives management
		int primCount;
		Primitive **primitives;
};

#endif