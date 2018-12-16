/*input
4
2 3 4 5
3
2 1 4 2
1 2 6
2 1 4 2
*/

//
//  main.cpp
//  GCDCNT
//
//  Created by Nirmaljot Singh Bhasin on 04/03/18.
//  Copyright Â© 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli spf[MAXN];
vector<lli> pf[MAXN], v[MAXN], idx[MAXN];

void sieve() {
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		if (!spf[i]) {
			spf[i] = i;
			for (int j = i; j < MAXN; j += i) {
				spf[j] = i;
				pf[j].push_back(i);
			}
		}
	}
}

int main(int argc, const char * argv[]) {
	sieve();
	int n, q;
	cin >> n;
	lli arr[n];
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		idx[arr[i]].push_back(i);
		v[arr[i]].push_back(i);
	}

	for (int i = 2; i < MAXN; ++i) {
		for (int j = (i << 1); j < MAXN; j += i) {
			for (int k = 0; k < v[j].size(); ++k) {
				idx[i].push_back(v[j][k]);
			}
		}
	}

	for (int i = 0; i < MAXN; ++i) {
		sort(idx[i].begin(), idx[i].end());
	}

	cin >> q;
	while (q--) {
		int ty;
		cin >> ty;
		if (ty == 1) {
			lli x, y;
			cin >> x >> y;

			lli siz = (1 << pf[arr[x]].size());
			for (int mask = 0; mask < siz; ++mask) {
				lli prod = 1;
				lli total = 0;
				for (int j = 0; j < pf[arr[x]].size(); ++j) {
					if (mask & (1 << j)) {
						prod *= pf[arr[x]][j];
						++total;
					}
				}
				if (!total) {
					continue;
				}

				if (binary_search(idx[prod].begin(), idx[prod].end(), x)) {
					idx[prod].erase(lower_bound(idx[prod].begin(), idx[prod].end(), x));
				}
			}

			siz = (1 << pf[y].size());
			for (int mask = 0; mask < siz; ++mask) {
				lli prod = 1;
				lli total = 0;
				for (int j = 0; j < pf[y].size(); ++j) {
					if (mask & (1 << j)) {
						prod *= pf[y][j];
						++total;
					}
				}
				if (!total) {
					continue;
				}

				if (!binary_search(idx[prod].begin(), idx[prod].end(), x)) {
					idx[prod].insert(lower_bound(idx[prod].begin(), idx[prod].end(), x), x);
				}
			}
			arr[x] = y;
		} else {
			lli l, r, g;
			cin >> l >> r >> g;
			lli siz = (1 << pf[g].size());
			lli ans = 0;
			for (int mask = 0; mask < siz; ++mask) {
				lli prod = 1;
				lli total = 0;
				for (int j = 0; j < pf[g].size(); ++j) {
					if (mask & (1 << j)) {
						prod *= pf[g][j];
						++total;
					}
				}
				if (!total) {
					continue;
				}

				lli low = lower_bound(idx[prod].begin(), idx[prod].end(), l) - idx[prod].begin();
				lli high = upper_bound(idx[prod].begin(), idx[prod].end(), r) - idx[prod].begin();

				lli cnt = high - low;

				if (total & 1) {
					ans += cnt;
				} else {
					ans -= cnt;
				}
			}
			cout << (r - l + 1) - ans << endl;
		}
	}
	return 0;
}