#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;
typedef long long int lli;
const int MAXN=10000007;
lli tree[MAXN]={0};
bool lazy[MAXN]={false};
void constructSTUtil(int ss,int se,int si)
{
    if(ss>se)
        return;
    if(ss==se)
    {
        tree[si]=0;
        return;
    }
    int mid=ss+(se-ss)/2;
    constructSTUtil(ss,mid,2*si+1);
    constructSTUtil(mid+1,se,2*si+2);
    tree[si]=tree[2*si+1]+tree[2*si+2];
}
void constructST(int N)
{
    constructSTUtil(0,N-1,0);
}
void updateUtil(int si,int ss,int se,int us,int ue)
{
    if(lazy[si])
    {
        tree[si]=(se-ss+1)-tree[si];
        if(ss!=se)
        {
            lazy[2*si+1]=!lazy[2*si+1];
            lazy[2*si+2]=!lazy[2*si+2];
        }
        lazy[si]=false;
    }
    if(ss>se || ss>ue || se<us)
        return;
    if (ss==se)
    {
        tree[si]=!tree[si];
        return;
    }
    if(ss>=us && se<=ue)
    {
        tree[si]=(se-ss+1)-tree[si];
        if(ss!=se)
        {
            lazy[2*si+1]=!lazy[2*si+1];
            lazy[2*si+2]=!lazy[2*si+2];
        }
        return;
    }
    int mid=ss+(se-ss)/2;
    updateUtil(2*si+1,ss,mid,us,ue);
    updateUtil(2*si+2,mid+1,se,us,ue);
    tree[si]=tree[2*si+1]+tree[2*si+2];
}
void update(int n,int us,int ue)
{
    updateUtil(0,0,n-1,us,ue);
}
lli solveQuery(int ss,int se,int qs,int qe,int si)
{
    if(lazy[si])
    {
        tree[si]=(se-ss+1)-tree[si];
        if(ss!=se)
        {
            lazy[2*si+1]=!lazy[2*si+1];
            lazy[2*si+2]=!lazy[2*si+2];
        }
        lazy[si]=false;
    }
    if(ss>se || ss>qe || se<qs)
        return 0;
    if(ss>=qs && se<=qe)
        return tree[si];
    int mid=ss+(se-ss)/2;
    return solveQuery(ss,mid,qs,qe,2*si+1)+solveQuery(mid+1,se,qs,qe,2*si+2);
}
lli query(int n,int qs,int qe)
{
    return solveQuery(0,n-1,qs,qe,0);
}
int main()
{
    int N,Q;
    int t,A,B;
    cin>>N>>Q;
    constructST(N);
    while(Q--)
    {
        cin>>t>>A>>B;
        if(t==0)
            update(N,A,B);
        else
            cout<<query(N,A,B)<<endl;
    }
}
