#include "sdt.h"
#include "conv.h"
Temperature::Temperature(double value, char scale)
{
    this->value=value;
    this->scale=scale;
}
Temperature::Temperature()
{
    this->value=-38.83;
    this->scale='C';
}
