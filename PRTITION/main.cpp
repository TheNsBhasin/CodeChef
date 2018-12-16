/*input
3
2 4
5 5
1 2
*/

//
//  main.cpp
//  PRTITION
//
//  Created by Nirmaljot Singh Bhasin on 06/01/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <memory.h>
using namespace std;

typedef long long int lli;
const int MAXN = 1000006;

lli subset[MAXN];
lli sumLeft[2];

bool subsetSum(lli n, lli x) {
	if (!sumLeft[0] && !sumLeft[1]) {
		return true;
	}

	if (n <= 0) {
		return false;
	}

	bool res = false;

	for (int i = 0; i < 2; ++i) {
		if (!res && (sumLeft[i] - n) >= 0) {
			subset[n] = i;
			sumLeft[i] -= n;
			if (n - 1 == x) {
				res = subsetSum(n - 2, x);
			} else {
				res = subsetSum(n - 1, x);
			}
			sumLeft[i] += n;
		}
	}

	return res;
}

void solve(lli n, lli x) {
	lli sum = (n * (n + 1)) >> 1;
	sum -= x;
	if (sum & 1) {
		cout << "impossible" << endl;
		return;
	}
	lli half = sum >> 1;
	memset(subset, -1, sizeof(subset));
	sumLeft[0] = sumLeft[1] = half;

	subset[x] = 2;
	bool res;
	if (n == x) {
		res = subsetSum(n - 1, x);
	} else {
		res = subsetSum(n, x);
	}

	if (!res) {
		cout << "impossible" << endl;
		return;
	}

	for (int i = 1; i <= n; ++i) {
		cout << subset[i];
	}
	cout << endl;
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli x, n;
		cin >> x >> n;
		lli sum = (n * (n + 1)) >> 1;
		sum -= x;
		if (sum & 1) {
			cout << "impossible" << endl;
		} else {
			solve(n, x);
		}
	}
	return 0;
}
