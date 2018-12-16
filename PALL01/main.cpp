#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t,n,rev,temp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        temp=n;
        rev=0;
        while(temp)
        {
            rev*=10;
            rev+=temp%10;
            temp/=10;
        }
        if(rev==n)
            cout<<"wins"<<endl;
        else
            cout<<"losses"<<endl;
    }
    return 0;
}
