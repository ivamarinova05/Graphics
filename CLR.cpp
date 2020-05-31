#include "CLR.h"

#include <string>
#include <vector>
#include <iostream>

#include "PPM.h"
#include "PGM.h"
#include "PBM.h"
#include "Functions.h"
#include "Rotation.h"
#include "Session.h"
#include "Editor.h"

void CLR::read()
{
    Editor editor;
    std::cout << "Welcome!\n";
    
    std::string command;
    while (command != "exit")
    {
        std::cout << ">_";
        std::cin >> command;
        if ( command == "load" )
        {
            Session thisSession;
            std::string files;
            getline(std::cin, files);
            files = files.substr(1);
            if ( files.empty() )
            {
                std::cout << "Please add one or more files to the current session.\n";
            }
            else
            {
                int pos = files.find(" ");
                while ( pos == 0 )
                {
                    files = files.substr(1);
                    pos = files.find(" ");
                }
                while (! files.empty() )
                {
                    std::string newFile;
                    newFile = files.substr(0, pos);
                    if(pos == -1 )
                    {
                        pos = files.size() - 1;
                    }
                    files.erase(0, pos + 1);
                    thisSession.add(newFile);
                    pos = files.find(" ");
                    std::cout << newFile << " has successfully been added to session #" << Session::id<< "\n";
                }
                editor.addSession(thisSession);
            }    
        }

        else if (command == "add")
        {
            std::string fileName;
            getline(std::cin, fileName);
            int pos = fileName.find(" ");
            while (pos == 0)
            {
                fileName = fileName.substr(1);
                pos = fileName.find(" ");
            }
            editor[ Editor::currentSession ].add(fileName);
            std::cout << fileName << " has successfully been added to session#" 
                                  << Editor::currentSession << "\n";

        }
        else if ( command == "sessionInfo")
        {
            editor[ Editor::currentSession ].sessionInfo();
        }
        else if ( command == "switch" )
        {
            int id;
            std::cin >> id;
            if (id < 0 || id >= editor.sessionsNumber())
            {
                std::cout << "A session with this id number does not exist!\n";
            }
            else 
            {
                Editor::currentSession = id;
                std::cout << "Successfully switched to session #" << id << "\n";
            }   
        }

        else if ( command == "undo" )
        {
            editor[ currentSession ].undo();
        }

        else if ( command == "grayscale" )
        {
            editor[currentSession].addTransformation("grayscale");
        }

        else if ( command == "monochrome" )
        {
            editor[ currentSession ].addTransformation( "monochrome" );
        }

        else if (command == "negative" )
        {
            editor[ currentSession ].addTransformation( "negative" );
        }
        else if ( command == "rotate" )
        {
            std::string direction;
            getline(std::cin, direction);
            int pos = direction.find(" ");
            while (pos == 0)
            {
                direction = direction.substr(1);
                pos = direction.find(" ");
            }
            if (direction == "left" )
            {
                editor[ currentSession ].addTransformation( "rotateLeft" );
            }
            else if (direction == "right" )
            {
                editor[ currentSession ].addTransformation( "rotateRight" );
            }
            else 
                std::cout << "Invalid direction!\n";
        }

        

        else if (command == "save")
        {
            editor[ currentSession ].makeTransformations();
            editor[ currentSession ].save();
        }
        else if ( command == "help" )
        {
            help();
        }
        else if (command == "exit")
        {
            std::cout << "Exiting the program...\n";
            continue;
        }
        else 
        {
            std::cout << "Invalid command!\n";
        }
        
    }
}

void CLR::help()
{
    std::cout << "The following commands are being supported:\n" <<
                 "load <files>              loads the stated files\n" <<
                 "close                     closes the currently opened file\n"<<
                 "save                      saves all images in the current session\n" <<
                 "saveas <file>             saves the first image of the current session in the stated file\n"
                 "exit                      exits the program\n" <<
                 "grayscale                 makes all images in the current session gray\n" <<
                 "monochrome                makes all images in the current session monochrome\n" <<
                 "negative                  makes all images in the current session negative\n" <<
                 "rotate <direction>        rotates all images in the current session left or right depending on the direction\n" <<
                 "undo                      clears the last transformation made\n" <<
                 "add <image>               adds the stated image to the current session\n"<<
                 "sessionInfo               prints information for the current session\n" <<
                 "switch <id>               switches to the session with the stated id if one exists\n" <<
                 "collage                   \n" <<
                 "  <direction>             creates a collage in of image1 and image2 in horizontal or vertical\n" <<
                 "  <image1>                direction. Note: both images need to be the same size!\n" <<
                 "  <image2>                \n" <<
                 "  <outimage>              \n";
}
