#include <iostream>
using namespace std;
const int MAXN=102;
int main()
{
    int t,a,b;
    char str[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>str;
        a=b=0;
        for(int i=0;str[i];i++)
            if(str[i]=='a')
                a++;
            else
                b++;
        if(a>b)
            cout<<b<<endl;
        else
            cout<<a<<endl;
    }
    return 0;
}
