#include <iostream>
using namespace std;
int main()
{
    int t,flag;
    string str1,str2;
    cin>>t;
    while(t--)
    {
        cin>>str1>>str2;
        flag=0;
        for(int i=0;str1[i];i++)
        {
            for(int j=0;j<str2[j];j++)
            {
                if(str1[i]==str2[j])
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
