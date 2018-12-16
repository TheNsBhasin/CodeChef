/*input
2
5
4 5
3 5
2 4
1 3
5 5
2
4 1 2 3 4
1 4
5
4 5
3 5
2 4
2 3
5 5
2
2 2 5
3 1 2 5
*/

//
//  main.cpp
//  CHANOQ
//
//  Created by Nirmaljot Singh Bhasin on 03/02/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;
const int BLOCK = 316;

struct seg {
	lli L, R;
	lli idx;
};

bool cmp(seg& x, seg& y) {
	if (x.L / BLOCK != y.L / BLOCK) {
		return x.L / BLOCK < y.L / BLOCK;
	}
	return x.R < y.R;
}

vector<lli> pnt[MAXN];

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < MAXN; ++i) {
			pnt[i].clear();
		}
		int n, q;
		cin >> n;
		seg s[n];
		for (int i = 0; i < n; ++i) {
			s[i].idx = i;
			cin >> s[i].L >> s[i].R;
		}
		sort(s, s + n, cmp);
		cin >> q;
		for (int i = 0; i < q; ++i) {
			lli m;
			cin >> m;
			for (int j = 0; j < m; ++j) {
				lli x;
				cin >> x;
				pnt[x].push_back(i);
			}
		}
		vector<lli> ans[q];
		lli st = s[0].L;
		lli ed = st;
		for (int i = 0; i < pnt[st].size(); ++i) {
			if (ans[pnt[st][i]].size() >= 1) {
				ans[pnt[st][i]].pop_back();
			} else {
				ans[pnt[st][i]].push_back(0);
			}
		}

		for (int i = 0; i < n; ++i) {
			while (ed < s[i].R) {
				++ed;
				for (int j = 0; j < pnt[ed].size(); ++j) {
					if (ans[pnt[ed][j]].size() >= 1) {
						lli idx = ans[pnt[ed][j]].back();
						if (idx == i) {
							ans[pnt[ed][j]].pop_back();
						} else {
							ans[pnt[ed][j]].push_back(i);
						}
					} else {
						ans[pnt[ed][j]].push_back(i);
					}
				}
			}
			while (st > s[i].L) {
				--st;
				for (int j = 0; j < pnt[st].size(); ++j) {
					if (ans[pnt[st][j]].size() >= 1) {
						lli idx = ans[pnt[st][j]].back();
						if (idx == i) {
							ans[pnt[st][j]].pop_back();
						} else {
							ans[pnt[st][j]].push_back(i);
						}
					} else {
						ans[pnt[st][j]].push_back(i);
					}
				}
			}
			while (ed > s[i].R) {
				for (int j = 0; j < pnt[ed].size(); ++j) {
					if (ans[pnt[ed][j]].size() >= 1) {
						lli idx = ans[pnt[ed][j]].back();
						if (idx == i) {
							ans[pnt[ed][j]].pop_back();
						} else {
							ans[pnt[ed][j]].push_back(i);
						}
					} else {
						ans[pnt[ed][j]].push_back(i);
					}
				}
				--ed;
			}
			while (st < s[i].L) {
				for (int j = 0; j < pnt[st].size(); ++j) {
					if (ans[pnt[st][j]].size() >= 1) {
						lli idx = ans[pnt[st][j]].back();
						if (idx == i) {
							ans[pnt[st][j]].pop_back();
						} else {
							ans[pnt[st][j]].push_back(i);
						}
					} else {
						ans[pnt[st][j]].push_back(i);
					}
				}
				++st;
			}
		}

		for (int i = 0; i < q; ++i) {
			ans[i].push_back(n);
			lli sum = 0;
			for (int j = 0; j < ans[i].size() - 1; j += 2) {
				sum += ans[i][j + 1] - ans[i][j];
			}
			cout << sum << endl;
		}
	}
	return 0;
}
