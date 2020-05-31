#include "Session.h"
#include "PPM.h"
#include "PGM.h"
#include "PBM.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

int Session::id = -1;

Session::Session()
{
    id++;
}
Session::~Session() 
{
    for (Image* i: images)
    {
        delete i;
    }
}

void Session::sessionInfo()
{
    std::cout << "Currently: session #" << id << "\n";
    if ( images.empty() )
    {
        std::cout << "There are no images in the current session. If you'd like to load some use the add command!";
    }
    else 
    {
        std::cout << "Images in this session: ";
        for (Image* image: images)
        {
            std::cout << image->getName() << " ";
        }
    }
    std::cout << "\n";
    if ( transformations.empty() )
    {
        std::cout << "There are no transformations in the current session. You can make some by using the" 
                  << " features of this app! For more information typy help.\n";
    }
    else 
    {
        std::cout << "Transformations in this session: ";
        for (std::string transformation: transformations)
        {
            std::cout << transformation << " ";
        }
        std::cout << "\n";
    }
    

}

void Session::undo()
{
    if (transformations.empty())
    {
        std::cout << "There are no transformations in the current session!\n";
        return;
    }

    transformations.pop_back();
}

void Session::add(std::string name)
{
    std::ifstream inFile (name.c_str());
    if ( !inFile.is_open() )
    {
        std::cout << "An error ocurred and this image cannot be opened!\n";
        return;
    }

    std::string magicNumber;
    inFile >> magicNumber;

    Image* newImage;
    if (magicNumber == "P1")
    {
        newImage = new PBM;
    }
    else if (magicNumber == "P2")
    {
        newImage = new PGM;
    }
    else if (magicNumber == "P3")
    {
        newImage = new PPM;
    }
    else 
    {
        std::cout << "Sorry, this format is not being supported!\n";
        return;
    }
    newImage->inputPicture(name);
    images.push_back(newImage);
}

void Session::addTransformation ( std::string transformation )
{
    transformations.push_back(transformation);
}

void Session::makeTransformations ()
{
    for (std::string transformation: transformations)
    {
        if (transformation == "grayscale")
        {
            for (Image* image: images)
            {
                image->grayscale();
            }
        }
        else if (transformation == "monochrome")
        {
            for (Image* image: images)
            {
                image->monochrome();
            }
        }
        else if (transformation == "negative")
        {
            for (Image* image: images)
            {
                image->negative();
            }
        }
        else if ( transformation == "rotateLeft" )
        {
            for (Image* image: images)
            {
                image->rotateLeft();
            }
        }
        else if ( transformation == "rotateRight")
        {
            for (Image* image: images)
            {
                image->rotateRight();
            }
        }
    }
}

void Session::save()
{
    for (Image* image: images)
    {
        std::string fileName = image->getName();
        std::ofstream outFile (fileName.c_str());
        image->printPicture(outFile);
        outFile.close();
    }
}
