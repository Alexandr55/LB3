#ifndef CONVERT_H_INCLUDED
#define CONVERT_H_INCLUDED



#endif // CONVERT_H_INCLUDED
enum Scale
{
    Celsiy, Kelvin, Fahrenheit
};

struct Temperature
{
    Temperature(double value, char scale);
    Temperature();
    double value;
    char scale;
};

Temperature convert(Temperature tepm, Scale to);
istream& operator>>(istream& input, Temperature& temp);
ostream& operator<<(ostream& output, const Temperature& temp);
istream& operator>>(istream& input, Scale& scale);
ostream& operator<<(ostream& output, const Scale& scale);
bool operator>(const Temperature left, const Temperature right);
Temperature operator+(const Temperature& left, const Temperature& right);
Temperature operator+=(Temperature& left, const Temperature& right);
Temperature operator/(Temperature& left, const int division);
Temperature operator/=(Temperature& left, const int division);
Temperature MaxTemp(vector<Temperature> temp);
Temperature SRTemp(vector<Temperature> temp);
Temperature MinTemp(vector<Temperature> temp);
