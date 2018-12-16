#include <iostream>
using namespace std;
bool isSubsetSum(int set[], int n, int sum)
{
    bool subset[n+1][sum+1];
    for(int i=0;i<=n;i++)
        subset[i][0]=true;
    for(int j=1;j<=sum;j++)
        subset[0][j]=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            subset[i][j]=subset[i-1][j];
            if(j>=set[i-1])
                subset[i][j]=subset[i][j]||subset[i-1][j-set[i-1]];
        }
    }
    return subset[n][sum];
}
int main()
{
    int t,n,m;
    int set[21];
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>set[i];
        if(isSubsetSum(set,n,m))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
