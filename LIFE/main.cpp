#include <iostream>
#include <cstring>
const int MAXN=100;
using namespace std;
bool isSafe(int n,bool orig[],bool curr[])
{
    for (int i = 2; i < n; ++i)
        orig[i] = orig[i-2]^orig[i-1]^curr[i-1];
    if (orig[n-2]^orig[n-1]^orig[0]^curr[n-1])
        return false;
    if (orig[n-1]^orig[0]^orig[1]^curr[0])
        return false;
    return true;
}
int main()
{
    int t;
    char str[MAXN+1];
    bool orig[MAXN+1],curr[MAXN+1],a,b;
    cin>>t;
    while(t--)
    {
        int count=0;
        cin>>str;
        int n=(int)strlen(str);
        for(int i=0;i<n;i++)
            curr[i]=(str[i]=='1');
        for(int i=0;i<4;i++)
        {
            orig[0]=i>>1;
            orig[1]=i&1;
            if(isSafe(n,orig,curr))
            {
                a=orig[0];
                b=orig[1];
                count++;
            }
        }
        if(count==0)
            cout<<"No solution"<<endl;
        else if(count>1)
            cout<<"Multiple solutions"<<endl;
        else
        {
            orig[0]=a;
            orig[1]=b;
            isSafe(n,orig,curr);
            for(int i=0;i<n;i++)
                cout<<(orig[i]?1:0);
            cout<<endl;
        }
    }
    return 0;
}
