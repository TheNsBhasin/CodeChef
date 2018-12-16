#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t;
    int G,I,N,Q;
    cin>>t;
    while(t--)
    {
        cin>>G;
        for(int i=0;i<G;i++)
        {
            cin>>I>>N>>Q;
            if(!(N&1))
                cout<<(N>>1)<<endl;
            else
            {
                if(I==Q)
                    cout<<((N-1)>>1)<<endl;
                else
                    cout<<((N+1)>>1)<<endl;
            }
        }
    }
    return 0;
}
