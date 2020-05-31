#include "PPM.h"
#include "PGM.h"
#include "RGB.h"
#include "Functions.h"
#include "Rotation.h"

#include <fstream>
#include <vector>

PPM::PPM() = default;

PPM::~PPM() = default;

void PPM::inputPicture( std::string name)
{
    fileName = name;
    std::ifstream image (name.c_str());
    if ( !image.is_open() )
    {
        std::cout << "An error occured!\n";
        return;
    }
    image >> magicNumber;

    char ignore;
    image >> ignore;
    while (ignore == '#')
    {
        std::string comment;
        image.unget();
        getline(image, comment);
        comments.push_back(comment);
        image >> ignore;
    }
    image.unget();
    image >> width >> height >> maxValue;
    
   
    for (int i = 0; i < height; i++)
    {
        for ( int j = 0; j < width; j++)
        {
            RGB pixel;
            pixel.input(image);
            pixels.push_back(pixel);
        }
    }
    image.close();  
}

void PPM::printPicture( std::ostream& out)
{
    out << magicNumber << std::endl;

    for (std::string comment: comments)
    {
        out << comment << std::endl;
    }

    out << width << " " << height << std::endl
        << maxValue << std::endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pixels[i*width + j].print(out);
        }
        out << std::endl;
    }
}

void PPM::negative ()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pixels[i*width + j].negative(maxValue);
            
        }
    }
}
void PPM::grayscale()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pixels[i*width + j].setGray();
            
        }
    }
}

RGB& PPM::operator[] ( int i)
{
    return pixels[i];
}

void PPM::rotateRight()
{
    std::cout << "Your image is being converted! Please wait, this may take a few seconds...\n";
    pixels =  Rotation<RGB>::rotateRight(pixels, width, height);
}

void PPM::rotateLeft()
{
    pixels = Rotation<RGB>::rotateLeft(pixels, width, height);
}

void PPM::monochrome() {}
