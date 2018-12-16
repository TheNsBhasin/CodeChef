#include <iostream>
using namespace std;
const int MAXN=100005;
int main()
{
    int t;
    char str[MAXN];
    cin>>t;
    while(t--)
    {
        cin>>str;
        bool flag=false;
        int N=(int)strlen(str);
        for(int i=0;i<N-2;i++)
        {
            if((str[i]=='0' && str[i+1]=='1' && str[i+2]=='0') || (str[i]=='1' && str[i+1]=='0' && str[i+2]=='1'))
            {
                flag=true;
                break;
            }
        }
        if(flag)
            cout<<"Good"<<endl;
        else
            cout<<"Bad"<<endl;
    }
    return 0;
}
