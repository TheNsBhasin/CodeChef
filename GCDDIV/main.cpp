/*input
2
3 6
10 15 30
3 4
5 10 20
*/

//
//  main.cpp
//  GCDDIV
//
//  Created by Nirmaljot Singh Bhasin on 06/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli n, k;
lli arr[MAXN];

lli gcd(lli a, lli b) {
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}

bool solve(lli g) {
	for (int i = 2; i * i <= g && i <= k; ++i) {
		while ((g % i) == 0) {
			g /= i;
		}
	}
	if (g > k) {
		return false;
	}
	return true;
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		lli g = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			g =  gcd(g, arr[i]);
		}
		if (solve(g)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
