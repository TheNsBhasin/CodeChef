#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
    int t,n,prerequisite;
    cin>>t;
    while(t--)
    {
        int maxi=INT_MIN;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>prerequisite;
            if(prerequisite>maxi)
                maxi=prerequisite;
        }
        cout<<n-maxi<<endl;
    }
    return 0;
}
