#include <iostream>
using namespace std;
const int MAXN=52;
int main()
{
    int t,n;
    int arr[MAXN];
    string str;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>str;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        if(n==1 && str=="Dee" && arr[0]%2==0)
            cout<<"Dee"<<endl;
        else
            cout<<"Dum"<<endl;
    }
    return 0;
}
