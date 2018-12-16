#include <iostream>
using namespace std;
int main()
{
    int t;
    string str;
    string M;
    cin>>t>>M;
    while(t--)
    {
        cin>>str;
        for(int i=0;str[i];i++)
        {
            if(str[i]=='_')
                cout<<' ';
            else if(str[i]>='a' && str[i]<='z')
                cout<<(M[str[i]-'a']);
            else if(str[i]>='A' && str[i]<='Z')
                cout<<(char)(M[str[i]+32-'a']-32);
            else
                cout<<str[i];
        }
        cout<<endl;
    }
    return 0;
}
