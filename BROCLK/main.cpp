/*input
3
4 2 1
4 2 2
4 2 3
*/

//
//  main.cpp
//  BROCLK
//
//  Created by Nirmaljot Singh Bhasin on 02/02/18.
//  Copyright Â© 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long int lli;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

unordered_map<lli, lli> m;

lli power(lli a, lli n) {
	lli res = 1;
	while (n > 0) {
		if (n & 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		n = n >> 1;
	}
	return res % MOD;
}

lli solve(lli n) {
	if (m.count(n) != 0) {
		return m[n];
	}
	lli a = n >> 1;
	lli b = a;
	if (n & 1) {
		a = (n + 1) >> 1;
	}
	lli cosA = solve(a) % MOD;
	lli cosB = solve(b) % MOD;
	lli cosAminusB = solve(a - b) % MOD;
	lli tmp = (((cosA * cosB) % MOD) << 1) % MOD;
	m[n] = (MOD + tmp - cosAminusB) % MOD;
	return m[n];
}

int main(int argc, const char * argv[]) {
	int T;
	cin >> T;
	while (T--) {
		m.clear();
		lli l, d, t;
		cin >> l >> d >> t;
		m[0] = 1;
		m[1] = ((d % MOD) * power(l, MOD - 2)) % MOD;
		m[2] = (((MOD + ((power(d, 2) << 1) % MOD) - power(l, 2)) % MOD) * power(power(l, 2), MOD - 2)) % MOD;
		lli ans = solve(t);
		cout << (l * ans) % MOD << endl;
	}
	return 0;
}