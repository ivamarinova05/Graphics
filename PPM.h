#ifndef PPM_H
#define PPM_H
#include <string>
#include <vector>

#include "RGB.h"
#include "PGM.h"
#include "Image.h"

class PPM: public Image
{
    private:
    
    int maxValue;
    std::vector<RGB> pixels;
    
    public:
    PPM();
    void inputPicture(std::string name);
    void printPicture(std::ostream&);
    int getPixelsNum () {return pixels.size();}
    void negative() override;
    void  grayscale() override ;
    void monochrome()override ;
    std::string getName() {return fileName;}

    void rotateRight() override;
    void rotateLeft() override;
    RGB& operator[](int);

    ~PPM();



};

#endif
