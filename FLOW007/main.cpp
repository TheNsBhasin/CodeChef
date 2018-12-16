#include <iostream>
using namespace std;
int main()
{
    int t,n,rev;
    cin>>t;
    while(t--)
    {
        cin>>n;
        rev=0;
        while(n)
        {
            rev*=10;
            rev+=(n%10);
            n/=10;
        }
        cout<<rev<<endl;
    }
    return 0;
}
