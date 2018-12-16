/*input
1
3
1 2 3
4 5 6
7 8 9
*/

//
//  main.cpp
//  MAXSC
//
//  Created by Nirmaljot Singh Bhasin on 05/01/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 701;

vector<lli> arr[MAXN];

int bs(int idx, int low, int high, lli val) {
	int l = low;
	int h = high;
	while (l <= h) {
		int m = l + ((h - l) >> 1);
		if (arr[idx][m] >= val) {
			h = m - 1;
		} else {
			l = m + 1;
		}
	}
	if (l >= low && l <= high && arr[idx][l] >= val) {
		--l;
	}
	return l;
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			arr[i].clear();
			for (int j = 0; j < n; ++j) {
				lli x;
				cin >> x;
				arr[i].push_back(x);
			}
			sort(arr[i].begin(), arr[i].end());
		}
		lli maxi = arr[n - 1][n - 1];
		lli sum = maxi;
		for (int i = n - 2; i >= 0 ; --i) {
			int idx = bs(i, 0, n - 1, maxi);
			if (idx < 0) {
				sum = -1;
				break;
			} else if (idx >= n) {
				idx = n - 1;
			}
			maxi = arr[i][idx];
			sum += maxi;
		}
		cout << sum << endl;
	}
	return 0;
}
