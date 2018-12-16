#include <iostream>
using namespace std;
int main()
{
    int t;
    int length;
    string str;
    cin>>t;
    while(t--)
    {
        length=2;
        cin>>str;
        char prev=str[0];
        for(int i=1;str[i];i++)
        {
            if(str[i]==prev)
                length++;
            else if(str[i]>prev)
                length+=str[i]-prev+1;
            else
                length+=str[i]+(26-prev)+1;
            prev=str[i];
        }
        if(length <= 11*str.length())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
