
/*
put your name here, just in case ****
Project 1: Ray Tracing
CSCI 441
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "image.h"
#include "raytrace.h"
#include "rgb.h"
#include "scene.h"
#include "vector.h"

using namespace std;

Vector calculateCenterOfPixel(const Scene* scene, int x, int y);

int main ( int argc, char *argv[] )
{

  string inputFile = "input.txt";

  if (argc > 2) {
    inputFile = argv[1];
  }

  Scene* inputScene = readInput(inputFile);
  Image img = renderScene(inputScene);
  img.save_to_ppm_file((char*)"output.ppm");

  delete inputScene;

  // read_input_file();

 //  image img(resolution_x,resolution_y);
 //  for ( x=0; x<resolution_x; x++ )
 //    for ( y=0; y<resolution_y; y++ )
 //      {
	// RGB &pix = img.pixel(x,y);

	/* 
	   call your raytracer here
	   then assign the rgb values
	   it returns to the pixel 
	*/

	// // this is just to produce a fun image...
	// pix.r = 0.5+0.5*sin(sin(x/30.0)+y*y/700.0);
	// pix.g = 0.5+0.5*sin(y/71.0);
	// pix.b = 0.5+0.5*sin(x*x*x/120000.0+y*y/1700.0);
 //      }

 //  /* save the image */
 //  

  return 0;
}

Image renderScene(const Scene* scene) {
  cout << "Beginning to render\n";
  int xRes = scene->xResolution;
  int yRes = scene->xResolution;

  cout << "Number of primitives: " << scene->numPrimitives() << endl;

  Image ret(xRes, yRes);
  for (int x = 0; x < xRes; ++x) {
    for (int y = 0; y < yRes; ++y) {


      RGB &pix = ret.pixel(x, yRes - y - 1);
      pix.r = pix.g = pix.b = 0;

      // calculate center of pixel position
      Vector centerOfPixel = calculateCenterOfPixel(scene, x, y);

      // Calculate ray that goes through the window
      Vector directionVector = centerOfPixel - scene->viewpoint;

      // Ray = centerOfPixel + (t * directionVector)
      Ray directionRay;
      directionRay.origin = scene->viewpoint;
      directionRay.direction = directionVector;

      // check intersecting primitives
      
      int numPrimitives = scene->numPrimitives();
      double minIntersectionTime = -1;
      int matchingPrimIdx = -1;

      for (int i = 0; i < numPrimitives; ++i) {
        Primitive *prim = scene->getPrimitiveAtIndex(i);
        if (!prim) {
          // Null primitive returned, invalid index/object?
          minIntersectionTime = 1;
          matchingPrimIdx = -1;
          cout << "INVALID PRIMITIVE RETRIEVED\n";
          exit(-1);
          break;
        }

        double lowestIntersectionTime = prim->checkIntersection(directionRay);
        if (lowestIntersectionTime >= 0) {
          // We have a positive time T where the primitive intersects
          if (minIntersectionTime == -1 ||
              lowestIntersectionTime < minIntersectionTime) {
            minIntersectionTime = lowestIntersectionTime;
            matchingPrimIdx = i;
          }
        }
      }

      if (matchingPrimIdx != -1 &&
          minIntersectionTime != -1) {

        // We found a primitive intersecting the eye ray for this pixel
        // Figure out the color to draw it

        Primitive *prim = scene->getPrimitiveAtIndex(matchingPrimIdx);
        // draw primitive color onto RGB value
        // get material from primitive
        Material primMaterial = prim->material;

        pix = primMaterial.k_diffusion;
        
      }
    }
  }
  cout << "RETURNING\n";
  return ret;
}

Vector calculateCenterOfPixel(const Scene* scene, int x, int y) {
  int xRes = scene->xResolution;
  int yRes = scene->xResolution;

  Vector result = (scene->lowerLeft + (scene->horizontalVector * ((x + .5)/xRes)) +
                    (scene->verticalVector * ((y + .5)/yRes)));
  return result;
}