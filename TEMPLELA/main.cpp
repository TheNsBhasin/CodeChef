#include <iostream>
using namespace std;
int arr[102];
bool solve(int n)
{
    if(n%2==0 || arr[0]!=1 || arr[n-1]!=1)
        return false;
    for(int i=0;i<(n/2)-1;i++)
    {
        if((arr[i+1]-arr[i])!=1)
            return false;
    }
    for(int i=n/2;i<n-1;i++)
    {
        if((arr[i]-arr[i+1])!=1)
            return false;
    }
    return true;
}
int main()
{
    int S,N;
    cin>>S;
    while(S--)
    {
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>arr[i];
        if(solve(N))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
