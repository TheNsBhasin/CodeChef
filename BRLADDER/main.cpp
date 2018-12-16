#include <iostream>
using namespace std;
typedef long long int lli;
int main()
{
    lli Q;
    lli a,b;
    cin>>Q;
    while(Q--)
    {
        cin>>a>>b;
        if(a%2==0 && b%2==0)
        {
            if(min(a,b)+2==max(a,b))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if(a%2!=0 && b%2!=0)
        {
            if(min(a,b)+2==max(a,b))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
        {
            lli even=(a%2?b:a);
            lli odd=(a%2?a:b);
            if(even-odd==1)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
