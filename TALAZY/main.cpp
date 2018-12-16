#include <iostream>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    ll time,n,m,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>b>>m;
        time=0;
        while(n)
        {
            if(n%2==0)
            {
                time+=(n/2)*m;
                n=n/2;
            }
            else
            {
                time+=m*((n+1)/2);
                n=(n-1)/2;
            }
            if(n==0)
                break;
            time+=b;
            m=m*2;
        }
        cout<<time<<endl;
    }
    return 0;
}
