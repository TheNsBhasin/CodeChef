/*input
2
4
4 3 2 1
5
1 2 2 3 1
*/

//
//  main.cpp
//  MINVOTE
//
//  Created by Nirmaljot Singh Bhasin on 02/03/18.
//  Copyright Â© 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli arr[MAXN], L[MAXN], R[MAXN];
lli lower[MAXN], upper[MAXN];
lli st[MAXN], en[MAXN];
lli ans[MAXN];

void solve(lli idx, lli low1, lli high1, lli low2, lli high2) {
	while (low1 <= high1 || low2 <= high2) {
		if (low1 <= high1) {
			lli mid1 = low1 + ((high1 - low1) >> 1);
			if (arr[idx] >= R[idx] - L[mid1]) {
				lower[idx] = mid1;
				high1 = mid1 - 1;
			} else {
				low1 = mid1 + 1;
			}
		}
		if (low2 <= high2) {
			lli mid2 = low2 + ((high2 - low2) >> 1);
			if (arr[idx] >= R[mid2] - L[idx]) {
				upper[idx] = mid2;
				low2 = mid2 + 1;
			} else {
				high2 = mid2 - 1;
			}
		}
	}
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			lower[i] = upper[i] = -1;
			st[i] = en[i] = 0;
			cin >> arr[i];
			L[i] = (i > 0 ? L[i - 1] : 0) + arr[i];
			R[i + 1] = R[i] + arr[i];
		}
		for (int i = 0; i < n; ++i) {
			solve(i, 0, i - 1, i + 1, n - 1);
			for (int j = lower[i]; j <= upper[i]; ++j) {
				if (j != i) {
					++ans[j];
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			if (lower[i] != -1) {
				++st[lower[i]];
			}
		}
		for (int i = 0; i < n; ++i) {
			if (upper[i] != -1) {
				++en[upper[i]];
			}
		}
		lli cnt = 0;
		for (int i = 0; i < n; ++i) {
			cnt += st[i];
			cout << cnt << " ";
			cnt -= en[i];
		}
		cout << endl;
	}
	return 0;
}