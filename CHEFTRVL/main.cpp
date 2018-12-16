/*input
1
3
1 2
1 3
1 2 3
*/

//
//  main.cpp
//  CHEFTRVL
//
//  Created by Nirmaljot Singh Bhasin on 20/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

vector<lli> adj[MAXN];
lli ans[2][2], age[MAXN];

void dfs(lli u, lli p, lli d) {
	++ans[d][__builtin_popcount(age[u]) & 1];
	for (auto &v : adj[u]) {
		if (v != p) {
			dfs(v, u, d ^ 1);
		}
	}
	return;
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < MAXN; ++i) {
			adj[i].clear();
		}
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				ans[i][j] = 0;
			}
		}
		for (int i = 1; i < n; ++i) {
			lli a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int i = 1; i <= n; ++i) {
			cin >> age[i];
		}

		dfs(1, 0, 0);

		cout << (ans[0][0] * ans[0][1]) + (ans[1][0] * ans[1][1]) + (ans[0][0] * ans[1][0]) + (ans[0][1] * ans[1][1]) << endl;
	}
	return 0;
}
