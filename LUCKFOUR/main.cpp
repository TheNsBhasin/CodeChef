#include <iostream>
using namespace std;
typedef long long int ll;
int main()
{
    ll t,n,count;
    cin>>t;
    while(t--)
    {
        cin>>n;
        count=0;
        while(n)
        {
            if(n%10==4)
                count++;
            n/=10;
        }
        cout<<count<<endl;
    }
    return 0;
}
