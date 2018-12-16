#include <iostream>
#include <math.h>
#include <climits>
using namespace std;
typedef long long int lli;
int main()
{
    int t;
    int N;
    int x,y,ans;
    cin>>t;
    while(t--)
    {
        cin>>N;
        ans=INT_MAX;
        for(x=sqrt(N);x>=1;x--)
        {
            if(N%x==0)
            {
                y=N/x;
                ans=y-x;
                break;
            }
        }
        cout<<abs(ans)<<endl;
    }
    return 0;
}
