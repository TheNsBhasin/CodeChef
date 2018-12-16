/*input
2
2 2 4
2 2
1 1
10 10 10
10 10
10 10
*/

//
//  main.cpp
//  ABX02
//
//  Created by Nirmaljot Singh Bhasin on 30/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long int lli;
const int MOD = 1e9 + 7;

lli P, Q, N;
lli B1, B2;
lli S1, S2;
unordered_map<lli, lli> dp;

lli solve(lli N, lli P, lli Q, lli B1, lli B2, lli prev) {
	if (N == 0) {
		return 1;
	}
	if (N < 0) {
		return 0;
	}
	if (dp.count((B2 + 201 * (B1 + 201 * ( Q + 201 * (P + 201 * (N))))) * 2 + prev % 2) != 0) {
		return dp[(B2 + 201 * (B1 + 201 * ( Q + 201 * (P + 201 * (N))))) * 2 + prev % 2] % MOD;
	}
	lli ans = 0;
	if (prev == 1) {
		if (B2 > 0) {
			for (int i = 1; i <= min(Q, S2); ++i) {
				ans = (ans + solve(N - i, P, Q - i, B1, B2 - 1, 2)) % MOD;
			}
		}
	} else {
		if (B1 > 0) {
			for (int i = 1; i <= min(P, S1); ++i) {
				ans = (ans + solve(N - i, P - i, Q, B1 - 1, B2, 1)) % MOD;
			}
		}
	}
	dp[(B2 + 201 * (B1 + 201 * ( Q + 201 * (P + 201 * (N))))) * 2 + prev % 2] = ans % MOD;
	return ans;
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		dp.clear();
		cin >> P >> Q >> N;
		cin >> B1 >> B2;
		cin >> S1 >> S2;
		lli ans = (solve(N, P, Q, B1, B2, 1) + solve(N, P, Q, B1, B2, 2)) % MOD;
		cout << ans << endl;
	}
	return 0;
}
