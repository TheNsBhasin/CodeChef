#include <iostream>
using namespace std;
int main()
{
    int t,n,sum,notes;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=notes=0;
        if(n)
        {
            notes=n/100;
            n-=(n/100)*100;
            notes+=n/50;
            n-=(n/50)*50;
            notes+=n/10;
            n-=(n/10)*10;
            notes+=n/5;
            n-=(n/5)*5;
            notes+=n/2;
            n-=(n/2)*2;
            notes+=n/1;
            n-=(n/1)*1;
        }
        cout<<notes<<endl;
    }
    return 0;
}
