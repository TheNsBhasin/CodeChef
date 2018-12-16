#include <iostream>
using namespace std;
bool prime[2004];
void sieve()
{
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i=4;i<2004;i+=2)
        prime[i]=false;
    for(int i=3;i*i<2004;i+=2)
    {
        if(prime[i]==true)
        {
            for(int j=i*i;j<2004;j+=i)
            {
                prime[j]=false;
            }
        }
    }
}
int main()
{
    sieve();
    int t;
    int x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        int num=0;
        for(int i=(x+y)+1;i<2004;i++)
        {
            if(prime[i])
            {
                num=i;
                break;
            }
        }
        cout<<num-(x+y)<<endl;
    }
    return 0;
}
