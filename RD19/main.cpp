/*input
2
2
2 3
2
2 4
*/

//
//  main.cpp
//  RD19
//
//  Created by Nirmaljot Singh Bhasin on 11/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAXN = 1003;
typedef long long int lli;

lli arr[MAXN], g[MAXN][MAXN];

lli gcd(lli a, lli b) {
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		lli cnt = 0, g = 0;
		for (int  i = 0; i < n; ++i) {
			cin >> arr[i];
			g = gcd(g, arr[i]);
		}
		if (g == 1) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < n; ++i) {
			if (arr[i] % g == 0) {
				++cnt;
			}
		}
		if (cnt == n) {
			cout << -1 << endl;
		} else {
			cout << cnt << endl;
		}
	}
	return 0;
}
