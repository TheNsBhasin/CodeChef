#include <iostream>
using namespace std;
typedef unsigned long long int lli;
int main()
{
    int t;
    lli N,K;
    cin>>t;
    while(t--)
    {
        cin>>N>>K;
        if(K==0)
        {
            cout<<0<<" "<<N<<endl;
            continue;
        }
        cout<<(N/K)<<" "<<(N%K)<<endl;
    }
    return 0;
}
