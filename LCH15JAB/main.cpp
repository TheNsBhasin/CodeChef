#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int t,count;
    char str[55];
    bool flag;
    cin>>t;
    while(t--)
    {
        cin>>str;
        int n=(int)strlen(str);
        for(int i=0;str[i];i++)
        {
            count=0;
            flag=false;
            for(int j=0;str[j];j++)
                if(str[i]==str[j])
                    count++;
            if(count==n-count)
            {
                flag=true;
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
