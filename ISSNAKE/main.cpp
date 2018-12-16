#include <iostream>
using namespace std;
const int MAXN=502;
char arr[2][MAXN];
int n;
int total;
bool traverse(int row,int col)
{
    bool moveVerticle=false;
    int visited=0;
    for(int i=row,j=col;j<n;)
    {
        if(arr[i][j]=='.')
            break;
        ++visited;
        if(!moveVerticle && arr[1-i][j]=='#')
        {
            moveVerticle=true;
            i=1-i;
        }
        else
        {
            moveVerticle=false;
            j++;
        }
    }
    if(total==visited)
        return true;
    return false;
}
bool solve()
{
    int col=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[0][i]=='#' || arr[1][i]=='#')
        {
            col=i;
            break;
        }
    }
    return (col>=0 && (traverse(0,col) || traverse(1,col)));
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        total=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[0][i];
            if(arr[0][i]=='#')
                ++total;
        }
        for(int i=0;i<n;i++)
        {
            cin>>arr[1][i];
            if(arr[1][i]=='#')
                ++total;
        }
        if(solve())
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
