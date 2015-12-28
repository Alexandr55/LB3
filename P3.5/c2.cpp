#include "sdt.h"
double convert(double, char, char);
int main()
{
    vector <double> cel;
    vector <double> kel;
    vector <double> far;
    double t,tc,tk,tf;
    char tem;
    int N,i;
    while(cin)
    {
        try{
        cout<<"Vvedite tempr: ";
        cin>>t;
        cin>>tem;
        cel.push_back(convert(t,tem,'C'));
        kel.push_back(convert(t,tem,'K'));
        far.push_back(convert(t,tem,'F'));
        }
        catch (const invalid_argument& e)
        {
            cerr <<e.what();
        }
        catch (const logic_error& er)
        {
            cerr <<er.what();
        }
        catch (...)
        {
            cerr <<"Neizvestnaya oshibka.\n";
        }


    }
    cout<<"CElCII  "<<"KELVIN  "<<"FARENGEIT "<<"\n";
    for (int i=0; i<cel.size(); i++)
    {
        cout<<cel[i]<<"\t";
        cout<<kel[i]<<"\t";
        cout<<far[i]<<"\n";
    }

}

double convert(double temp, char from, char to)
{
    double tempC;
    switch (from)
    {
        case 'C': tempC=temp;
             break;
        case 'K': tempC=temp-273.15;
             break;
        case 'F': tempC=5/9.0*(temp-32);
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
        case 'C': return tempC;
             break;
        case 'K': return tempC+273.15;
             break;
        case 'F': return 1.8*tempC+32;
             break;
        default: throw invalid_argument("Nevernaya shkala.\n");
        return 0;
    }
}






