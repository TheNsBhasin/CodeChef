#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
    int t,n,max_rem;
    cin>>t;
    while(t--)
    {
        cin>>n;
        max_rem=n%(n/2+1);
        cout<<n-max_rem<<endl;
    }
    return 0;
}
