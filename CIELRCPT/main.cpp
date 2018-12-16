#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
    int t,n,big,small,sum,count;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=count=0;
        big=small=1;
        while(sum!=n)
        {
            while(n-sum>=small && small<=2048)
                small=small<<1;
            small=small>>1;
            sum+=small;
            count++;
            small=1;
        }
        cout<<count<<endl;
    }
    return 0;
}
