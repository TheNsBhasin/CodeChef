#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long int lli;
const int MAXN=100005;
const int MOD=1000000007;
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
    int p,q,r;
    lli prefixSum_A[MAXN],prefixSum_C[MAXN];
    lli sum,answer;
    cin>>t;
    while(t--)
    {
        cin>>p>>q>>r;
        vector<lli> A(p),B(q),C(r);
        map<lli,lli> ans;
        for(int i=0;i<p;i++)
            cin>>A[i];
        for(int i=0;i<q;i++)
            cin>>B[i];
        for(int i=0;i<r;i++)
            cin>>C[i];
        sort(A.begin(),A.end());
        sort(B.begin(),B.end(),greater<lli>());
        sort(C.begin(),C.end());
        prefixSum_A[0]=A[0];
        prefixSum_C[0]=C[0];
        for(int i=1;i<p;i++)
            prefixSum_A[i]=((prefixSum_A[i-1]%MOD)+(A[i]%MOD))%MOD;
        for(int i=1;i<r;i++)
            prefixSum_C[i]=((prefixSum_C[i-1]%MOD)+(C[i]%MOD))%MOD;
        answer=0;
        for(int i=0;i<q;i++)
        {
            if(ans.find(B[i])!=ans.end())
            {
                answer+=ans[B[i]];
                continue;
            }
            sum=0;
            lli index_A=upper_bound(A.begin(),A.end(),B[i])-A.begin();
            lli index_C=upper_bound(C.begin(),C.end(),B[i])-C.begin();
            if(index_A<= 0 || index_C<= 0)
                break;
            sum=((sum)%MOD+((((((index_C)%MOD)*(prefixSum_A[index_A-1])%MOD)%MOD)+((((index_A)%MOD)*(prefixSum_C[index_C-1])%MOD)%MOD))*(B[i]%MOD))%MOD)%MOD;
            sum=(sum%MOD+((prefixSum_A[index_A-1]%MOD)*(prefixSum_C[index_C-1]%MOD))%MOD)%MOD;
            sum=(sum%MOD+(((((((index_A)%MOD)*((index_C)%MOD))%MOD)*(B[i]%MOD))%MOD)*(B[i]%MOD))%MOD)%MOD;
            ans[B[i]]=sum%MOD;
            answer=(((answer)%MOD)+((sum)%MOD))%MOD;
        }
        cout<<answer<<endl;
    }
    return 0;
}
