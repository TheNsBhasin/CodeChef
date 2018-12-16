#include <iostream>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n][n],count=0,bandwidth;
        bandwidth=(2*n-1)/2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]==0)
                    count++;
            }
        }
        count/=2;
        int j=1;
        while(count!=0)
        {
            if(count-j>=0)
            {
                count=count-j;
                bandwidth--;
            }
            else
                count=0;
            j++;
        }
        cout<<bandwidth<<endl;
    }
    return 0;
}
