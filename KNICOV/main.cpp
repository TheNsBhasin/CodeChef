#include <iostream>
using namespace std;
int main()
{
    int t;
    int n,m;
    int count;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin>>n>>m;
        if(n==1 || m==1)
            count=max(m,n);
        else
        {
            while(m >= 6)
            {
                count+=4;
                m-=6;
            }
            if(m==1)
                count+=2;
            if(m>1)
                count+=4;
            if(m==2 && n==3 && count>8)
                count--;
        }
        cout<<count<<endl;
    }
    return 0;
}
