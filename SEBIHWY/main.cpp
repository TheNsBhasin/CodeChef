#include <iostream>
#include <set>
using namespace std;
typedef long long int lli;
double abs(double x)
{
    if(x<0)
        x=x*-1;
    return x;
}
int main()
{
    int t;
    double s,sg,fg,d,time;
    double speed;
    cin>>t;
    while(t--)
    {
        cin>>s>>sg>>fg>>d>>time;
        speed=s+(d*180)/time;
        if(abs(speed-sg)>abs(speed-fg))
            cout<<"FATHER"<<endl;
        else if(abs(speed-sg)<abs(speed-fg))
            cout<<"SEBI"<<endl;
        else
            cout<<"DRAW"<<endl;
    }
    return 0;
}
