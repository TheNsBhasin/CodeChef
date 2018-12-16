/*input
4 5
1 1 2 3 1
3 1 2 5 2
5 2 1 5 6
1 3 1 2 1
*/

//
//  main.cpp
//  TWOFL
//
//  Created by Nirmaljot Singh Bhasin on 04/06/18.
//  Copyright Â© 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <memory.h>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

typedef long long int lli;

const int N = 2001;
const int MAXN = 4 * 1000001;

lli ROW[] = { 0, 0, 1,  -1};
lli COL[] = { -1, 1, 0, 0};

lli a[N][N], pa[N][N], vis[N][N];
lli group;
int n, m;

bool check(lli x, lli y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return 0;
	}
	return 1;
}

lli dfs(lli u, lli v, lli x, lli y) {
	if (a[u][v] != x && a[u][v] != y) {
		return 0;
	}
	vis[u][v] = 1;
	pa[u][v] = group;
	lli cnt = 1;
	for (int k = 0; k < 4; ++k) {
		lli X = u + ROW[k];
		lli Y = v + COL[k];
		if (check(X, Y) && pa[X][Y] != group) {
			cnt += dfs(X, Y, x, y);
		}
	}
	return cnt;
}

lli solve() {
	lli res = 1;
	group = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!vis[i][j]) {
				for (int k = 0; k < 4; ++k) {
					lli X = i + ROW[k];
					lli Y = j + COL[k];
					if (check(X, Y) && a[i][j] != a[X][Y]) {
						++group;
						lli cnt = dfs(i, j, a[i][j], a[X][Y]);
						res = max(res, cnt);
					}
				}
			}
		}
	}
	return res;
}

int main(int argc, const char * argv[]) {
	cin >> n >> m;
    bool flag = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
            if (a[i][j] != a[0][0]) {
                flag = false;
            }
		}
	}
    
    if (flag) {
        cout << n * m << endl;
        return 0;
    }

	lli ans = solve();
	cout << ans << endl;

	return 0;
}
