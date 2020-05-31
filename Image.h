#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

class Image
{
    protected:
    std::string fileName;
    std::string magicNumber;
    std::vector<std::string> comments;
    int width;
    int height;

    public:
    Image();
    Image(std::string, std::string, std::vector<std::string>, int, int);
    ~Image();
    virtual void inputPicture(std::string name) = 0;
    virtual void printPicture (std::ostream& out ) = 0;
    virtual void negative () = 0;
    virtual void grayscale();
    virtual void monochrome();
    virtual void rotateLeft() = 0;
    virtual void rotateRight() = 0;
    virtual std::string getName() = 0;

};

#endif
