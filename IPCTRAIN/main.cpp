#include <iostream>
#include <queue>
#include <utility>
using namespace std;
const int MAXN=100005;
typedef long long int lli;
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

typedef struct subset
{
    lli parent;
} subset;
lli find(subset subsets[], lli i)
{
    if(subsets[i].parent!=i)
        subsets[i].parent=find(subsets,subsets[i].parent);
    return subsets[i].parent;
}
void Union(subset subsets[], lli x,lli y)
{
    lli xroot=find(subsets,x);
    lli yroot=find(subsets,y);
    
    subsets[yroot].parent=xroot;
}

int main()
{
    int t;
    lli N,D;
    lli day,lect,sad;
    lli maxSad;
    pair<lli, pair<lli,lli> > temp;
    cin>>t;
    while(t--)
    {
        maxSad=0;
        priority_queue<pair<lli, pair<lli,lli> > > pq;
        cin>>N>>D;
        for(int i=0;i<N;i++)
        {
            cin>>day>>lect>>sad;
            pq.push(make_pair(sad, make_pair(lect, day)));
        }
        subset subsets[D+1];
        for(int i=0;i<=D;i++)
            subsets[i].parent=i;
        while(!pq.empty())
        {
            temp=pq.top();
            pq.pop();
            lli d = (temp.second).second;
            lli availableSlot=find(subsets,D-d+1);
            if(availableSlot>0)
            {
                Union(subsets,find(subsets,availableSlot-1),availableSlot);
                (temp.second).first--;
                if((temp.second).first>0)
                    pq.push(temp);
            }
            else
            {
                maxSad+=(((temp.second).first)*(temp.first));
                continue;
            }
        }
        cout<<maxSad<<endl;
    }
    return 0;
}
