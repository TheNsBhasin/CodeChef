#include <iostream>
using namespace std;
int sum(int n)
{
    if(n==1)
        return 1;
    return n+sum(n-1);
}
int main()
{
    int t,d,n;
    cin>>t;
    while(t--)
    {
        cin>>d>>n;
        while(d--)
            n=sum(n);
        cout<<n<<endl;
    }
    return 0;
}
