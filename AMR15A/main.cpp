#include <iostream>
using namespace std;
int main()
{
    int n,w,count=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>w;
        if(w%2==0)
            count++;
    }
    if(count>n-count)
        cout<<"READY FOR BATTLE"<<endl;
    else
        cout<<"NOT READY"<<endl;
    return 0;
}
