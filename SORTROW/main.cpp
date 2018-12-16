#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int ascending(int i, int j)
{
    return (i<j);
}
int descending(int i, int j)
{
    return (i>j);
}
int main()
{
    int n;
    cin>>n;
    int arr[n][n],moves[n],front,rear;
    for(int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>arr[i][j];
    for(int i=0;i<n;i++)
    {
        front=rear=0;
        for(int j=0;j<n-1;j++)
        {
            if(arr[i][j]<=arr[i][j+1])
                front++;
            else
                rear++;
        }
        if(front>=rear)
            moves[i]=0;
        else
            moves[i]=1;
    }
    for(int i=0;i<n;i++)
        if(moves[i]==0)
            sort(arr[i],arr[i]+n,ascending);
        else
            sort(arr[i],arr[i]+n,descending);
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
