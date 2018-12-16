#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
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
int main()
{
    int t;
    int N,K;
    int len,s;
    lli count;
    cin>>t;
    while(t--)
    {
        count=0;
        cin>>N>>K;
        vector<int> init;
        for(int i=1;i<=K;i++)
            init.push_back(i);
        vector< vector<int> > v;
        vector<int> Set;
        vector< vector<int> > v_prime;
        vector<int> Set_prime;
        vector< vector<int> > v_element(K+1);
        for(int i=0;i<N;i++)
        {
            Set_prime=init;
            Set.clear();
            cin>>len;
            for(int j=0;j<len;j++)
            {
                cin>>s;
                Set.push_back(s);
                v_element[s].push_back(i);
                Set_prime.erase(remove(Set_prime.begin(),Set_prime.end(),s));
            }
            sort(Set.begin(),Set.end());
            v_prime.push_back(Set_prime);
            v.push_back(Set);
        }
        vector<int> s(K);
        int j;
        for(int i=0;i<N;i++)
        {
            if(v_prime[i].empty())
            {
                count+=N-1;
                continue;
            }
            else
                j=v_prime[i].at(0);
            if(v_element[j].empty())
                continue;
            for(auto x:v_element[j])
            {
                s.clear();
                vector<int>::iterator it;
                it=set_union(v[i].begin(),v[i].end(),v[x].begin(),v[x].end(),s.begin());
                s.resize(it-s.begin());
                if(s.size()==K)
                    ++count;
            }
        }
        cout<<count/2<<endl;
    }
}
