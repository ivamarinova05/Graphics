#ifndef ROTATION_H
#define ROTATION_H

#include <vector>
#include <string>
#include "PPM.h"
#include "RGB.h"

template <class T>
class Rotation
{
    public:
    static std::vector<T> rotateRight (std::vector<T> , int , int );
    static std::vector<T> rotateLeft (std::vector<T> , int, int);

};
#endif
