#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int t,n,m,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        while(k--)
        {
            if(n==m)
                break;
            else if(n>m)
                n--;
            else
                m--;
        }
        cout<<abs(n-m)<<endl;
    }
    return 0;
}
