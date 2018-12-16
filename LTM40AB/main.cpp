#include <iostream>
using namespace std;
typedef long long int lli;
int main()
{
    int t;
    lli a,b,c,d,total;
    cin>>t;
    while(t--)
    {
        total=0;
        cin>>a>>b>>c>>d;
        for(lli i=a;i<=b;i++)
            total+=((d>=max(c,i+1))?d-max(c,i+1)+1:0);
        cout<<total<<endl;
    }
    return 0;
}
