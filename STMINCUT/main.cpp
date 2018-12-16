/*input
3
2
0 0
1 0
3
0 0 3
1 0 1
2 0 0
4
0 0 2 2
1 0 2 0
0 3 0 3
2 4 0 0
*/

//
//  main.cpp
//  STMINCUT
//
//  Created by Nirmaljot Singh Bhasin on 22/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>
using namespace std;

typedef long long int lli;
const int MAXN = 1003;

lli A[MAXN][MAXN];
lli pa[MAXN], siz[MAXN], w[MAXN];
priority_queue< pair<lli, pair<lli, lli> > > pq;
lli vis[MAXN];
int n;

lli root(lli x) {
	while (pa[x] != x) {
		x = pa[x];
	}
	return x;
}

void uni(lli a, lli b, lli wt) {
	lli ra = root(a);
	lli rb = root(b);

	if (ra == rb) {
		return;
	}

	if (siz[ra] > siz[rb]) {
		pa[rb] = ra;
		w[rb] = wt;
	} else if (siz[ra] < siz[rb]) {
		pa[ra] = rb;
		w[ra] = wt;
	} else {
		pa[ra] = rb;
		w[ra] = wt;
		++siz[rb];
	}
}

lli connected(lli a, lli b) {
	lli ra = root(a);
	lli rb = root(b);

	if (ra != rb) {
		return -1;
	}

	lli da, db;
	da = db = 0;

	lli ta = a;
	lli tb = b;

	while (a != pa[a]) {
		++da;
		a = pa[a];
	}

	while (b != pa[b]) {
		++db;
		b = pa[b];
	}

	lli ret = LONG_MAX;
	a = ta;
	b = tb;

	if (da > db) {
		while (da != db) {
			ret = min(ret, w[a]);
			--da;
			a = pa[a];
		}
	} else if (da < db) {
		while (da != db) {
			ret = min(ret, w[b]);
			--db;
			b = pa[b];
		}
	}

	while (a != b) {
		ret = min(ret, w[a]);
		ret = min(ret, w[b]);
		a = pa[a];
		b = pa[b];
	}

	return ret;
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> A[i][j];
			}
			pa[i] = i;
			siz[i] = 1;
			w[i] = 0;
		}

		lli ans = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i != j) {
					pq.push({A[i][j], {i, j}});
				}
			}
		}

		while (!pq.empty()) {
			lli wt = pq.top().first;
			pair<lli, lli> edge = pq.top().second;
			pq.pop();
			lli st = connected(edge.first, edge.second);
			if (st != -1) {
				ans += (st - A[edge.first][edge.second]);
			} else {
				uni(edge.first, edge.second, wt);
			}
		}

		cout << ans << endl;
	}
	return 0;
}
