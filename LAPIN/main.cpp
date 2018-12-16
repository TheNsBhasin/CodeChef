#include <iostream>
#include <math.h>
using namespace std;
typedef long long int lli;
const int MAXN = 1003;
int main()
{
    int t;
    char str[MAXN];
    int left[26],right[26];
    bool flag;
    cin>>t;
    while(t--)
    {
        flag=true;
        cin>>str;
        int n=(int)strlen(str);
        for(int i=0;i<26;i++)
            left[i]=right[i]=0;
        for(int i=0;i<n/2;i++)
            left[str[i]-'a']++;
        for(int i=ceil((double)n/2);i<n;i++)
            right[str[i]-'a']++;
        for(int i=0;i<26;i++)
        {
            if(left[i]!=right[i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
