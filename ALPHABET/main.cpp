#include <iostream>
using namespace std;
const int MAXN=1003;
int main()
{
    int n;
    char str[MAXN],word[MAXN];
    bool flag=false;
    cin>>str;
    cin>>n;
    while(n--)
    {
        cin>>word;
        for(int i=0;word[i];i++)
        {
            flag=false;
            for(int j=0;str[j];j++)
            {
                if(word[i]==str[j])
                {
                    flag=true;
                    break;
                }
            }
            if(flag==false)
                break;
        }
        if(flag==true)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
