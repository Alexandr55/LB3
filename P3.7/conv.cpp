#include "sdt.h"
#include "conv.h"

Scale change_format_scale(char scale)
{   switch (scale)
      {
       case 'C': return Celsiy;
                 break;
       case 'F': return Fahrenheit;
                 break;
       case 'K': return Kelvin;
                 break;
       default: throw invalid_argument("Nevernaya shkala.\n");
       }
}
Temperature convert(Temperature tepm, Scale to)
{
    double tempC;
    switch (from)
    {
        case Celsiy: tempC=temp;
             break;
        case Kelvin: tempC=temp-273.15;
             break;
        case Fahrenheit: tempC=5/9.0*(temp-32);
             break;
        default: throw invalid_argument("Nevernaya shkala.\n");
             return 0;
    }
    if (tempC<-273.15)
    {
       throw logic_error("Vvedeno ne vernoe znachenie.\n");
        return 0;
    }
    switch (to)
    {
        case Celsiy: return tempC;
             break;
        case Kelvin: return tempC+273.15;
             break;
        case Fahrenheit: return 1.8*tempC+32;
             break;
        default: throw invalid_argument("Nevernaya shkala.\n");
        return 0;
    }
}