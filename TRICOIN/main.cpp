#include <iostream>
using namespace std;
typedef long long int ll;
int main()
{
    ll t,n,h;
    cin>>t;
    while(t--)
    {
        cin>>n;
        h=1;
        while(h*(h+1)/2 <= n)
            h++;
        cout<<h-1<<endl;
    }
    return 0;
}
