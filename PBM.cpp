#include "PBM.h"
#include "Rotation.h"

#include <iostream>
#include <fstream>

PBM::PBM() = default;

PBM::~PBM() = default;

void PBM::inputPicture(std::string name)
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

    image >> width >> height ;
    
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

void PBM::printPicture(std::ostream& out)
{
    out << magicNumber << std::endl;

    for (std::string comment: comments)
    {
        out << comment << std::endl;
    }

    out << width << " " << height << std::endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            out << pixels[i*width + j] << " ";
        }
        out << std::endl;
    }
}

void PBM::negative()
{
    for (int i = 0; i < pixels.size(); i++)
    {
        if (pixels[i] == 0) pixels[i] = 1;
        else  pixels[i] = 0;
    }
}

void PBM::rotateRight()
{
    pixels =  Rotation<int>::rotateRight(pixels, width, height);
}

void PBM::rotateLeft()
{
    pixels =  Rotation<int>::rotateLeft(pixels, width, height);
}
