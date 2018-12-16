#include <iostream>
#include <string>
using namespace std;
typedef struct Seat
{
    int s;
    string ch;
} Seat;
Seat arr[9];
void preprocess()
{
    arr[0]={-1,"SL"},arr[1]={4,"LB"},arr[2]={5,"MB"},arr[3]={6,"UB"},arr[4]={1,"LB"},arr[5]={2,"MB"},arr[6]={3,"UB"},arr[7]={8,"SU"},arr[8]={7,"SL"};
}
int main()
{
    int t,n;
    preprocess();
    cin>>t;
    while(t--)
    {
        cin>>n;
        int temp=n/8;
        int index=n%8;
        int ans=arr[index].s;
        ans+=8*temp;
        cout<<ans<<arr[index].ch<<endl;
    }
    return 0;
}
