#include <iostream>
using namespace std;
int main()
{
    int t;
    int N;
    int arr[102];
    cin>>t;
    while(t--)
    {
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>arr[i];
        int localInv=0,globalInv=0;
        for(int i=0;i<N-1;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(arr[j]<arr[i])
                    globalInv++;
            }
        }
        
        for(int i=0;i<N-1;i++)
        {
            if(arr[i+1]<arr[i])
                localInv++;
        }
        if(localInv == globalInv)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
