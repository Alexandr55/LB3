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
    cout<<"Rezultat:"<<"\n";
     ofstream out("Rezultat.txt", ios_base::trunc);
    for (int i=0; i<(cel.size())-1; i++)
    {
        cout<<cel[i].value<<cel[i].scale<<"\t";
        cout<<kel[i].value<<kel[i].scale<<"\t";
        cout<<far[i].value<<far[i].scale<<"\n";
        out<<cel[i].value<<cel[i].scale<<"\t";
        out<<kel[i].value<<kel[i].scale<<"\t";
        out<<far[i].value<<far[i].scale<<"\n";

    }

    out <<"Max =" <<MaxTemp(kel)<<'\n';
    out <<"Min =" <<MinTemp(kel)<<'\n';
    out <<"Srednyaya =" <<SRTemp(kel)<<'\n';
    out.close();
    cout <<'\n';
    cout <<"Max =" <<MaxTemp(kel)<<'\n';
    cout <<"Min =" <<MinTemp(kel)<<'\n';
    cout <<"Srednyaya =" <<SRTemp(kel)<<'\n';

}








