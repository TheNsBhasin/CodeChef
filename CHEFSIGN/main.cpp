#include <iostream>
using namespace std;
int main()
{
    int t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        int maxi=1,curr=1;
        for(int i=0;str[i];i++)
        {
            if(str[i]=='<')
            {
                if(curr<1)
                {
                    maxi=max(maxi,2-curr);
                    curr=1;
                }
                curr++;
            }
            else if(str[i]=='>')
            {
                if(curr>1)
                    curr=0;
                else
                    curr--;
            }
            maxi=max(maxi,curr);
        }
        maxi=max(maxi,2-curr);
        cout<<maxi<<endl;
    }
    return 0;
}
