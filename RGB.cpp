#include "RGB.h"
#include <iostream>
#include "Functions.h"


void RGB::copy(int _R, int _G, int _B)
{
    R = _R;
    G = _G;
    B = _B;
}

RGB::RGB(): R(0), G(0), B(0){}

RGB::RGB(int _R, int _G, int _B)
{
    copy(_R, _G, _B);
}

RGB::RGB(const RGB& other)
{
    copy(other.R, other.G, other.B);
}

RGB::~RGB() = default;

RGB& RGB::operator=(const RGB& other)
{
    copy(other.R, other.G, other.B);
    return *this;
}

void RGB::input(std::istream& in)
{
    in >> R >> G >> B;

}

std::ostream& RGB::print(std::ostream& out)
{
    if (Functions::oneDigit(R)) 
        out << "  " << R << " ";
    else if (Functions::twoDigit(R))
        out << " " << R << " ";
    else
        out << R << " ";

    if (Functions::oneDigit(G))
        out << "  " << G << " ";
    else if (Functions::twoDigit(G))
        out << " " << G << " ";
    else 
        out << G << " ";

    if (Functions::oneDigit(B))
        out << "  " << B << " ";
    else if (Functions::twoDigit(B))
        out << " " << B << " ";
    else 
        out << B << " ";
    
    return out;
}

void RGB::setR (int _R)
{
    R = _R;
}

void RGB::setG ( int _G)
{
    G = _G;
}

void RGB::setB ( int _B)
{
    B = _B;
}

RGB& RGB::negative(int maxValue)
{
    R = maxValue - R;
    G = maxValue - G;
    B = maxValue - B;
    return *this;
}

RGB& RGB::setGray()
{
    R = 0*3*R;
    G = 0.59*G;
    B = 0.11*B;
    return *this;
}
