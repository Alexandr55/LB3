#ifndef CONVERT_H_INCLUDED
#define CONVERT_H_INCLUDED



#endif // CONVERT_H_INCLUDED
enum Scale
{
    Celsiy, Kelvin, Fahrenheit
};

Scale change_format_scale(char scale);

struct Temperature
{
    Temperature(double value, char scale);
    Temperature();
    double value;
    char scale;
};

Temperature convert(Temperature tepm, Scale to);
