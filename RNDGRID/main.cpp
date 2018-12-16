#include <iostream>
#include <stack>
#include <utility>
using namespace std;
typedef long long int lli;
char moves[100005];
char grid[1003][1003];
int N,L,XOR=0;
int isSafe(int row,int col,char move)
{
    if (grid[row][col]=='#')
            return 0;
    switch (move)
    {
        case 'R':
            if(col+1>=N || grid[row][col+1]=='#')
                return 0;
            break;
        case 'L':
            if(col-1<0 || grid[row][col-1]=='#')
                return 0;
            break;
        case 'U':
            if(row-1<0 || grid[row-1][col]=='#')
                return 0;
            break;
        case 'D':
            if(row+1>=N || grid[row+1][col]=='#')
                return 0;
            break;
        default:
            break;
    }
    return 1;
}
void solve()
{
    int row,col,count=0,k=-1;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            k=-1;
            row=i;
            col=j;
            count=0;
            while(isSafe(row,col,moves[++k]) && k<=L-1)
            {
                ++count;
                switch (moves[k])
                {
                    case 'L':
                        col--;
                        break;
                    case 'R':
                        col++;
                        break;
                    case 'U':
                        row--;
                        break;
                    case 'D':
                        row++;
                        break;
                }
                if(k>=L-1)
                    break;
            }
            XOR^=count;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>L>>N;
        XOR=0;
        cin>>moves;
        for(int i=0;i<N;i++)
            cin>>grid[i];
        solve();
        cout<<XOR<<endl;
    }
    return 0;
}
