#ifndef RAYTRACE_H
#define RAYTRACE_H

#include <string>

#include "image.h"
#include "scene.h"

Image renderScene(const Scene* scene);
Scene* readInput(std::string inputFile);

#endif