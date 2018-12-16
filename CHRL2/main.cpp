#include <iostream>
#include <string.h>
using namespace std;
const int MAXN=100005;
int main()
{
    int ans,H,E,F,n;
    char str[MAXN];
    cin>>str;
    n=(int)strlen(str);
    ans=H=E=F=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='C')
        {
            H=max(H,i+1);
            while(H<n && str[H]!='H')
                H++;
            if(H==n)
                break;
            E=max(E,H+1);
            while(E<n && str[E]!='E')
                E++;
            if(E==n)
                break;
            F=max(F,E+1);
            while(F<n && str[F]!='F')
                F++;
            if(F==n)
                break;
            H++;
            E++;
            F++;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
