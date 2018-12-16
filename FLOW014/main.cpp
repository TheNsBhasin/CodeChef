#include <iostream>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    float hardness,carbon,tensile;
    bool c1,c2,c3;
    cin>>t;
    while(t--)
    {
        cin>>hardness>>carbon>>tensile;
        c1=c2=c3=false;
        if(hardness>50)
            c1=true;
        if(carbon<0.7)
            c2=true;
        if(tensile>5600)
            c3=true;
        if(c1 && c2 && c3)
            cout<<"10"<<endl;
        else if(c1 && c2 && !c3)
            cout<<"9"<<endl;
        else if(!c1 && c2 && c3)
            cout<<"8"<<endl;
        else if(c1 && !c2 && c3)
            cout<<"7"<<endl;
        else if((c1 && !c2 && !c3)||(!c1 && c2 && !c3)||(!c1 && !c2 && c3))
            cout<<"6"<<endl;
        else
            cout<<"5"<<endl;
    }
    return 0;
}
