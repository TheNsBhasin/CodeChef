#include <iostream>
using namespace std;
typedef long long int ll;
ll factorial(ll n)
{
    if(n==0 || n==1)
        return 1;
    return n*factorial(n-1);
}
int main()
{
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<factorial(n)<<endl;
    }
    return 0;
}
