#include <iostream>
#include <vector>
#include <utility>
using namespace std;
static struct IO {
    char tmp[1 << 10];
    
    // fast input routines
    char cur;
    
    //#define nextChar() (cur = getc_unlocked(stdin))
    //#define peekChar() (cur)
    inline char nextChar() { return cur = getc_unlocked(stdin); }
    inline char peekChar() { return cur; }
    
    inline operator bool() { return peekChar(); }
    inline static bool isBlank(char c) { return (c < '-' && c); }
    inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }
    
    inline IO& operator >> (char & c) { c = nextChar(); return *this; }
    
    inline IO& operator >> (char * buf) {
        if (skipBlanks()) {
            if (peekChar()) {
                *(buf++) = peekChar();
                while (!isBlank(nextChar())) *(buf++) = peekChar();
            } *(buf++) = 0; } return *this; }
    
    inline IO& operator >> (string & s) {
        if (skipBlanks()) {	s.clear(); s += peekChar();
            while (!isBlank(nextChar())) s += peekChar(); }
        return *this; }
    
    inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}
    
#define defineInFor(intType) \
inline IO& operator >>(intType & n) { \
if (skipBlanks()) { \
int sign = +1; \
if (peekChar() == '-') { \
sign = -1; \
n = nextChar() - '0'; \
} else \
n = peekChar() - '0'; \
while (!isBlank(nextChar())) { \
n += n + (n << 3) + peekChar() - 48; \
} \
n *= sign; \
} \
return *this; \
}
    
    defineInFor(int)
    defineInFor(unsigned int)
    defineInFor(long long)
    
    // fast output routines
    
    //#define putChar(c) putc_unlocked((c), stdout)
    inline void putChar(char c) { putc_unlocked(c, stdout); }
    inline IO& operator << (char c) { putChar(c); return *this; }
    inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }
    
    inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }
    
    char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
    inline IO& operator << (double d) { return (*this) << toString(d); }
    
    
#define defineOutFor(intType) \
inline char * toString(intType n) { \
char * p = (tmp + 30); \
if (n) { \
bool isNeg = 0; \
if (n < 0) isNeg = 1, n = -n; \
while (n) \
*--p = (n % 10) + '0', n /= 10; \
if (isNeg) *--p = '-'; \
} else *--p = '0'; \
return p; \
} \
inline IO& operator << (intType n) { return (*this) << toString(n); }
    
    defineOutFor(int)
    defineOutFor(long long)
    
#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;
typedef long long int lli;
const int MAXN=100005;
const int LN=17;
const int ROOT=0;
vector<lli> adj[MAXN], costs[MAXN], indexx[MAXN];
lli baseArray[MAXN], ptr;
lli chainNo, chainInd[MAXN], chainHead[MAXN], posInBase[MAXN];
lli depth[MAXN], dp[LN][MAXN], otherEnd[MAXN], subsize[MAXN];
lli k;
struct node
{
    vector<lli> val;
    vector<lli> xor_val;
} st[6*MAXN];

void make_tree(lli ss, lli se, lli si)
{
    if(ss==se)
    {
        st[si].val.push_back(baseArray[ss]);
        st[si].xor_val.push_back(baseArray[ss]^0);
        return;
    }
    lli mid=ss+(se-ss)/2;
    make_tree(ss, mid, 2*si);
    make_tree(mid+1, se, 2*si+1);
    for(lli i=ss;i<=se;i++)
        st[si].val.push_back(baseArray[i]);
    sort(st[si].val.begin(), st[si].val.end());
    st[si].xor_val.push_back(st[si].val.front());
    for(vector<lli>:: iterator it = st[si].val.begin()+1; it!=st[si].val.end(); it++)
        st[si].xor_val.push_back((*it)^(st[si].xor_val.at(st[si].xor_val.size()-1)));
}

lli query_tree(lli ss, lli se, lli qs, lli qe, lli si)
{
    if(qs<=ss && qe>=se)
    {
        lli i=upper_bound(st[si].val.begin(), st[si].val.end(), k)-(st[si].val.begin());
        if(i==0)
            return 0;
        return st[si].xor_val.at(i-1);
    }
    if(se<qs || ss>qe)
        return 0;
    if(ss==se)
        return 0;
    lli mid=ss+(se-ss)/2;
    return query_tree(ss, mid, qs, qe, 2*si)^query_tree(mid+1, se, qs, qe, 2*si+1);
}

lli query_up(lli u, lli v)
{
    if(u==v)
        return 0;
    lli uchain, vchain=chainInd[v], ans=0;
    while(1)
    {
        uchain=chainInd[u];
        if(uchain==vchain)
        {
            if(u==v)
                break;
            ans^=query_tree(1,ptr-1,posInBase[v]+1,posInBase[u],1);
            break;
        }
        ans^=query_tree(1,ptr-1,posInBase[chainHead[uchain]],posInBase[u],1);
        u=chainHead[uchain];
        u=dp[0][u];
    }
    return ans;
}

lli LCA(lli u, lli v)
{
    if(depth[u]<depth[v])
        swap(u,v);
    lli diff=depth[u]-depth[v];
    for(int i=0;i<LN;i++)
    {
        if((diff>>i)&1)
            u=dp[i][u];
    }
    if(u==v)
        return u;
    for(int i=LN-1;i>=0;i--)
    {
        if(dp[i][u]!=dp[i][v])
        {
            u=dp[i][u];
            v=dp[i][v];
        }
    }
    return dp[0][u];
}

lli query(lli u, lli v)
{
    lli lca=LCA(u,v);
    lli ans=query_up(u, lca);
    ans^=query_up(v, lca);
    return ans;
}

void HLD(lli currNode, lli cost, lli prev)
{
    if(chainHead[chainNo]==-1)
        chainHead[chainNo]=currNode;
    chainInd[currNode]=chainNo;
    posInBase[currNode]=ptr;
    baseArray[ptr++]=cost;
    
    lli sc=-1, ncost=0;
    for(int i=0;i<adj[currNode].size();i++)
    {
        if(adj[currNode][i]!=prev)
        {
            if(sc==-1 || subsize[sc]<subsize[adj[currNode][i]])
            {
                sc=adj[currNode][i];
                ncost=costs[currNode][i];
            }
        }
    }
    
    if(sc!=-1)
        HLD(sc, ncost, currNode);
    
    for(int i=0;i<adj[currNode].size();i++)
    {
        if(adj[currNode][i]!=prev)
        {
            if(sc!=adj[currNode][i])
            {
                chainNo++;
                HLD(adj[currNode][i], costs[currNode][i], currNode);
            }
        }
    }
}

void dfs(lli curr, lli prev, lli _depth=0)
{
    dp[0][curr]=prev;
    depth[curr]=_depth;
    subsize[curr]=1;
    for(int i=0;i<adj[curr].size();i++)
    {
        if(adj[curr][i]!=prev)
        {
            otherEnd[indexx[curr][i]]=adj[curr][i];
            dfs(adj[curr][i], curr, _depth+1);
            subsize[curr]+=subsize[adj[curr][i]];
        }
    }
}
int main()
{
    int t;
    lli n,m;
    lli u,v,c;
    lli ans;
    cin>>t;
    while(t--)
    {
        ptr=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            adj[i].clear();
            costs[i].clear();
            indexx[i].clear();
            chainHead[i]=-1;
            for(int j=0;j<LN;j++)
                dp[j][i]=-1;
        }
        for(int i=1;i<n;i++)
        {
            cin>>u>>v>>c;
            u--;v--;
            adj[u].push_back(v);
            costs[u].push_back(c);
            indexx[u].push_back(i-1);
            adj[v].push_back(u);
            costs[v].push_back(c);
            indexx[v].push_back(i-1);
        }
        chainNo=0;
        dfs(ROOT,-1);
        HLD(ROOT, -1, -1);
        make_tree(1,ptr-1,1);
        for(int i=1; i<LN; i++)
            for(int j=0; j<n; j++)
                if(dp[i-1][j] != -1)
                    dp[i][j] = dp[i-1][dp[i-1][j]];
        for(int i=0;i<8;i++)
        {
            for(lli x:st[i].val)
                cout<<x<<" ";
            cout<<endl;
            for(lli x:st[i].xor_val)
                cout<<x<<" ";
            cout<<endl<<endl;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v>>k;
            u--;v--;
            ans=0;
            if(u==v)
            {
                cout<<ans<<endl;
                continue;
            }
            ans=query(u,v);
            cout<<ans<<endl;
        }
    }
}
