#include <iostream>
#include <string.h>
using namespace std;
typedef long long int lli;
lli counter[10],A[10];
bool check(lli n)
{
    while(n!=0)
    {
        counter[n%10]++;
        n=n/10;
    }
    for(int i=0;i<10;i++)
        if(counter[i]==A[i])
            return false;
    return true;
}
int main()
{
    int t;
    lli L,R,c;
    cin>>t;
    while(t--)
    {
        c=0;
        cin>>L>>R;
        for(int i=0;i<10;i++)
            cin>>A[i];
        for(lli i=L;i<=R;i++)
        {
            for(lli i=0;i<10;i++)
                counter[i]=0;
            if(check(i))
                ++c;
        }
        cout<<c<<endl;
    }
    return 0;
}
