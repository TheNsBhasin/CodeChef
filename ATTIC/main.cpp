#include <iostream>
using namespace std;
int main()
{
    int t,n;
    string str;
    int counter,curr,ans;
    cin>>t;
    while(t--)
    {
        cin>>str;
        ans=0;
        curr=1;
        n=(int)str.length();
        for(int i=0;i<n;)
        {
            counter=0;
            if(str[i]=='.')
            {
                while(str[i++]=='.')
                    ++counter;
                ++counter;
                if(counter>curr)
                {
                    ans+=1;
                    curr=counter;
                }
            }
            else
                i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
