/*input
6 7
1 2 3 4 5 6
1 2
1 3
2 4
2 5
3 6
1 5 6
2 5 6
1 1 5
1 5 6
2 1 6
1 5 6
1 2 6
*/
 
//
//  main.cpp
//  DISTNUM3
//
//  Created by Nirmaljot Singh Bhasin on 22/12/17.
//  Copyright Â© 2017 Nirmaljot Singh Bhasin. All rights reserved.
//
 
#include <iostream>
#include <vector>
#include <utility>
#include <memory.h>
#include <map>
#include <algorithm>
#include <assert.h>
 
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
 
const int MAXN = 100050;
const int LN = 21;
const int BLK_SIZ = 2154;
 
int arr[MAXN], tmp[MAXN], depth[MAXN], freq[MAXN], ans[MAXN], pa[MAXN][LN], stamp[MAXN << 1], in[MAXN], out[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];
map<lli, lli> m;
int timer = 0;
int qt = 0, ut = 0;
 
struct query {
	int id;
	int L, R, t;
	int lca;
 
	query() {
		id = L = R = t = lca = -1;
	}
	query(int id, int L , int R, int t, int lca) : id(id), L(L), R(R), t(t), lca(lca) {}
} qu[MAXN];
 
struct update {
	int id;
	lli prev, curr;
 
	update() {
		id = prev = curr = -1;
	}
	update(int id, lli prev , lli curr) : id(id), prev(prev), curr(curr) {}
} upd[MAXN];
 
bool cmp(query &q1, query &q2) {
	if (q1.L / BLK_SIZ == q2.L / BLK_SIZ) {
		if (q1.R / BLK_SIZ == q2.R / BLK_SIZ) {
			return q1.t < q2.t;
		}
		return q1.R < q2.R;
	}
	return q1.L < q2.L;
}
 
void dfs(int u, int p) {
	depth[u] = depth[p] + 1;
	in[u] = ++timer;
	stamp[timer] = u;
	pa[u][0] = p;
	for (auto v : adj[u]) {
		if (v != p) {
			dfs(v, u);
		}
	}
	out[u] = ++timer;
	stamp[timer] = u;
}
 
int LCA(int u, int v) {
	if (depth[v] < depth[u]) {
		swap(u, v);
	}
 
	int diff = depth[v] - depth[u];
 
	for (int i = 0; i < LN; i++) {
		if ((diff >> i) & 1) {
			v = pa[v][i];
		}
	}
 
	if (u == v) {
		return u;
	}
 
	for (int i = LN - 1; i >= 0; i--) {
		if (pa[u][i] != pa[v][i]) {
			u = pa[u][i];
			v = pa[v][i];
		}
	}
 
	return pa[u][0];
}
 
void util(int idx, lli &cnt) {
	if (vis[idx]) {
		--freq[arr[idx]];
		if (freq[arr[idx]] == 0) {
			--cnt;
		}
	} else {
		++freq[arr[idx]];
		if (freq[arr[idx]] == 1) {
			++cnt;
		}
	}
	vis[idx] = !vis[idx];
}
 
void solve() {
	memset(vis, false, sizeof(vis));
	memset(freq, 0, sizeof(freq));
	int start = 1;
	int end = 0;
	int ut = 0;
	lli cnt = 0;
	for (int i = 0; i < qt; ++i) {
		while (ut < qu[i].t)
		{
			++ut;
			if (vis[upd[ut].id])
			{
				util(upd[ut].id, cnt);
				arr[upd[ut].id] = upd[ut].curr;
				util(upd[ut].id, cnt);
			}
			else arr[upd[ut].id] = upd[ut].curr;
		}
		while (ut > qu[i].t)
		{
			if (vis[upd[ut].id])
			{
				util(upd[ut].id, cnt);
				arr[upd[ut].id] = upd[ut].prev;
				util(upd[ut].id, cnt);
			}
			else arr[upd[ut].id] = upd[ut].prev;
			ut--;
		}
		while (end < qu[i].R) {
			util(stamp[++end], cnt);
		}
		while (end > qu[i].R) {
			util(stamp[end--], cnt);
		}
		while (start < qu[i].L) {
			util(stamp[start++], cnt);
		}
		while (start > qu[i].L) {
			util(stamp[--start], cnt);
		}
		if (qu[i].lca != stamp[qu[i].L]) {
			util(qu[i].lca, cnt);
		}
		ans[qu[i].id] = cnt;
		if (qu[i].lca != stamp[qu[i].L]) {
			util(qu[i].lca, cnt);
		}
	}
}
 
int main(int argc, const char * argv[]) {
	memset(pa, -1, sizeof(pa));
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		tmp[i] = arr[i];
		m[arr[i]];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
	timer = 0;
	dfs(1, 0);
 
	for (int i = 1; i < LN; ++i) {
		for (int u = 1; u <= n; ++u) {
			if (pa[u][i - 1] != -1) {
				pa[u][i] = pa[pa[u][i - 1]][i - 1];
			}
		}
	}
 
	qt = 0; ut = 0;
	for (int i = 0; i < q; ++i) {
		int type;
		cin >> type;
		if (type == 1) {
			int u, v;
			cin >> u >> v;
			if (in[u] > in[v]) {
				swap(u, v);
			}
			int lca = LCA(u, v);
			if (lca == u) {
				qu[qt] = query(qt, in[u], in[v], ut, lca);
			} else {
				qu[qt] = query(qt, out[u], in[v], ut, lca);
			}
			qt++;
		} else {
			int idx, val;
			cin >> idx >> val;
			ut++;
			upd[ut] = update(idx, arr[idx], val);
			arr[idx] = val;
			m[val];
		}
	}
	sort(qu, qu + qt, cmp);
	lli cnt = 0;
	for (auto &x : m) {
		x.second = cnt++;
	}
	for (int i = 1; i <= ut; ++i) {
		upd[i].prev = m[upd[i].prev];
		upd[i].curr = m[upd[i].curr];
	}
	for (int i = 1; i <= n; ++i) {
		arr[i] = m[tmp[i]];
	}
 
	solve();
	for (int i = 0; i < qt; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}