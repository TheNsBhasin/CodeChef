/*input
8 5
3 5 1 4 6 9 12 6
3 6 2
3 6 4
4 8 3
2 6 7
8 8 6
*/

//
//  main.cpp
//  DIVQUERY
//
//  Created by Nirmaljot Singh Bhasin on 04/03/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli arr[MAXN], ans[MAXN];
vector <lli> divs[MAXN], bucket[MAXN];
vector < pair<lli, pair<lli, lli> > > qs[MAXN];
lli tree[MAXN];

lli read(lli idx) {
	lli val = 0;
	while (idx > 0) {
		val += tree[idx];
		idx -= (idx & -idx);
	}
	return val;
}

void update(lli idx, lli val) {
	while (idx < MAXN) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

void preprocess() {
	for (int i = 1; i < MAXN; ++i) {
		for (int j = i; j < MAXN; j += i) {
			divs[j].push_back(i);
		}
	}
}

int main(int argc, const char * argv[]) {
	preprocess();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		for (int j = 0; j < divs[arr[i]].size(); ++j) {
			bucket[divs[arr[i]][j]].push_back(i);
		}
	}
	for (int i = 0; i < q; ++i) {
		lli l, r, m;
		cin >> l >> r >> m;
		qs[m].push_back({i, {l, r}});
	}
	for (int i = 1; i < MAXN; ++i) {
		for (int j = 0; j < bucket[i].size(); ++j) {
			update(bucket[i][j], +1);
		}
		for (int j = 0; j < qs[i].size(); ++j) {
			lli idx = qs[i][j].first;
			lli l = (qs[i][j].second).first;
			lli r = (qs[i][j].second).second;

			ans[idx] = read(r) - read(l - 1);
		}
		for (int j = 0; j < bucket[i].size(); ++j) {
			update(bucket[i][j], -1);
		}
	}
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
