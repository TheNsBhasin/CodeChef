#include <iostream>
using namespace std;
int main()
{
    int t;
    int N,K;
    int W[102];
    int totalSum,sum1,sum2;
    cin>>t;
    while(t--)
    {
        totalSum=sum1=sum2=0;
        cin>>N>>K;
        for(int i=0;i<N;i++)
        {
            cin>>W[i];
            totalSum+=W[i];
        }
        sort(W,W+N);
        for(int i=0;i<K;i++)
            sum1+=W[i];
        for(int i=N-1;i>=N-K;i--)
            sum2+=W[i];
        cout<<max(abs(sum1-(totalSum-sum1)),abs(sum2-(totalSum-sum2)))<<endl;
    }
    return 0;
}
