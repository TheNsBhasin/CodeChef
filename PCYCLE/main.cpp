#include <iostream>
#include <vector>
using namespace std;
const int MAXN=1003;
int main()
{
    int N;
    int arr[MAXN];
    bool visited[MAXN];
    memset(visited,false,sizeof(visited));
    cin>>N;
    vector< vector<int> > v(N);
    for(int i=1;i<=N;i++)
        cin>>arr[i];
    int k=0;
    for(int i=1;i<=N;i++)
    {
        if(!visited[arr[i]])
        {
            int j=i;
            v[k].push_back(j);
            while(!visited[arr[j]])
            {
                v[k].push_back(arr[j]);
                visited[arr[j]]=true;
                j=arr[j];
            }
            k++;
        }
    }
    cout<<k<<endl;
    for(int i=0;i<k;i++)
    {
        for(auto x:v[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
