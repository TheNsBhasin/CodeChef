#include <iostream>
using namespace std;
int main()
{
    int t,max,min;
    char str1[102],str2[102];
    cin>>t;
    while(t--)
    {
        cin>>str1>>str2;
        max=min=0;
        for(int i=0;str1[i] && str2[i];i++)
        {
            if(str1[i]=='?' || str2[i]=='?')
                max++;
            else if(str1[i]!=str2[i])
            {
                max++;
                min++;
            }
        }
        cout<<min<<" "<<max<<endl;
    }
    return 0;
}
