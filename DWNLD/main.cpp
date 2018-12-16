#include <iostream>
using namespace std;
const int MAXN=11;
int main()
{
    int t,n,k;
    int T[MAXN],D[MAXN];
    int pay;
    string str;
    cin>>t;
    while(t--)
    {
        pay=0;
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>T[i]>>D[i];
        for(int i=0;i<n;i++)
        {
            if(T[i]<=k)
                k=k-T[i];
            else
            {
                pay+=D[i]*(T[i]-k);
                k=0;
            }
        }
        cout<<pay<<endl;
    }
    return 0;
}
