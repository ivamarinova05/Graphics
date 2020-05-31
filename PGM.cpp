#include "PGM.h"
#include "PPM.h"
#include "Rotation.h"

#include <fstream>

PGM::PGM() = default;
PGM::~PGM() = default;

void PGM::inputPicture(std::string name)
{
    fileName = name;

    std::ifstream image(name.c_str());
    if (!image.is_open())
    {
        std::cout << "An error occured!\n";
    }

    image >> magicNumber;

    char ignore;
    image >> ignore;
    while (ignore == '#')
    {
        std::string comment;
        image.unget();
        getline (image, comment);
        comments.push_back(comment);
        image >> ignore;
    }

    image.unget();

    image >> width >> height >> maxValue;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int pixel;
            image >> pixel;
            pixels.push_back(pixel);

        }
    }
    image.close();
}

void PGM::printPicture( std::ostream& out)
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
            out << pixels[i*width + j] << " ";
        }
        out << std::endl;
    }
}

void PGM::negative()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pixels[i*width + j ] = maxValue - pixels[i*width + j];
        }
    }
}

void PGM::rotateRight()
{
    pixels =  Rotation<int>::rotateRight(pixels, width, height);
}

void PGM::rotateLeft()
{
    pixels =  Rotation<int>::rotateLeft(pixels, width, height);
}

void PGM::monochrome () {}
