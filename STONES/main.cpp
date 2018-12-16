#include <iostream>
using namespace std;
int main()
{
    int t;
    char J[102],S[102];
    bool arr[150];
    cin>>t;
    while(t--)
    {
        int counter=0;
        cin>>J>>S;
        for(int i=0;i<150;i++)
            arr[i]=0;
        for(int i=0;J[i];i++)
            arr[J[i]]=true;
        for(int i=0;S[i];i++)
        {
            if(arr[S[i]])
                counter++;
        }
        cout<<counter<<endl;
    }
    return 0;
}
