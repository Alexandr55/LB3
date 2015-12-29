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
istream& operator>>(istream& input, Temperature& temp)
{
    input>>temp.value >>temp.scale;
    return input;
}
ostream& operator<<(ostream& output, const Temperature& temp)
{
    output<<temp.value <<temp.scale;
    return output;
}
istream& operator>>(istream& input, Scale& scale)
{
    char s;
    input>>s;
    switch(s)
    {
    case 'C':
        scale=Celsiy;
        break;
    case 'K':
        scale=Kelvin;
        break;
    case 'F':
        scale=Fahrenheit;
        break;
    default:
        input.setstate(ios_base::failbit); //ошибка
    }
    return input;
}
ostream& operator<<(ostream& output, const Scale& scale)
{
    switch(scale)
    {
    case Celsiy:
        output<<'C';
        break;
    case Kelvin:
        output<<'K';
        break;
    case Fahrenheit:
        output<<'F';
        break;
    }
    return output;
}
bool operator>(const Temperature& left, const Temperature& right)
{
if (left.scale==right.scale)
    return left.value>right.value;
 else
            switch (left.scale)
        {
        case 'C':
          return left.value>convert(right ,Celsiy).value;
            case 'K':
          return left.value>convert(right ,Kelvin).value;
             case 'F':
           return left.value>convert(right ,Fahrenheit).value;
        }
}

Temperature operator+(const Temperature& left, const Temperature& right)
{
      if (left.scale==right.scale)
    return  {left.value+right.value,
             left.scale
            };
            else
            switch (left.scale)
        {
        case 'C':
          return  {left.value+convert(right ,Celsiy).value,
             left.scale
            };
            case 'K':
          return  {left.value+convert(right ,Kelvin).value,
             left.scale
            };
             case 'F':
          return  {left.value+convert(right ,Fahrenheit).value,
             left.scale
            };

        }

}

Temperature operator+=(Temperature& left, const Temperature& right)
{
    if (left.scale==right.scale)
    left.value+=right.value;
    return left;
}

Temperature operator/(Temperature& left, const int division)
{
    return  {left.value/division,
             left.scale
            };
}


Temperature operator/=(Temperature& left, const int division)
{
    left.value/=division;
    return left;
}
Temperature MaxTemp(vector<Temperature> temp)
{
    Temperature MaxT= {0, Kelvin};
    for (int i=0; i < temp.size(); i++)
    {
        if (temp[i].value > MaxT.value)
            MaxT=temp[i];
    }
    return MaxT;
}

Temperature MinTemp(vector<Temperature> temp)
{
    Temperature MinT= {10000000000, Kelvin};
    for (int i=0; i < temp.size(); i++)
    {
        if (temp[i].value < MinT.value)
            MinT=temp[i];
    }
    return MinT;
}

Temperature SRTemp(vector<Temperature> temp)
{
    Temperature SRT= {0, Kelvin};
    for (int i=0; i < temp.size(); i++)
    {
        SRT+=temp[i];
    }
    SRT/=temp.size();
    return SRT;
}
