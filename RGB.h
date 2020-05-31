#ifndef RGB_H
#define RGB_H
#include <iostream>
#include <fstream>

class RGB
{
    private:
    int R;
    int G;
    int B;
    void copy(int, int, int);

    public:
    RGB();
    RGB(int, int, int);
    RGB(const RGB&);
    RGB& operator= (const RGB&);
    ~RGB();

    void setR (int);
    void setG (int);
    void setB (int);

    int getR () const {return R;}
    int getG () const {return G;}
    int getB () const {return B;}

    RGB& negative(int);
    RGB& setGray();
    void input (std::istream&);
    std::ostream& print (std::ostream&);


};

#endif
