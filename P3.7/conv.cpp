#include "sdt.h"
#include "conv.h"

Scale change_format_scale(char scale)
{
    switch (scale)
    {
    case 'C':
        return Celsiy;
        break;
    case 'F':
        return Fahrenheit;
        break;
    case 'K':
        return Kelvin;
        break;
    default:
        throw invalid_argument("Nevernaya shkala.\n");
    }
}
Temperature convert(Temperature temp, Scale to)
{
    Temperature result;
    double tempC;
    char from;
    switch (from)
    {
    case Celsiy:
        tempC=temp.value;
        break;
    case Kelvin:
        tempC=temp.value-273.15;
        break;
    case Fahrenheit:
        tempC=5/9.0*(temp.value-32);
        break;
    default:
        throw invalid_argument("Nevernaya shkala.\n");
        //return 0;
    }
    if (tempC<-273.15)
    {
        throw logic_error("Vvedeno ne vernoe znachenie.\n");
        // return 0;
    }
    switch (to)
    {
    case Celsiy:
        result.value=tempC;
        result.scale='C';
        break;
    case Kelvin:
        result.value=tempC-273.15;
        result.scale='K';
        break;
    case Fahrenheit:
        result.value=5/9.0*(tempC-32);
        result.scale='F';
        break;
    default:
        throw invalid_argument("Nevernaya shkala.\n");
    }
    return result;
}
