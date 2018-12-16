/*input
5 3
20 11 18 2 13
1 3
3 5
2 4
*/

//
//  main.cpp
//  XXOR
//
//  Created by Nirmaljot Singh Bhasin on 02/03/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;
const int BITS = 31;

lli arr[MAXN];
lli dp[MAXN][BITS];

int main(int argc, const char * argv[]) {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		for (int j = BITS - 1; j >= 0; --j) {
			dp[i][j] = dp[i - 1][j] + ((arr[i] >> j) & 1);
		}
	}
	for (int i = 0; i < q; ++i) {
		lli L, R;
		int ans = 0;
		cin >> L >> R;
		for (int j = BITS - 1; j >= 0; --j) {
			lli oc = dp[R][j] - dp[L - 1][j];
			lli zc = (R - L + 1) - oc;
			ans |= (zc > oc) << j;
		}
		cout << ans << endl;
	}
	return 0;
}
