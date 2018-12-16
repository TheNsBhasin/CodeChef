/*input
2
5 3
2 4 6 8 9
1 1 3
2 2 56
1 1 3
7 6
20 8 50 16 22 23 29
1 1 6
2 2 18
1 1 4
2 6 10
2 5 11
1 5 6
*/

//
//  main.cpp
//  KRILLIN
//
//  Created by Nirmaljot Singh Bhasin on 12/06/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <utility>
#include <math.h>
#define F first
#define S second
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli a[MAXN];
pair<lli, lli> tree[4 * MAXN];
int n;

lli max(lli x, lli y) {
	if (a[x] > a[y]) {
		return x;
	}
	return y;
}

void combine(lli p) {
	tree[p].F = tree[p << 1].F + tree[p << 1 | 1].F;
	tree[p].S = max(tree[p << 1].S, tree[p << 1 | 1].S);
}

void build(lli p, lli l, lli r) {
	if (l == r) {
		tree[p] = {a[l], l};
		return;
	}
	lli m = l + ((r - l) >> 1);
	build(p << 1, l, m);
	build(p << 1 | 1, m + 1, r);
	combine(p);
}

void modify(lli p, lli l, lli r, lli x, lli v) {
	if (x < l or x > r) {
		return;
	}
	if (l == r) {
		tree[p] = {v, l};
		return;
	}
	lli m = l + ((r - l) >> 1);
	modify(p << 1, l, m, x, v);
	modify(p << 1 | 1, m + 1, r, x, v);
	combine(p);
}

pair<lli, lli> query(lli p, lli l, lli r, lli a, lli b) {
	if (a > b or r<a or l>b) {
		return {0, 0};
	}
	if (l >= a and r <= b) {
		return tree[p];
	}
	lli m = l + ((r - l) >> 1);
	auto q1 = query(p << 1, l, m, a, b);
	auto q2 = query(p << 1 | 1, m + 1, r, a, b);
	return {q1.F + q2.F, max(q1.S, q2.S)};
}

lli get(lli p, lli l, lli r, lli x) {
	if (l == r) {
		return l;
	}
	lli m = l + ((r - l) >> 1);
	if (tree[p << 1].F >= x) {
		return get(p << 1, l, m, x);
	}
	return get(p << 1 | 1, m + 1, r, x - tree[p << 1].F);
}

lli gcd(lli a, lli b) {
	if (a % b == 0) {
		return b;
	} else {
		return gcd(b, a % b);
	}
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int q;
		cin >> n >> q;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		build(1, 1, n);
		for (int i = 0; i < q; ++i) {
			lli ty;
			cin >> ty;
			if (ty == 1) {
				lli l, r;
				cin >> l >> r;
				auto q1 = query(1, 1, n, l, r);
				auto q2 = query(1, 1, n, 0, l - 1);
				lli mode = q1.S;
				lli median = 0;
				if (q1.F & 1) {
					median = get(1, 1, n, q2.F + ((q1.F + 1) >> 1));
				} else {
					median = (get(1, 1, n, q2.F + (q1.F >> 1)) + get(1, 1, n, q2.F + (q1.F >> 1) + 1)) >> 1;
				}
				lli g = gcd(median, mode);
				cout << (median * mode) / g << endl;
			} else {
				lli idx, val;
				cin >> idx >> val;
				a[idx] = val;
				modify(1, 1, n, idx, val);
			}
		}
	}
	return 0;
}
