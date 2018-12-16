#include <iostream>
using namespace std;
int main()
{
    int t,n,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=n%10;
        while(n/10!=0)
            n/=10;
        sum+=n;
        cout<<sum<<endl;
    }
    return 0;
}
