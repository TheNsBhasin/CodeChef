#include <iostream>
#include <climits>
using namespace std;
typedef long long int lli;
const int MAXN=100005;
int main()
{
    int t;
    lli N,maxi;
    lli W[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>N;
        maxi=INT_MIN;
        for(int i=0;i<N;i++)
        {
            cin>>W[i];
            maxi=max(maxi,(W[i]+i));
        }
        cout<<maxi<<endl;
    }
    return 0;
}
