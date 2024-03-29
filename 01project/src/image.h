#ifndef IMAGE_H
#define IMAGE_H

#include "rgb.h"

class Image {
  private:
    int xsize,ysize; // resolution
    RGB *rgb;        // pixel intensities
  public:
    Image( int m, int n );       // allocates image of specified size
    
    RGB &pixel ( int i, int j );  // access to a specific pixel
    void save_to_ppm_file ( char *filename );
};

#endif