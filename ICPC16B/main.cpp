#include <iostream>
using namespace std;
const int MAXN = 100005;
typedef long long int lli;
int main()
{
    int t,n;
    int arr[MAXN];
    int zero,one,minusOne,other;
    cin>>t;
    while(t--)
    {
        cin>>n;
        zero=one=minusOne=other=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]==0)
                zero++;
            else if(arr[i]==1)
                one++;
            else if(arr[i]==-1)
                minusOne++;
            else
                other++;
        }
        if((other>1) || (minusOne && other) || (minusOne>1 && !one))
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
    return 0;
}
