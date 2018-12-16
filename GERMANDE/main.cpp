#include <iostream>
#include <stdlib.h>
using namespace std;
int printPresident(int arr[],int n,int k)
{
    int d=n*k;
    int counter=0;
    int cases[k];
    for(int i=0;i<k;i++)
    {
        cases[i]=0;
        if(arr[i]==1)
            counter++;
    }
    if(counter>k/2)
        cases[0]++;
    for(int i=k;i<d+k;i++)
    {
        if(arr[i%d]==1 && arr[i-k]==0)
            counter++;
        else if(arr[i%d]==0 && arr[i-k]==1)
            counter--;
        if(counter>k/2)
            cases[i%k]++;
        if(cases[i%k]>n/2)
            return 1;
    }
    return 0;
}
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int arr[n*k];
        for(int i=0;i<n*k;i++)
            cin>>arr[i];
        cout<<printPresident(arr,n,k)<<endl;
    }
    return 0;
}
