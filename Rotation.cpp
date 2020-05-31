#include <vector>
#include <string>
#include "PPM.h"
#include "RGB.h"
#include "Rotation.h"

#include "CLR.h"
#include "Editor.h"
#include "Functions.h"
#include "Image.h"
#include "PBM.h"
#include "PGM.h"
#include "Session.h"


template<class T>
std::vector<T> Rotation<T>::rotateRight (std::vector<T> pixels, int width, int height)
{
    std::vector<T> rotated;
    for(int i = 0; i < width*height; i++)
    {
        rotated.push_back( pixels [( (width-1)-(i)%width)*height + (i/width)]);
    }
    
    return rotated;
}

template<class T>
std::vector<T> Rotation<T>::rotateLeft (std::vector<T> pixels, int width, int height)
{
    std::vector<T> rotated;
    for(int i = 0; i < width*height; i++)
    {
        rotated.push_back(pixels [( (i%width) + 1 ) * height - ( i/width ) - 1]); 
    }
    return rotated;
}
