/*input
5 3
1 1 1 1 1
2 5 1
1 3 2
2 5 1
*/

//
//  main.cpp
//  CHEFEXQ
//
//  Created by Nirmaljot Singh Bhasin on 02/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <unordered_map>
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
        if (skipBlanks()) { s.clear(); s += peekChar();
            while (!isBlank(nextChar())) s += peekChar(); }
        return *this; }
    
    inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this; }
    
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
const int RTN = 750;
const int MAXN = 100005;

lli arr[MAXN], bkt[MAXN], loc[MAXN];
lli mat[RTN + 1][RTN + 1], prefix_xor[RTN + 1][RTN + 1];
lli siz[RTN + 1];
unordered_map<lli, lli> cnt[RTN + 1];

void compute(lli bucket) {
    cnt[bucket].clear();
    prefix_xor[bucket][0] = mat[bucket][0];
    ++cnt[bucket][prefix_xor[bucket][0]];
    for (int i = 1; i < siz[bucket]; ++i) {
        prefix_xor[bucket][i] = prefix_xor[bucket][i - 1] ^ mat[bucket][i];
        ++cnt[bucket][prefix_xor[bucket][i]];
    }
}

int main(int argc, const char * argv[]) {
    int n, q;
    cin >> n >> q;

    lli bucket = -1, pos = 0;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (i % RTN == 0) {
            if (bucket >= 0) {
                compute(bucket);
            }
            ++bucket;
            siz[bucket] = 0;
            pos = 0;
        }
        bkt[i] = bucket;
        loc[i] = pos;
        ++siz[bucket];
        mat[bucket][pos] = arr[i];
        ++pos;
    }
    compute(bucket);

    while (q--) {
        int type, idx, val;
        cin >> type >> idx >> val;
        --idx;

        if (type == 1) {
            bucket = bkt[idx];
            pos = loc[idx];
            mat[bucket][pos] = val;
            compute(bucket);
        } else {
            bucket = bkt[idx];
            lli ans = 0, pre = 0;
            lli ptr = 0;

            while (bkt[ptr] < bucket) {
                lli cur_bkt = bkt[ptr];
                lli need = val ^ pre;
                ans += cnt[cur_bkt][need];
                pre = pre ^ prefix_xor[cur_bkt][siz[cur_bkt] - 1];
                ptr += RTN;
            }

            for (int i = 0; i <= loc[idx]; ++i) {
                pre = pre ^ mat[bucket][i];
                if (pre == val) {
                    ++ans;
                }
            }

            cout << ans << endl;
        }
    }
    return 0;
}
