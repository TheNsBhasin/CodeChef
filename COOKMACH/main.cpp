#include <iostream>
using namespace std;
typedef long long int ll;
int main()
{
    int t,a,b;
    ll steps;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        steps=0;
        while(a!=b)
        {
            if(a>b)
                a/=2;
            else
                b/=2;
            ++steps;
        }
        cout<<steps<<endl;
    }
    return 0;
}
