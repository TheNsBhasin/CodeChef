#include <iostream>
using namespace std;
typedef long long int lli;
int main()
{
    int t;
    int N,K;
    lli arr[102];
    int counter;
    cin>>t;
    while(t--)
    {
        counter=0;
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>arr[i];
        cin>>K;
        K--;
        for(int i=0;i<N;i++)
        {
            if(i==K)
                continue;
            if(arr[i]<arr[K])
                counter++;
        }
        cout<<counter+1<<endl;
    }
    return 0;
}
