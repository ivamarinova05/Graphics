#ifndef PGM_H
#define PGM_H

#include <string>
#include <vector>

#include "Image.h"
#include "PPM.h"

class PGM: public Image
{
    private:
    int maxValue;
    std::vector<int> pixels;

    public:
    PGM();
    ~PGM();
    void inputPicture(std::string);
    void printPicture(std::ostream&);
    void negative();
    std::vector<int> getPixels() const {return pixels;}
    std::string getName() {return fileName;}

    void rotateRight();
    void rotateLeft();
    void monochrome();
    int operator[] (int );


};

#endif
