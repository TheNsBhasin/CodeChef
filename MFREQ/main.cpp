#include <iostream>
using namespace std;
int mostFreq(int arr[],int l,int r,int k)
{
    int count=0,index=l-1;
    for(int i=l-1;i<r;)
    {
        while(arr[i]==arr[index] && i<r)
        {
            count++;
            i++;
            if(count>=k)
                return arr[index];
        }
        if(r-i-1<k)
            break;
        index=i;
        count=0;
    }
    return -1;
}
int main()
{
    int n,m,l,r,k;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    while(m--)
    {
        cin>>l>>r>>k;
        cout<<mostFreq(arr,l,r,k)<<endl;
    }
    return 0;
}
