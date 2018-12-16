#include <iostream>
#include <set>
using namespace std;
int main()
{
    int t;
    int N,x;
    cin>>t;
    while(t--)
    {
        set<int> s;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>x;
            s.insert(x);
        }
        cout<<s.size()<<endl;
    }
    return 0;
}
