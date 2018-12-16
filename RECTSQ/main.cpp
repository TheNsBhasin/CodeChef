#include <iostream>
using namespace std;
int GCD(int a,int b)
{
    if(a==0 || b==0)
        return 0;
    if(a==b)
        return a;
    if(a>b)
        return GCD(a-b,b);
    return GCD(a,b-a);
}
int main()
{
    int t,m,n;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        cout<<(m*n)/(GCD(m,n)*GCD(m,n))<<endl;
    }
    return 0;
}
