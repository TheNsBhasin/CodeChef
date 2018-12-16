/*input
1
999 999
*/

//
//  main.cpp
//  DSERIES
//
//  Created by Nirmaljot Singh Bhasin on 27/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 1003;
const int MOD = 1000000007;

lli cum_prod[MAXN], inv[MAXN];

lli f(lli n, lli r) {
	lli res = 1;
	for (int i = 0; i <= r; ++i) {
		res = (res * ((n + i) % MOD)) % MOD;
	}
	res = (res * inv[r + 1]) % MOD;
	return res;
}

int main(int argc, const char * argv[]) {
	cum_prod[0] = cum_prod[1] = 1;
	for (int i = 2; i < MAXN; ++i) {
		cum_prod[i] = (cum_prod[i - 1] * i) % MOD;
	}
	inv[1] = 1;
	for (int i = 2; i < MAXN; ++i) {
		inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
	}
	int q;
	cin >> q;
	while (q--) {
		lli n, t;
		cin >> n >> t;
		lli ans = f(n + 1, t) % MOD;
		ans = (MOD + ans - cum_prod[t]) % MOD;
		cout << ans << endl;
	}
	return 0;
}
