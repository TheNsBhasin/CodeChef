#include <iostream>
using namespace std;
int mod(string b,int a)
{
    int rem=0;
    for(int i=0;b[i];i++)
        rem=(rem*10+b[i]-'0')%a;
    return rem;
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int gcd2(int a,string b)
{
    if(b=="0")
        return a;
    else
        return gcd(a,mod(b,a));
}
int main()
{
    int t;
    int A;
    string B;
    cin>>t;
    while(t--)
    {
        cin>>A>>B;
        if(A==0)
        {
            cout<<B<<endl;
            continue;
        }
        cout<<gcd2(A,B)<<endl;
    }
    return 0;
}
