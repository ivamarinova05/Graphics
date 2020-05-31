#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include <string>

#include "Image.h"


class Session
{
    private:
    
    std::vector<Image*> images;
    std::vector<std::string> transformations;

    public:

    static int id;
    
    Session();
    ~Session();
    void sessionInfo();
    void undo();
    void add(std::string);
    void addTransformation (std::string);
    void makeTransformations ();
    void save();

};


#endif
