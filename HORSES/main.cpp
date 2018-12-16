#include <iostream>
#include <climits>
using namespace std;
typedef long long int lli;
int main()
{
    int t;
    int N;
    lli S[5003];
    cin>>t;
    while(t--)
    {
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>S[i];
        lli mini=LONG_MAX;
        for(int i=0;i<N-1;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                mini=min(mini,abs(S[j]-S[i]));
            }
        }
        cout<<mini<<endl;
    }
    return 0;
}
