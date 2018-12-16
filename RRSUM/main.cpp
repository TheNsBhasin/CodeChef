#include <iostream>
#include <climits>
using namespace std;
typedef unsigned long long int lli;
int main()
{
    lli N,M;
    lli q;
    cin>>N>>M;
    while(M--)
    {
        cin>>q;
        if(q<=N)
            cout<<0<<endl;
        if(q>N && q<=2*N)
            cout<<q-(N+1)<<endl;
        if(q>2*N)
            cout<<3*N-(q-1)<<endl;
    }
    return 0;
}
