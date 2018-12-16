#include <iostream>
using namespace std;
typedef long long int lli;
int main()
{
    int t;
    lli N,A,B;
    lli ans;
    int bit1,bit2,bits;
    cin>>t;
    while(t--)
    {
        bits=bit1=bit2=ans=0;
        cin>>N>>A>>B;
        for(int i=0;i<N;i++)
        {
            if(A&(1<<i))
                bit1++;
        }
        for(int i=0;i<N;i++)
        {
            if(B&(1<<i))
                bit2++;
        }
        bits=bit1+bit2;
        if(bits<=N)
            ans=((1<<bits)-1)*(1<<(N-bits));
        else
            ans=((1<<(N+N-bits))-1)*(1<<(bits-N));
        cout<<ans<<endl;
    }
    return 0;
}
