#include <iostream>
using namespace std;
typedef long long int lli;
const int MAXN=2003;
int main()
{
    int n;
    lli arr[MAXN];
    lli counter;
    while(1)
    {
        counter=0;
        cin>>n;
        if(n==0)
            break;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        for(int i=n-1;i>1;i--)
        {
            int low=0;
            int high=i-1;
            while(high>low)
            {
                if(arr[low]+arr[high]<arr[i])
                {
                    counter+=(high-low);
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        cout<<counter<<endl;
    }
    return 0;
}
