#include "Functions.h"
#include "RGB.h"

bool Functions::oneDigit(int number)
{
    return (number/10 == 0);
}

bool Functions::twoDigit(int number)
{
    return ((number/10)/10 == 0);
}
