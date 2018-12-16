/*input
4
4
4 3 1 2
6
1 2 2 1 3 1
5
10 1 2 10 5
4
1 2 1 2
*/

//
//  main.cpp
//  CHSIGN
//
//  Created by Nirmaljot Singh Bhasin on 11/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

#define INF 999999999999999

typedef long long int lli;
const int MAXN = 1000006;

lli A[MAXN], ans[MAXN];
lli dp[MAXN][2], pp[MAXN][2];

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> A[i];
		}
		A[n] = INF;
		if (n == 2) {
			if (A[0] < A[1]) {
				ans[0] = -A[0];
				ans[1] = A[1];
			} else if (A[0] == A[1]) {
				ans[0] = A[0];
				ans[1] = A[1];
			} else {
				ans[0] = A[0];
				ans[1] = -A[1];
			}
			for (int i = 0; i < n; ++i) {
				cout << ans[i] << " ";
			}
			cout << endl;
			continue;
		}
		for (int i = 0; i <= n; ++i) {
			dp[i][0] = dp[i][1] = INF;
			pp[i][0] = pp[i][1] = -1;
		}

		dp[0][0] = A[0];
		dp[0][1] = -A[0];

		if (A[0] >= A[1]) {
			dp[0][1] = INF;
		}

		dp[1][0] = min(dp[0][0] , dp[0][1]) + A[1];
		pp[1][0] = (dp[0][0] < dp[0][1]) ? 0 : 1;

		dp[1][1] = dp[0][0] - A[1];
		dp[1][1] = (A[0] > A[1] && A[1] < A[2]) ? dp[0][0] - A[1] : INF;
		pp[1][1] = 0;

		for (int i = 2; i < n; ++i) {
			dp[i][0] = min(dp[i - 1][0] , dp[i - 1][1]) + A[i];
			pp[i][0] = (dp[i - 1][0] < dp[i - 1][1]) ? 0 : 1;
			if (A[i - 1] > A[i] && A[i] < A[i + 1]) {
				lli op1, op2;
				op1 = op2 = INF;
				if (A[i - 1] - A[i - 2] - A[i] > 0) {
					op1 = dp[i - 2][1] + A[i - 1] - A[i];
				}
				op2 = dp[i - 2][0] + A[i - 1] - A[i];
				dp[i][1] = min(op1, op2);
				pp[i][1] = (op1 < op2) ? 1 : 0;
			}
		}

		lli s = (dp[n - 1][0] < dp[n - 1][1]) ? 0 : 1;
		int i = n - 1;

		while (i >= 0) {
			lli cur = A[i];
			if (s == 1) {
				cur *= -1;
			}
			ans[i] = cur;
			if (i == 0) {
				break;
			}
			lli tmp = pp[i][s];
			if (s == 1) {
				ans[i - 1] = A[i - 1];
				--i;
			}
			s = tmp;
			--i;
		}

		for (int i = 0; i < n; ++i) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
