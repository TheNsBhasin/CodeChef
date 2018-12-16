/*input
4
1 2 3 4
*/

//
//  main.cpp
//  COPRIME3
//
//  Created by Nirmaljot Singh Bhasin on 04/03/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 1000006;

lli arr[MAXN], p[MAXN], dp[MAXN];

void preprocess() {
	for (int i = 2; i < MAXN; ++i) {
		if (!p[i]) {
			for (int j = i; j < MAXN; j += i) {
				if (!p[j]) {
					p[j] = i;
				}
			}
		}
	}
}

int main(int argc, const char * argv[]) {
	preprocess();
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		lli x;
		cin >> x;
		++arr[x];
	}
	lli ans = 0;
	for (int i = 1; i < MAXN; ++i) {
		if (i == 1) {
			dp[i] = 1;
		} else {
			if (p[i / p[i]] == p[i]) {
				dp[i] = 0;
			} else {
				dp[i] = -1 * dp[i / p[i]];
			}
		}
		if (!dp[i]) {
			continue;
		}
		lli val = 0;
		for (int j = i; j < MAXN; j += i) {
			val += arr[j];
		}
		ans += (val * (val - 1) * (val - 2)  / 6) * dp[i];
	}
	cout << ans << endl;
	return 0;
}
