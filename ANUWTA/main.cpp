#include <iostream>
using namespace std;
typedef unsigned long long int lli;
int main()
{
    int t;
    lli N;
    cin>>t;
    while(t--)
    {
        cin>>N;
        cout<<(N*(N+3))/2<<endl;
    }
    return 0;
}
