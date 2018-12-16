/*input
3
3
10 11 12
2 1 3
1 1 3
2 1 3
*/

//
//  main.cpp
//  PRIMECLO
//
//  Created by Nirmaljot Singh Bhasin on 27/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>
#include <memory.h>
#include <limits.h>
using namespace std;

typedef long long int lli;
const int N = 1000000;
const int MAXN = 110100;
const lli MOD = 1000000007;

lli a[MAXN], seg[MAXN], lesser_prime[MAXN], lesser_big_prime[MAXN];
lli lp[N + 1];
vector<lli> prime;
pair<lli, lli> tree[MAXN * 4];
lli maxi, mini;

void sieve() {
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() && prime[j] <= lp[i] && i * prime[j] <= N; ++j) {
			lp[i * prime[j]] = prime[j];
		}
	}
}

void seg_sieve(lli lo, lli hi) {
	for (int i = 0; i < prime.size(); ++i) {
		if (prime[i] * prime[i] > maxi) {
			break;
		}
		lli x = ((lo + prime[i] - 1) / prime[i]) * prime[i];
		while (x <= lo) {
			seg[x - lo] = 0;
			x += prime[i];
		}
	}
	lli cur = 0;
	for (int i = 0; i < hi - lo + 1; ++i) {
		lesser_big_prime[i] = cur;
		if (seg[i] == 1) {
			cur = i + lo;
		}
	}
}

lli compute(lli x) {
	if (x < MAXN) {
		return lesser_prime[x];
	} else {
		return lesser_big_prime[x - mini];
	}
}

pair<lli, lli> combine(pair<lli, lli> a, pair<lli, lli> b) {
	pair<lli, lli> ans;
	ans.first = a.first + b.first;
	ans.second = a.second & b.second;
	return ans;
}

void build(lli node, lli l, lli r) {
	if (l == r) {
		tree[node].first = a[l];
		tree[node].second = a[l] < 3;
		return;
	}
	lli mid = l + ((r - l) >> 1);
	build(node << 1, l, mid);
	build(node << 1 | 1, mid + 1, r);
	tree[node] = combine(tree[node << 1], tree[node << 1 | 1]);
}

void update(lli node, lli l, lli r, lli lo, lli hi) {
	if (l > r || lo > r || l > hi || tree[node].second) {
		return;
	}
	if (l == r) {
		tree[node].first -= compute(tree[node].first);
		if (tree[node].first < 3) {
			tree[node].second = 1;
		}
		return;
	}
	lli mid = l + ((r - l) >> 1);
	update(node << 1, l, mid, lo, hi);
	update(node << 1 | 1, mid + 1, r, lo, hi);
	tree[node] = combine(tree[node << 1], tree[node << 1 | 1]);
}

lli query(lli node, lli l, lli r, lli lo, lli hi) {
	if (l > r || l > hi || lo > r) {
		return 0;
	}
	if (lo <= l && r <= hi) {
		return tree[node].first;
	}
	lli mid = l + ((r - l) >> 1);
	return query(node << 1, l, mid, lo, hi) + query(node << 1 | 1, mid + 1, r, lo, hi);
}

int main(int argc, const char * argv[]) {
	for (int i = 0; i < MAXN; ++i) {
		seg[i] = 1;
	}
	sieve();
	lesser_prime[0] = lesser_prime[1] = lesser_prime[2] = 0;
	int cur = 2;
	for (int i = 3; i < MAXN; i++) {
		lesser_prime[i] = cur;
		if (lp[i] == i) {
			cur = i;
		}
	}
	int n, q;
	cin >> n >> q;
	mini = MOD * MOD;
	maxi = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mini = min(mini, a[i]);
		maxi = max(maxi, a[i]);
	}
	mini = max(1LL, mini - 500LL);
	seg_sieve(mini, maxi);

	build(1, 0, n - 1);
	for (int i = 0; i < q; ++i) {
		lli ty, l, r;
		cin >> ty >> l >> r;
		--l;
		--r;
		if (ty == 1) {
			update(1, 0, n - 1, l, r);
		} else {
			cout << query(1, 0, n - 1, l, r) << endl;
		}
	}
	return 0;
}
