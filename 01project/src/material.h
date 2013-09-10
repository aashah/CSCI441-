#ifndef MATERIAL_H
#define MATERIAL_H

#include "rgb.h"

class Material {
  public:
  	RGB k_diffusion;
  	RGB k_ambient;
    double k_specular;
    double n_specular;
};

#endif