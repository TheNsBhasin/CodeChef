#include <iostream>
using namespace std;
int main()
{
    int t;
    int N;
    int cost[1003];
    int pay;
    cin>>t;
    while(t--)
    {
        pay=0;
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>cost[i];
        sort(cost,cost+N,greater<int>());
        for(int i=0;i<N;i++)
        {
            pay+=cost[i];
            if(i!=N-1)
            {
                pay+=cost[i+1];
                i+=3;
            }
        }
        cout<<pay<<endl;
    }
    return 0;
}
