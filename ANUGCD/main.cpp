/*input
6 5
1 2 3 4 5 4
2 1 5
121 1 6
3 2 6
5 5 5
24 4 6
*/

//
//  main.cpp
//  ANUGCD
//
//  Created by Nirmaljot Singh Bhasin on 04/03/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;
const int SEGN = 2400005;

lli arr[MAXN], st[MAXN], en[MAXN];
bool mark[MAXN];
vector<lli> pf[MAXN], v[MAXN];
vector<lli> Z;
pair<lli, lli> tree[SEGN];

void preprocess() {
	for (int i = 2; i < MAXN; i++) {
		if (!mark[i]) {
			for (int j = i; j < MAXN; j += i) {
				pf[j].push_back(i);
				mark[j] = true;
			}
		}
	}
}

pair<lli, lli> build(lli at, lli L, lli R) {
	if (L == R) {
		tree[at] = {arr[Z[L]], 1};
		return tree[at];
	}

	lli mid = L + ((R - L) >> 1);
	pair<lli, lli> left = build((at << 1), L, mid);
	pair<lli, lli> right = build((at << 1) ^ 1, mid + 1, R);

	if (left.first > right.first) {
		tree[at] = left;
	} else if (right.first > left.first) {
		tree[at] = right;
	} else {
		tree[at] = {left.first, left.second + right.second};
	}
	return tree[at];
}

pair<lli, lli> query(lli at, lli L, lli R, lli l, lli r) {
	if (r < L || R < l) {
		return { -1, -1};
	}
	if (l <= L && R <= r) {
		return tree[at];
	}

	lli mid = L + ((R - L) >> 1);
	pair<lli, lli> left = query((at << 1), L, mid, l, r);
	pair<lli, lli> right = query((at << 1) ^ 1, mid + 1, R, l, r);

	if (left.first == -1) {
		return right;
	}
	if (right.first == -1) {
		return left;
	}

	if (left.first > right.first) {
		return left;
	}
	if (right.first > left.first) {
		return right;
	}

	return {left.first, left.second + right.second};
}

int main(int argc, const char * argv[]) {
	preprocess();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		for (int j = 0; j < pf[arr[i]].size(); ++j) {
			v[pf[arr[i]][j]].push_back(i);
		}
	}
	for (int i = 2; i < MAXN; ++i) {
		st[i] = Z.size();
		for (int j = 0; j < v[i].size(); ++j) {
			Z.push_back(v[i][j]);
		}
		en[i] = Z.size() - 1;
	}

	build(1, 0, Z.size() - 1);

	for (int i = 0; i < m; ++i) {
		lli g, x, y;
		cin >> g >> x >> y;
		--x; --y;
		pair<lli, lli> ans(-1, -1);
		for (int j = 0; j < pf[g].size(); ++j) {
			if (st[pf[g][j]] > en[pf[g][j]]) {
				continue;
			}

			lli l = lower_bound(v[pf[g][j]].begin(), v[pf[g][j]].end(), x) - v[pf[g][j]].begin();
			lli r = upper_bound(v[pf[g][j]].begin(), v[pf[g][j]].end(), y) - v[pf[g][j]].begin();
			l += st[pf[g][j]];
			r += st[pf[g][j]];
			if (l > r - 1) {
				continue;
			}
			pair<lli, lli> now = query(1, 0, Z.size() - 1, l, r - 1);
			if (now.first > ans.first) {
				ans = now;
			}
		}
		cout << ans.first << " " << ans.second << endl;
	}
	return 0;
}
