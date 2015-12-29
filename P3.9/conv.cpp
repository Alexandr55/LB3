#include "sdt.h"
#include "conv.h"

Temperature convert(Temperature temp, Scale to)
{
    double tempC;
    Temperature result;
    switch (temp.scale)
    {
    case 'C':
        tempC=temp.value;
        break;
    case 'K':
        tempC=temp.value-273.15;
        break;
    case 'F':
        tempC=5/9.0*(temp.value-32);
        break;
    default:
        throw invalid_argument("Nevernaya shkala.\n");

    }
    if (tempC<-273.15)
    {
        throw logic_error("Vvedeno ne vernoe znachenie.\n");

    }
    switch (to)
    {
    case Celsiy:
        result.value=tempC;
        result.scale='C';
        break;
    case Kelvin:
        result.value=tempC+273.15;
        result.scale='K';
        break;
    case Fahrenheit:
        result.value=1.8*tempC+32;
        result.scale='F';
        break;
    default:
        throw invalid_argument("Nevernaya shkala.\n");
        return result;
    }
}
