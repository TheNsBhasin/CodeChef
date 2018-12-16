#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=100005;
int main()
{
    int t,n,R,B,G;
    char str[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>str;
        R=B=G=0;
        for(int i=0;str[i];i++)
            if(str[i]=='R')
                R++;
            else if(str[i]=='B')
                B++;
            else
                G++;
        cout<<n-max(max(R,B),G)<<endl;
    }
    return 0;
}
