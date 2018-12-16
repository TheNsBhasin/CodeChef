#include <iostream>
using namespace std;
typedef long long int lli;
lli gcd(lli a, lli b)
{
    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}
int main()
{
    int t;
    int N;
    lli A[1003];
    cin>>t;
    while(t--)
    {
        cin>>N;
        lli g=0;
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
            g=gcd(g,A[i]);
        }
        cout<<g<<endl;
    }
    return 0;
}
