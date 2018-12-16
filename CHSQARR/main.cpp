/*input
3 4
1 8 3 4
5 2 3 1
3 6 2 2
4
1 1
2 2
2 3
3 2
*/
 
//
//  main.cpp
//  CHSQARR
//
//  Created by Nirmaljot Singh Bhasin on 21/12/17.
//  Copyright Â© 2017 Nirmaljot Singh Bhasin. All rights reserved.
//
 
#include <iostream>
#include <queue>
#include <climits>
using namespace std;
 
typedef long long int lli;
 
int main(int argc, const char * argv[]) {
	int n, m;
	cin >> n >> m;
	lli arr[n + 1][m + 1], sum[n + 1][m + 1], maxCol[n + 1][m + 1], max[n + 1][m + 1];
 
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			sum[i][j] = maxCol[i][j] = max[i][j] = 0;
		}
	}
 
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> arr[i][j];
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + arr[i][j];
		}
	}
 
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
 
		deque<lli> q[m + 1];
 
		for (int i = 1; i <= a; ++i) {
			for (int j = 1; j <= m; ++j) {
				while (!q[j].empty() && q[j].back() < arr[i][j]) {
					q[j].pop_back();
				}
				q[j].push_back(arr[i][j]);
			}
		}
 
		for (int i = a; i <= n; ++i) {
			deque<lli> tmp;
			for (int j = 1; j <= b; ++j) {
				while (!tmp.empty() && tmp.back() < q[j].front()) {
					tmp.pop_back();
				}
				tmp.push_back(q[j].front());
			}
 
			for (int j = b; j <= m; ++j) {
				max[i][j] = tmp.front();
 
				if (tmp.front() == q[j - b + 1].front()) {
					tmp.pop_front();
				}
				if (j + 1 <= m) {
					while (!tmp.empty() && tmp.back() < q[j + 1].front()) {
						tmp.pop_back();
					}
					tmp.push_back(q[j + 1].front());
				}
			}
 
			for (int j = 1; j <= m; ++j) {
				if (q[j].front() == arr[i - a + 1][j]) {
					q[j].pop_front();
				}
			}
 
			if (i + 1 <= n) {
				for (int j = 1; j <= m; ++j) {
					while (!q[j].empty() && q[j].back() < arr[i + 1][j]) {
						q[j].pop_back();
					}
					q[j].push_back(arr[i + 1][j]);
				}
			}
		}
 
		lli ans = LONG_MAX;
 
		for (int i = a; i <= n; ++i) {
			for (int j = b; j <= m; ++j) {
				ans =  min(ans, (max[i][j] * a * b) - (sum[i][j] - sum[i - a][j] - sum[i][j - b] + sum[i - a][j - b]));
			}
		}
 
		cout << ans << endl;
	}
	return 0;
}