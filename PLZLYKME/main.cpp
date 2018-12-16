#include <iostream>
using namespace std;
typedef unsigned long long int lli;
int main()
{
    lli l,d,s,c,t,sum,i;
    cin>>t;
    while(t--)
    {
        cin>>l>>d>>s>>c;
        sum=s;
        for(i=0;i<d-1;i++)
        {
            if(sum>l)
                break;
            sum=sum+sum*c;
        }
        
        if(sum<l)
            cout<<"DEAD AND ROTTING"<<endl;
        else
            cout<<"ALIVE AND KICKING"<<endl;
    }
    return 0;
}
