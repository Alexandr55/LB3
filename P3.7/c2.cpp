#include "sdt.h"
#include "conv.h"


int main()
{
    Temperature temp;
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
            //cin>>t;
            //cin>>scale;
            cin>>temp.value>>temp.scale;
            //Scale s=change_format_scale(scale);
            //Temperature convert(Temperature tepm, Scale to);
            //Temperature t1(t,scale);

            cel.push_back(convert(temp,Celsiy));
            kel.push_back(convert(temp,Kelvin));
            far.push_back(convert(temp,Fahrenheit));
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
        cout<<cel[i].value << "\t" << cel[i].scale << "\n";
        cout<<kel[i].value << "\t" << kel[i].scale << "\n";
        cout<<far[i].value << "\t" << far[i].scale << "\n";
    }
}








