#include "sdt.h"
#include "conv.h"


int main()
{
    Temperature vvod;
    vector <Temperature> cel;
    vector <Temperature> kel;
    vector <Temperature> far;
    double t,tc,tk,tf;
    char scale;
    while(cin)
    {
        try
        {
            cout<<"Vvedite tempr: ";
            cin>>vvod.value>>vvod.scale;
            cel.push_back(convert(vvod ,Celsiy));
            kel.push_back(convert(vvod ,Kelvin));
            far.push_back(convert(vvod ,Fahrenheit));
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
    for (int i=0; i<(cel.size())-1; i++)
    {
        cout<<cel[i].value<<"\t";
        cout<<kel[i].value<<"\t";
        cout<<far[i].value<<"\n";
    }

}








