#include "sdt.h"
#include "conv.h"


int main()
{
    vector <double> cel;
    vector <double> kel;
    vector <double> far;
    double t,tc,tk,tf;
    char scale;
    int N,i;
    while(cin)
    {
        try{
        cout<<"Vvedite tempr: ";
        cin>>t;
        cin>>scale;
        Scale s=change_format_scale(scale);
        cel.push_back(convert(t,s,Celsiy));
        kel.push_back(convert(t,s,Kelvin));
        far.push_back(convert(t,s,Fahrenheit));
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
        cout<<cel[i]<<"      ";
        cout<<kel[i]<<"     ";
        cout<<far[i]<<" "<<"\n";
    }

}








