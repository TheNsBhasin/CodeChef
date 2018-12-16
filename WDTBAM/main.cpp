#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long int ll;
int main()
{
    int t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        string str1,str2;
        cin>>str1>>str2;
        vector<int> W(n+1);
        for (int i=0; i<=n;i++)
            cin>>W[i];
        int k=0;
        for (int i=0;i<n;i++)
            if (str1[i]==str2[i])
                ++k;
        if (k==n)
            cout<<W[n]<<endl;
        else
        {
            int ans = 0;
            for (int i=0;i<=k;i++)
                ans=max(ans,W[i]);
            cout<<ans<<endl;
        }
    }
    return 0;
}
