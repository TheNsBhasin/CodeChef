#include <iostream>
using namespace std;
const int MAXN=100005;
int main()
{
    int t;
    char str[MAXN];
    int count;
    cin>>t;
    while (t--)
    {
        count=0;
        cin>>str;
        for(int i=1;str[i];i++)
            if(str[i-1]=='<' && str[i]=='>')
                count++;
        cout<<count<<endl;
    }
    return 0;
}
