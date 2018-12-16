#include <iostream>
using namespace std;
int main()
{
    int t;
    string M,W;
    cin>>t;
    while(t--)
    {
        cin>>M>>W;
        if(M.length()>W.length())
            swap(M,W);
        int j=0;
        for(int i=0;W[i];i++)
        {
            if(W[i]==M[j])
                j++;
        }
        if(j==M.length())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
