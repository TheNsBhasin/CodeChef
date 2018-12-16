/*input
1
5 18
45 23 47 12 19
102 14 25 63 12
*/

//
//  main.cpp
//  DBFB
//
//  Created by Nirmaljot Singh Bhasin on 11/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;
const int MOD = 1e9 + 7;

lli A[MAXN], B[MAXN], fib[MAXN];

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli n, m;
		cin >> m >> n;
		A[0] = B[0] = 0;
		lli sum1 = 0, sum2 = 0;
		for (int i = 1; i <= m; ++i) {
			cin >> A[i];
			sum1 = (sum1 + A[i]) % MOD;
		}
		for (int i = 1; i <= m; ++i) {
			cin >> B[i];
			sum2 = (sum2 + B[i]) % MOD;
		}
		// lli res = 0;
		// for (int i = 1; i <= m; ++i) {
		// 	for (int j = 1; j <= m; ++j) {
		// 		fib[1] = A[i];
		// 		fib[2] = B[j];
		// 		for (int k = 3; k <= n; ++k) {
		// 			fib[k] = fib[k - 1] + fib[k - 2];
		// 		}
		// 		res += fib[n];
		// 	}
		// }
		// cout << res << endl;
		fib[1] = (sum1 * m) % MOD;
		fib[2] = (sum2 * m) % MOD;
		for (int i = 3; i <= n; ++i) {
			fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
		}
		cout << fib[n] % MOD << endl;
	}
	return 0;
}
