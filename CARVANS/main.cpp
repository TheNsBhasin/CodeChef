#include <iostream>
using namespace std;
typedef long long int lli;
const int MAXN = 10004;
int main()
{
    int t,n;
    lli arr[MAXN];
    lli counter;
    cin>>t;
    while(t--)
    {
        counter=1;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]>=arr[i])
                counter++;
            else
                arr[i]=arr[i-1];
        }
        cout<<counter<<endl;
    }
    return 0;
}
