/*input
1
3 6
0110
0000
0000
0001

0000
0000
0000
0000

1000
1000
0000
0000

1 1 1
1 2 2
1 3 3
1 1 3
2 2
0001
0010
0100
1000
1 1 3
*/

//
//  main.cpp
//  PSHTBRTH
//
//  Created by Nirmaljot Singh Bhasin on 22/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <bitset>

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

typedef long long int lli;

const int MAXN = 100005;
const int BITN = 65536;

int grundy[BITN];
int arr[MAXN], seg[2 * MAXN + 1];

int mex(const unordered_set<int> &s) {
	int mex = 0;
	while (s.find(mex) != s.end()) {
		++mex;
	}
	return mex;
}

int checkOnes(int mat, int i, int j , int k, int l) {
	bitset<16> m(mat);
	for (int x = i; x <= j; x++) {
		for (int y = k; y <= l; y++) {
			int pos = 15 - ((x * 4) + y);
			if (!m.test(pos)) {
				return -1;
			}
			m.reset(pos);
		}
	}
	int res = m.to_ullong();
	return res;
}

int getGrundy(int pos) {
	if (grundy[pos] != -1) {
		return grundy[pos];
	}
	unordered_set<int> s;
	for (int i = 0; i < 4; ++i) {
		for (int j = i; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				for (int l = k; l < 4; ++l) {
					int res = checkOnes(pos, i, j , k, l);
					if (res != -1) {
						grundy[res] = getGrundy(res);
						s.insert(grundy[res]);
					}
				}
			}
		}
	}

	return mex(s);
}

void preprocess() {
	fill(grundy, grundy + BITN, - 1);
	grundy[0] = 0;
	grundy[BITN - 1] = getGrundy(BITN - 1);
}

int readMatrix() {
	bitset<16> m(0);
	string str;
	int bit;
	for (int i = 0; i < 4; ++i) {
		cin >> str;
		for (int j = 0; j < 4; ++j) {
			int pos = 15 - ((4 * i) + j);
			bit = (str[j] == '1') ? 1 : 0;
			if (bit == 1) {
				m.set(pos);
			}
		}
	}
	return m.to_ullong();
}

void build(int low, int high, int idx) {
	if (low == high) {
		seg[idx] = arr[low];
		return;
	}

	int mid = low + ((high - low) >> 1);
	build(low, mid, (idx << 1));
	build(mid + 1, high, (idx << 1) + 1);
	seg[idx] = seg[(idx << 1)] ^ seg[(idx << 1) + 1];
}

int query(int low, int high, int left, int right, int idx) {
	if (left > high || right < low) {
		return 0;
	}
	if (left <= low && right >= high) {
		return seg[idx];
	}

	int mid = low + ((high - low) >> 1);
	return query(low, mid, left , right, (idx << 1)) ^ query(mid + 1, high, left , right, (idx << 1) + 1);
}

void update(int low, int high, int val, int pos, int idx) {
	if (pos > high || pos < low) {
		return;
	}
	if (low == high) {
		seg[idx] = val;
		return;
	}

	int mid = low + ((high - low) >> 1);
	update(low, mid, val , pos, (idx << 1));
	update(mid + 1, high, val , pos, (idx << 1) + 1);

	seg[idx] = seg[(idx << 1)] ^ seg[(idx << 1) + 1];
}

int main(int argc, const char * argv[]) {
	preprocess();
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			int mat = readMatrix();
			arr[i] = grundy[mat];
			getchar();
		}

		build(0, n - 1, 1);
		while (m--) {
			int type, l, r, idx;
			cin >> type;
			if (type == 1) {
				cin >> l >> r;
				--l; --r;
				int res = query(0, n - 1, l , r, 1);
				if (res) {
					cout << "Pishty" << endl;
				} else {
					cout << "Lotsy" << endl;
				}
			} else {
				cin >> idx;
				--idx;
				int mat = readMatrix();

				update(0, n - 1, grundy[mat], idx, 1);
			}
		}
	}
	return 0;
}
