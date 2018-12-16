#include <iostream>
using namespace std;
typedef long long int lli;
int main()
{
    int t;
    int N;
    char str[1003];
    cin>>t;
    while(t--)
    {
        cin>>N;
        cin>>str;
        for(int i=0;i<N;i++)
        {
            if(str[i]=='1')
            {
                if(i==0 && str[i+1]=='0')
                   str[0]=str[1]='*';
                else if(i==N-1 && str[i-1]=='0')
                    str[N-1]=str[N-2]='*';
                else
                {
                    str[i]='*';
                    if(str[i-1]=='0')
                        str[i-1]='*';
                    if(str[i+1]=='0')
                        str[i+1]='*';
                }
            }
        }
        int counter=0;
        for(int i=0;i<N;i++)
        {
            if(str[i]=='0')
                counter++;
        }
        cout<<counter<<endl;
    }
    return 0;
}
