/*input
1
7 2
12 90 4 18 100 70 90
5 2
*/

//
//  main.cpp
//  INTERVAL
//
//  Created by Nirmaljot Singh Bhasin on 20/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		lli A[n + 1], B[m + 1], prefix_sum[n + 1], dp[n + 1];
		prefix_sum[0] = dp[0] = 0;

		for (int i = 1; i <= n; ++i) {
			cin >> A[i];
			prefix_sum[i] = prefix_sum[i - 1] + A[i];
			dp[i] = 0;
		}

		for (int j = 1; j <= m; ++j) {
			cin >> B[j];
		}

		for (int i = 1; i + B[m] - 1 <= n; ++i) {
			dp[i] = prefix_sum[i + B[m] - 1] - prefix_sum[i - 1];
		}

		for (int i = m - 1; i >= 1; --i) {
			deque<int> q;
			int k;
			int siz = B[i] - B[i + 1] + i;

			for (k = i + 1; k < siz; ++k) {
				while (!q.empty() && dp[k] > dp[q.back()]) {
					q.pop_back();
				}
				q.push_back(k);
			}

			for (int j = 1; j + B[i] - 1 <= n; ++j) {
				lli tmp = (prefix_sum[j + B[i] - 1] - prefix_sum[j - 1]) - dp[q.front()];

				while (!q.empty() && q.front() <= j + 1) {
					q.pop_front();
				}

				while (!q.empty() && dp[k] >= dp[q.back()]) {
					q.pop_back();
				}

				q.push_back(k++);
				dp[j] = tmp;
			}
		}

		lli ans = 0;

		for (int i = 1; i + B[1] - 1 <= n; ++i) {
			ans = max(ans, dp[i]);
		}

		cout << ans << endl;
	}
	return 0;
}
