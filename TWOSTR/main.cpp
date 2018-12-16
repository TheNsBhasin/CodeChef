#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int t,flag;
    char str1[15],str2[15];
    cin>>t;
    while(t--)
    {
        cin>>str1>>str2;
        flag=1;
        for(int i=0;str1[i] && str2[i];i++)
        {
            if(str1[i]=='?')
                str1[i]=str2[i];
            else if(str2[i]=='?')
                str2[i]=str1[i];
            else if(str1[i]!=str2[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
