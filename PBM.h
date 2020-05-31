#ifndef PBM_H
#define PBM_H

#include <string>
#include <vector>

#include "Image.h"

class PBM: public Image
{
    private:

    std::vector<int> pixels;

    public:

    PBM();
    ~PBM();

    void inputPicture (std::string );
    void printPicture (std::ostream&);
    void negative ();
    void rotateLeft();
    void rotateRight();


    std::string getName() {return fileName;}



};

#endif
