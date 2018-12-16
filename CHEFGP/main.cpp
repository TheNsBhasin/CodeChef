/*input
15
bbbbbaa
3 2
bbbbbaa
3 3
aaaaabbb
1 3
aaaaabbb
2 1
aaaaabbb
2 2
aaaaabbb
1 2
aaaaabbbbb
3 4
aaaaabbbbb
2 2
aaaaabbbbb
4 2
aaaabbbbb
4 5
aaaaaaaabb
5 2
aaaaaaaabb
2 5
aaaaaaaabb
3 3
aaaaaaaabb
9 1
aaaaaaaabb
1 9
*/

//
//  main.cpp
//  CHEFGP
//
//  Created by Nirmaljot Singh Bhasin on 06/10/17.
//  Copyright Ã�ï¿½Ã�Â© 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <string>
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

int main(int argc, const char * argv[]) {
    lli t;
    cin >> t;
    while (t--) {
        string str;
        lli x, y;
        lli num_apple = 0, num_banana = 0;
        cin >> str;
        cin >> x >> y;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == 'a') {
                ++num_apple;
            } else {
                ++num_banana;
            }
        }
        lli proper_group_apple = num_apple / x;
        lli remaining_apple = num_apple % x;
        lli proper_group_banana = num_banana / y;
        lli remaining_banana = num_banana % y;
        lli total_group_apple = proper_group_apple + (remaining_apple != 0);
        lli total_group_banana = proper_group_banana + (remaining_banana != 0);
        string tmp = "";
        if (total_group_apple > total_group_banana) {
            while (proper_group_apple > 0) {
                for (int i = 0; i < x; ++i) {
                    tmp.push_back('a');
                }
                if (proper_group_apple > 1) {
                    if (num_banana) {
                        tmp.push_back('b');
                        --num_banana;
                    } else {
                        tmp.push_back('*');
                    }
                }
                --proper_group_apple;
            }
            if (remaining_apple > 0) {
                if (num_banana) {
                    tmp.push_back('b');
                    --num_banana;
                } else {
                    tmp.push_back('*');
                }
            }
            while (remaining_apple > 0) {
                tmp.push_back('a');
                --remaining_apple;
            }
            for (int i = 0; i < tmp.size(); ++i) {
                if (tmp[i] == 'a') {
                    cout << tmp[i];
                } else {
                    cout << tmp[i];
                    lli count = 1;
                    while (count < y && num_banana > 0) {
                        cout << tmp[i];
                        ++count;
                        --num_banana;
                    }
                }
            }
        } else if (total_group_apple < total_group_banana) {
            while (proper_group_banana > 0) {
                for (int i = 0; i < y; ++i) {
                    tmp.push_back('b');
                }
                if (proper_group_banana > 1) {
                    if (num_apple) {
                        tmp.push_back('a');
                        --num_apple;
                    } else {
                        tmp.push_back('*');
                    }
                }
                --proper_group_banana;
            }
            if (remaining_banana > 0) {
                if (num_apple) {
                    tmp.push_back('a');
                    --num_apple;
                } else {
                    tmp.push_back('*');
                }
            }
            while (remaining_banana) {
                tmp.push_back('b');
                --remaining_banana;
            }
            for (int i = 0; i < tmp.size(); ++i) {
                if (tmp[i] == 'b') {
                    cout << tmp[i];
                } else {
                    cout << tmp[i];
                    lli count = 1;
                    while (count < x && num_apple > 0) {
                        cout << tmp[i];
                        ++count;
                        --num_apple;
                    }
                }
            }
        } else {
            while (proper_group_apple > 0 && proper_group_banana > 0) {
                for (int i = 0; i < x; ++i) {
                    cout << "a";
                }
                --proper_group_apple;
                for (int i = 0; i < y; ++i) {
                    cout << "b";
                }
                --proper_group_banana;
            }
            if (proper_group_apple > 0) {
                for (int i = 0; i < x; ++i) {
                    cout << "a";
                }
            }
            if (remaining_apple > 0) {
                for (int i = 0; i < remaining_apple; ++i) {
                    cout << "a";
                }
            }
            if (proper_group_banana > 0) {
                for (int i = 0; i < x; ++i) {
                    cout << "b";
                }
            }
            if (remaining_banana > 0) {
                for (int i = 0; i < remaining_banana; ++i) {
                    cout << "b";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
