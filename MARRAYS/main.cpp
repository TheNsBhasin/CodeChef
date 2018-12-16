/*input
3
3
3 1 2 3
2 3 2
2 4 5
2
2 1 2
2 4 5
3
2 1 2
3 3 2 5
2 4 5
*/

//
//  main.cpp
//  MARRAYS
//
//  Created by Nirmaljot Singh Bhasin on 07/10/17.
//  Copyright Â© 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <climits>
#include <map>
#include <utility>
#include <vector>
using namespace std;

typedef long long int lli;

const int MAXN = 1000006;

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
    inline bool skipBlanks() {
        while (isBlank(nextChar()));
        return peekChar() != 0;

    }

    inline IO& operator >> (char & c) { c = nextChar(); return *this; }

    inline IO& operator >> (char * buf) {
        if (skipBlanks()) {
            if (peekChar()) {
                *(buf++) = peekChar();
                while (!isBlank(nextChar())) *(buf++) = peekChar();
            } *(buf++) = 0;
        } return *this;
    }

    inline IO& operator >> (string & s) {
        if (skipBlanks()) {
            s.clear(); s += peekChar();
            while (!isBlank(nextChar())) s += peekChar();
        }
        return *this;
    }

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

lli n;
vector<lli> v[MAXN];
vector<lli> dp[MAXN];
vector< pair<lli, lli> > range[MAXN];

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 2) {
            lli max1 = LONG_MIN, max2 = LONG_MIN;
            lli min1 = LONG_MAX, min2 = LONG_MAX;
            for (int i = 0; i < n; ++i) {
                v[i].clear();
                lli m;
                cin  >> m;
                for (int j = 0; j < m; ++j) {
                    lli x;
                    cin >> x;
                    v[i].push_back(x);
                    if (i == 0) {
                        if (x < min1) {
                            min1 = x;
                        }
                        if (x > max1) {
                            max1 = x;
                        }
                    }
                    if (i == 1) {
                        if (x < min2) {
                            min2 = x;
                        }
                        if (x > max2) {
                            max2 = x;
                        }
                    }
                }
            }
            cout << max(abs(min1 - max2), abs(max1 - min2)) << endl;
            continue;
        }
        for (int i = 0; i < n; ++i) {
            v[i].clear();
            dp[i].clear();
            range[i].clear();
            lli m;
            cin >> m;
            for (int j = 0; j < m; ++j) {
                lli x;
                cin >> x;
                v[i].push_back(x);
                dp[i].push_back(0);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
                range[i].push_back(make_pair(v[i][(j + 1) % v[i].size()], v[i][j]));
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
                for (int k = 0; k < v[i - 1].size(); ++k) {
                    dp[i][j] = max(dp[i][j], abs(range[i][j].first - range[i - 1][k].second) * i + dp[i - 1][k]);
                }
            }
        }

        lli ans = dp[n - 1][0];
        for (int i = 1; i < v[n - 1].size(); ++i) {
            ans = max(ans, dp[n - 1][i]);
        }
        cout << ans << endl;
    }
    return 0;
}