/*input
3
10 1 1
9 1 5
1000000 999999 999999
*/

//
//  main.cpp
//  GCDMOD
//
//  Created by Nirmaljot Singh Bhasin on 06/08/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;
const int MOD = 1e9 + 7;

lli power(lli a, lli n, lli mod) {
	lli res = 1;
	while (n > 0) {
		if (n & 1) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		n = n >> 1;
	}
	return res % mod;
}

lli gcd(lli a, lli b) {
	if (b == 0) {
		return a % MOD;
	}
	return gcd(b, a % b) % MOD;
}

int main(int argc, const char * argv[]) {
	lli t;
	cin >> t;
	while (t--) {
		lli a, b, n;
		cin >> a >> b >> n;

		lli res = 0;

		if (a == b) {
			res = (power(a, n, MOD) % MOD) + (power(b, n, MOD) % MOD) % MOD;
		} else {
			lli an = power(a, n, a - b);
			lli bn = power(b, n, a - b);
			res = gcd((an + bn) % (a - b), a - b) % MOD;
		}
		cout << res % MOD << endl;
	}
	return 0;
}
