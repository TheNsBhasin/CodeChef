#include <iostream>
#include <utility>
#include <vector>
#include <set>
using namespace std;
typedef long long int lli;
int n,m;
int moves_x[] = {1,0,-1,0,1,1,-1,-1};
int moves_y[] = {0,1,0,-1,1,-1,1,-1};
bool visited[502][502];
void swap(vector< vector<lli> > &wealth,set< pair<int,int> > &pos,set< pair<int,int> > &new_pos)
{
    for(set< pair<int,int> >::iterator it=pos.begin();it!=pos.end();it++)
    {
        int X=(*it).first;
        int Y=(*it).second;
        visited[X][Y]=true;
        for(int i=0;i<8;i++)
        {
            int x=X+moves_x[i];
            int y=Y+moves_y[i];
            if((x>=0 && x<n && y>=0 && y<m) && visited[x][y]==false && wealth[x][y]!=wealth[X][Y])
            {
                visited[x][y]=true;
                wealth[x][y]=wealth[X][Y];
                new_pos.insert(make_pair(x,y));
            }
        }
    }
}
lli solve(vector< vector<lli> > &wealth)
{
    lli count=0;
    lli maxi=-1;
    memset(visited,false,sizeof(visited));
    set< pair<int,int> > pos;
    set< pair<int,int> > new_pos;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(wealth[i][j]>maxi)
            {
                pos.clear();
                maxi=wealth[i][j];
                pos.insert(make_pair(i,j));
            }
            if(wealth[i][j]==maxi)
                pos.insert(make_pair(i,j));
        }
    }
    int processed=0;
    while(processed+pos.size()!=(n*m))
    {
        swap(wealth,pos,new_pos);
        ++count;
        processed+=pos.size();
        pos=new_pos;
        new_pos.clear();
    }
    return count;
}
int main()
{
    int t;
    lli w;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector< vector<lli> > wealth;
        for(int i=0;i<n;i++)
        {
            vector<lli> row;
            for(int j=0;j<m;j++)
            {
                cin>>w;
                row.push_back(w);
            }
            wealth.push_back(row);
        }
        cout<<solve(wealth)<<endl;
    }
    return 0;
}
