#include <iostream>
using namespace std;
typedef long long int ll;
int GCD(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    if (a == b)
        return a;
    if (a > b)
        return GCD(a-b, b);
    return GCD(a, b-a);
}
int main()
{
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<GCD(a,b)<<" "<<a*b/GCD(a,b)<<endl;
    }
    return 0;
}
